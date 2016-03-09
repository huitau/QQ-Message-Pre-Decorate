#pragma once

#include "Position.h"

namespace DecorateMessage
{

class CPositionBegin :
	public CPosition
{
public:
	CPositionBegin();
	CPositionBegin(int iOffset);
	~CPositionBegin(void);

	// str保存了全部字符串,
	// 由Offset指定跳过多少字符
	// pt以str为起始值
	// 返回值以str为起始值, 若函数出错, 返回UINT(-1)
	virtual UINT GetPosition(LPCTSTR str, POINT &pt);

	void Serialize(CArchive& ar);

	DECLARE_SERIAL(CPositionBegin)
};






}// namespace DecorateMessage
