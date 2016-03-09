#pragma once
#include "afx.h"

namespace DecorateMessage
{

class CPosition :
	public CObject
{
public:
	CPosition();
	CPosition(int iOffset);
	virtual ~CPosition(void);

	// str保存了全部字符串,
	// pt以str为起始值
	// 返回值以str为起始值, 若函数出错, 返回UINT(-1)
	virtual UINT GetPosition(LPCTSTR str, POINT &pt);

	void Serialize(CArchive& ar);

	DECLARE_SERIAL(CPosition)


protected:
	int m_iOffset;// 用户提供的偏移量
};






}// namespace DecorateMessage