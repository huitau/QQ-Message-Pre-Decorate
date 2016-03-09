#include "StdAfx.h"
#include "ConditionKeyWord.h"

using namespace DecorateMessage;

IMPLEMENT_SERIAL(CConditionKeyWord, CCondition, 0x1)

CConditionKeyWord::CConditionKeyWord()
{
}

CConditionKeyWord::CConditionKeyWord(LPCTSTR strKey)
: m_strKey(strKey)
{
}

CConditionKeyWord::~CConditionKeyWord(void)
{
}


// ������������ʱ�ַ�����ʼ����ֹλ��, ���POINT ��xy��Ϊ0, �򲻳���
/*virtual*/ POINT CConditionKeyWord::Check(LPCTSTR str)
{
	POINT pt = { 0 };

	// �ҹؼ���
	LPCTSTR strT = wcsstr(str, m_strKey.GetString());
	if (strT == 0)
		return pt;// �Ҳ���, ����ʧ��

	pt.x = strT - str;
	pt.y = pt.x + lstrlen(m_strKey.GetString());

	return pt;
}

void CConditionKeyWord::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << m_strKey;
	}
	else
	{
		ar >> m_strKey;
	}

	CCondition::Serialize(ar);
}