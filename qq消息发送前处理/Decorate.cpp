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

// 为指针赋值
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
		// 查找有无目标
		POINT pt = m_pCondition->Check(str.GetString() + uiOffset);
		if (pt.x == 0 && pt.y == 0)
			break;

		// 转换pt由部分str到全部str
		pt.x += uiOffset;
		pt.y += uiOffset;
		// 调整位置
		UINT uiPos = m_pPosition->GetPosition(str.GetString(), pt);
		// 判断函数是否出错
		if (uiPos == UINT(-1))
		{
			// 出错了, 那么跳过当前的目标, 修改offset, 进行新的字符处理
			uiOffset = pt.y;
			continue;
		}

		UINT uiRtn = m_pAction->Action(str, uiPos, pt);
		if (uiRtn == UINT(-1))
		{
			// 出错了, 那么跳过当前的目标, 修改offset, 进行新的字符处理
			uiOffset = pt.y;
			continue;
		}


		uiOffset = uiRtn;

		// 如果是换行的位置, pt = m_pCondition->Check   pt不包含\r\n, 需要这里自己uiOffset += 2
		if (m_pCondition->IsKindOf(RUNTIME_CLASS(CConditionEachLine)))
		{
			// 可能是结尾, 看看有没有换行符;   有 那么跳
			if (*(str.GetString() + uiRtn) == '\r')
				uiOffset += 2;
		}
		else if (m_pPosition->IsKindOf(RUNTIME_CLASS(CPositionLineBegin)))
		{
			// 可能是结尾, 看看有没有换行符;   有 那么跳
			if (*(str.GetString() + uiRtn) == '\r')
				uiOffset += 2;
		}
		else if (m_pPosition->IsKindOf(RUNTIME_CLASS(CPositionLineMiddle)))
		{
			// 可能是结尾, 看看有没有换行符;   有 那么跳
			if (*(str.GetString() + uiRtn) == '\r')
				uiOffset += 2;
		}
		else if (m_pPosition->IsKindOf(RUNTIME_CLASS(CPositionLineEnd)))
		{
			// 可能是结尾, 看看有没有换行符;   有 那么跳
			if (*(str.GetString() + uiRtn) == '\r')
				uiOffset += 2;
		}
		
		++uiCount;
	}

	return uiCount;
}
