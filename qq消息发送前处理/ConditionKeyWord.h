#pragma once

#include "Condition.h"

namespace DecorateMessage
{

class CConditionKeyWord :
	public CCondition
{
public:
	CConditionKeyWord();
	CConditionKeyWord(LPCTSTR strKey);
	~CConditionKeyWord(void);

	// 返回条件成立时字符的起始和终止位置, 如果POINT 的xy都为0, 则不成立
	virtual POINT Check(LPCTSTR str);

	void Serialize(CArchive& ar);

	DECLARE_SERIAL(CConditionKeyWord);

private:
	CString m_strKey;
};











}// namespace DecorateMessage