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

	// str������ȫ���ַ���,
	// ��Offsetָ�����������ַ�
	// pt��strΪ��ʼֵ
	// ����ֵ��strΪ��ʼֵ, ����������, ����UINT(-1)
	virtual UINT GetPosition(LPCTSTR str, POINT &pt);

	void Serialize(CArchive& ar);

	DECLARE_SERIAL(CPositionBegin)
};






}// namespace DecorateMessage
