#pragma once
#include "afx.h"

namespace DecorateMessage
{

class CCondition :
	public CObject
{
public:
	CCondition(void);
	virtual ~CCondition(void);

	// 返回条件成立时字符的起始和终止位置, 如果POINT 的xy都为0, 则不成立
	//  终止位置是终止字符的下标+1, 这个位置指向字符的下一个位置
	virtual POINT Check(LPCTSTR str);

	void Serialize(CArchive& ar);

	DECLARE_SERIAL(CCondition);

};






}// namespace DecorateMessage