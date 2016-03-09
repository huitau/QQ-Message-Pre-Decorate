#include "StdAfx.h"
#include "ConditionEachLine.h"

using namespace DecorateMessage;

IMPLEMENT_SERIAL(CConditionEachLine, CCondition, 0x1)

CConditionEachLine::CConditionEachLine(void)
{
}

CConditionEachLine::~CConditionEachLine(void)
{
}


// 返回条件成立时字符的起始和终止位置, 如果POINT 的xy都为0, 则不成立
/*virtual*/ POINT CConditionEachLine::Check(LPCTSTR str)
{
	POINT pt = { 0 };

	pt.x = 0;
	// 找换行符
	LPCTSTR strT = wcschr(str, _T('\r'));
	if (strT == 0)// 找不到换行符, 可能是最后一行
	{
		pt.y = lstrlen(str);
		if (pt.y)// 有长度, 那么是最后一行
		{
			// 此时x是0, y是长度
		}
		else// 没长度, 看来传进来一个"\0"字符串了, 直接返回无效
		{
			// 此时xy都是0, 代表无效
		}
	}
	else
	{
		pt.y = strT - str;
	}

	return pt;
}

void CConditionEachLine::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
	}
	else
	{
	}

	CCondition::Serialize(ar);
}