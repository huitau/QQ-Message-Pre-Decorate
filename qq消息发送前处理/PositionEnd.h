#pragma once

#include "Position.h"

namespace DecorateMessage
{

class CPositionEnd :
	public CPosition
{
public:
	CPositionEnd();
	CPositionEnd(int iOffset);
	~CPositionEnd(void);

	// str������ȫ���ַ���,
	// ��Offsetָ�����������ַ�
	// pt��strΪ��ʼֵ
	// ����ֵ��strΪ��ʼֵ, ����������, ����UINT(-1)
	virtual UINT GetPosition(LPCTSTR str, POINT &pt);

	void Serialize(CArchive& ar);

	DECLARE_SERIAL(CPositionEnd)
};






}// namespace DecorateMessage
