#pragma once

#include "Condition.h"

namespace DecorateMessage
{

class CConditionWholeMessage :
	public CCondition
{
public:
	CConditionWholeMessage(void);
	~CConditionWholeMessage(void);

	// 返回条件成立时字符的起始和终止位置, 如果POINT 的xy都为0, 则不成立
	virtual POINT Check(LPCTSTR str);

	void Serialize(CArchive& ar);

	DECLARE_SERIAL(CConditionWholeMessage);
};








}// namespace DecorateMessage