#include "StdAfx.h"
#include "Decorate.h"

using namespace DecorateMessage;

CDecorateContent::CDecorateContent()
: iConditionType(0)
, iPositionType(0)
, iPositionOffset(0)
, iActionType(0)
, iDeleteRange(0)
, iReplaceRange(0)
{
}

void CDecorateContent::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << iConditionType;
		ar << strKeyword;

		ar << iPositionType;
		ar << iPositionOffset;

		ar << iActionType;
		ar << strAdd;
		ar << strReplace;
		ar << iDeleteRange;
		ar << iReplaceRange;
	}
	else
	{
		ar >> iConditionType;
		ar >> strKeyword;

		ar >> iPositionType;
		ar >> iPositionOffset;

		ar >> iActionType;
		ar >> strAdd;
		ar >> strReplace;
		ar >> iDeleteRange;
		ar >> iReplaceRange;
	}
}

CArchive &DecorateMessage::operator << (CArchive &ar, CDecorateContent &de)
{
	de.Serialize(ar);
	return ar;
}

CArchive &DecorateMessage::operator >> (CArchive &ar, CDecorateContent &de)
{
	de.Serialize(ar);
	return ar;
}



























CDecorate::CDecorate()
: m_pCondition(NULL)
, m_pPosition(NULL)
, m_pAction(NULL)
{
}

CArchive &DecorateMessage::operator << (CArchive &ar, CDecorate &de)
{
	de.Serialize(ar);
	return ar;
}

CArchive &DecorateMessage::operator >> (CArchive &ar, CDecorate &de)
{
	de.Serialize(ar);
	return ar;
}


void CDecorate::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << m_DecorateContent;
		ar << m_pCondition;
		ar << m_pPosition;
		ar << m_pAction;
	}
	else
	{
		ar >> m_DecorateContent;
		CObject *pOb;
		ar >> pOb;
		m_pCondition = (CCondition *)pOb;
		ar >> pOb;
		m_pPosition = (CPosition *)pOb;
		ar >> pOb;
		m_pAction = (CAction *)pOb;
	}
}


CDecorate::CDecorate(const CDecorateContent &DecorateContent)
: m_DecorateContent(DecorateContent)
{
	Construct(DecorateContent);
}

// Ϊָ�븳ֵ
void CDecorate::Construct(const CDecorateContent &DecorateContent)
{
	switch (DecorateContent.iConditionType)
	{
	case CDecorateContent::CONDITION_WHOLEMESSAGE:
		m_pCondition = new CConditionWholeMessage;
		break;
	case CDecorateContent::CONDITION_EACHLINE:
		m_pCondition = new CConditionEachLine;
		break;
	case CDecorateContent::CONDITION_KEYWORD:
		m_pCondition = new CConditionKeyWord(DecorateContent.strKeyword);
		break;
	}

	switch (DecorateContent.iPositionType)
	{
	case CDecorateContent::POSITION_BEGIN:
		m_pPosition = new CPositionBegin(DecorateContent.iPositionOffset);
		break;
	case CDecorateContent::POSITION_END:
		m_pPosition = new CPositionEnd(DecorateContent.iPositionOffset);
		break;
	case CDecorateContent::POSITION_MIDDLE:
		m_pPosition = new CPositionMiddle(DecorateContent.iPositionOffset);
		break;
	case CDecorateContent::POSITION_LINE_BEGIN:
		m_pPosition = new CPositionLineBegin(DecorateContent.iPositionOffset);
		break;
	case CDecorateContent::POSITION_LINE_END:
		m_pPosition = new CPositionLineEnd(DecorateContent.iPositionOffset);
		break;
	case CDecorateContent::POSITION_LINE_MIDDLE:
		m_pPosition = new CPositionLineMiddle(DecorateContent.iPositionOffset);
		break;
	}

	switch (DecorateContent.iActionType)
	{
	case CDecorateContent::ACTION_ADD:
		m_pAction = new CActionAdd(
			DecorateContent.strAdd);
		break;
	case CDecorateContent::ACTION_DELETE:
		m_pAction = new CActionDelete(
			DecorateContent.iDeleteRange);
		break;
	case CDecorateContent::ACTION_REPLACE:
		m_pAction = new CActionReplace(
			DecorateContent.iReplaceRange, DecorateContent.strReplace);
		break;
	}
}

void CDecorate::ReConstruct(const CDecorateContent &DecorateContent)
{
	delete m_pCondition;
	delete m_pPosition;
	delete m_pAction;

	m_DecorateContent = DecorateContent;

	Construct(DecorateContent);
}

CDecorate::~CDecorate(void)
{
	delete m_pCondition;
	delete m_pPosition;
	delete m_pAction;
}

UINT CDecorate::Decorate(CString &str)
{
	UINT uiOffset = 0;
	UINT uiCount = 0;

	for (;;)
	{
		// ��������Ŀ��
		POINT pt = m_pCondition->Check(str.GetString() + uiOffset);
		if (pt.x == 0 && pt.y == 0)
			break;

		// ת��pt�ɲ���str��ȫ��str
		pt.x += uiOffset;
		pt.y += uiOffset;
		// ����λ��
		UINT uiPos = m_pPosition->GetPosition(str.GetString(), pt);
		// �жϺ����Ƿ����
		if (uiPos == UINT(-1))
		{
			// ������, ��ô������ǰ��Ŀ��, �޸�offset, �����µ��ַ�����
			uiOffset = pt.y;
			continue;
		}

		UINT uiRtn = m_pAction->Action(str, uiPos, pt);
		if (uiRtn == UINT(-1))
		{
			// ������, ��ô������ǰ��Ŀ��, �޸�offset, �����µ��ַ�����
			uiOffset = pt.y;
			continue;
		}


		uiOffset = uiRtn;

		// ����ǻ��е�λ��, pt = m_pCondition->Check   pt������\r\n, ��Ҫ�����Լ�uiOffset += 2
		if (m_pCondition->IsKindOf(RUNTIME_CLASS(CConditionEachLine)))
		{
			// �����ǽ�β, ������û�л��з�;   �� ��ô��
			if (*(str.GetString() + uiRtn) == '\r')
				uiOffset += 2;
		}
		else if (m_pPosition->IsKindOf(RUNTIME_CLASS(CPositionLineBegin)))
		{
			// �����ǽ�β, ������û�л��з�;   �� ��ô��
			if (*(str.GetString() + uiRtn) == '\r')
				uiOffset += 2;
		}
		else if (m_pPosition->IsKindOf(RUNTIME_CLASS(CPositionLineMiddle)))
		{
			// �����ǽ�β, ������û�л��з�;   �� ��ô��
			if (*(str.GetString() + uiRtn) == '\r')
				uiOffset += 2;
		}
		else if (m_pPosition->IsKindOf(RUNTIME_CLASS(CPositionLineEnd)))
		{
			// �����ǽ�β, ������û�л��з�;   �� ��ô��
			if (*(str.GetString() + uiRtn) == '\r')
				uiOffset += 2;
		}
		
		++uiCount;
	}

	return uiCount;
}
