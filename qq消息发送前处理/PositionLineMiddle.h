#pragma once

#include "Position.h"

namespace DecorateMessage
{

class CPositionLineMiddle :
	public CPosition
{
public:
	CPositionLineMiddle(void);
	CPositionLineMiddle(int iOffset);
	~CPositionLineMiddle(void);

	// str������ȫ���ַ���,
	// pt��strΪ��ʼֵ
	// ����ֵ��strΪ��ʼֵ, ����������, ����UINT(-1)
	virtual UINT GetPosition(LPCTSTR str, POINT &pt);

	void Serialize(CArchive& ar);


	DECLARE_SERIAL(CPositionLineMiddle)
};








}// namespace DecorateMessage