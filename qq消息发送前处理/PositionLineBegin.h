#pragma once

#include "Position.h"

namespace DecorateMessage
{

class CPositionLineBegin :
	public CPosition
{
public:
	CPositionLineBegin(void);
	CPositionLineBegin(int iOffset);
	~CPositionLineBegin(void);

	// str������ȫ���ַ���,
	// pt��strΪ��ʼֵ
	// ����ֵ��strΪ��ʼֵ, ����������, ����UINT(-1)
	virtual UINT GetPosition(LPCTSTR str, POINT &pt);

	void Serialize(CArchive& ar);



	DECLARE_SERIAL(CPositionLineBegin)
};








}// namespace DecorateMessage