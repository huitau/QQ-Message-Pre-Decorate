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

	// str������ȫ���ַ���,
	// pt��strΪ��ʼֵ
	// ����ֵ��strΪ��ʼֵ, ����������, ����UINT(-1)
	virtual UINT GetPosition(LPCTSTR str, POINT &pt);

	void Serialize(CArchive& ar);

	DECLARE_SERIAL(CPositionLineEnd)
};








}// namespace DecorateMessage