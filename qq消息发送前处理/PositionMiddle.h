#pragma once

#include "Position.h"

namespace DecorateMessage
{

class CPositionMiddle :
	public CPosition
{
public:
	CPositionMiddle();
	CPositionMiddle(int iOffset);
	~CPositionMiddle(void);

	// str������ȫ���ַ���,
	// ��Offsetָ�����������ַ�
	// pt��strΪ��ʼֵ
	// ����ֵ��strΪ��ʼֵ, ����������, ����UINT(-1)
	virtual UINT GetPosition(LPCTSTR str, POINT &pt);

	void Serialize(CArchive& ar);

	DECLARE_SERIAL(CPositionMiddle)
};






}// namespace DecorateMessage