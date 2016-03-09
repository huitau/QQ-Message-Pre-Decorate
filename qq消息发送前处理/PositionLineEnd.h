#pragma once


#include "Position.h"

namespace DecorateMessage
{

class CPositionLineEnd :
	public CPosition
{
public:
	CPositionLineEnd(void);
	CPositionLineEnd(int iOffset);
	~CPositionLineEnd(void);

	// str保存了全部字符串,
	// pt以str为起始值
	// 返回值以str为起始值, 若函数出错, 返回UINT(-1)
	virtual UINT GetPosition(LPCTSTR str, POINT &pt);

	void Serialize(CArchive& ar);

	DECLARE_SERIAL(CPositionLineEnd)
};








}// namespace DecorateMessage