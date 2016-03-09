#include "StdAfx.h"
#include "ConditionWholeMessage.h"

using namespace DecorateMessage;

IMPLEMENT_SERIAL(CConditionWholeMessage, CCondition, 0x1)

CConditionWholeMessage::CConditionWholeMessage(void)
{
}

CConditionWholeMessage::~CConditionWholeMessage(void)
{
}


// 返回条件成立时字符的起始和终止位置, 如果POINT 的xy都为0, 则不成立
/*virtual*/ POINT CConditionWholeMessage::Check(LPCTSTR str)
{
	// 条件是全部字, 那么就选中全部的字就好了
	POINT pt = { 0 };
	pt.x = 0;
	pt.y = lstrlen(str);
	return pt;
}

void CConditionWholeMessage::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
	}
	else
	{
	}

	CCondition::Serialize(ar);
}