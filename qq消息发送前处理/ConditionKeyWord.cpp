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


// 返回条件成立时字符的起始和终止位置, 如果POINT 的xy都为0, 则不成立
/*virtual*/ POINT CConditionKeyWord::Check(LPCTSTR str)
{
	POINT pt = { 0 };

	// 找关键字
	LPCTSTR strT = wcsstr(str, m_strKey.GetString());
	if (strT == 0)
		return pt;// 找不到, 返回失败

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