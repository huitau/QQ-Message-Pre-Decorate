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

	// str������ȫ���ַ���,
	// pt��strΪ��ʼֵ
	// ����ֵ��strΪ��ʼֵ, ����������, ����UINT(-1)
	virtual UINT GetPosition(LPCTSTR str, POINT &pt);

	void Serialize(CArchive& ar);

	DECLARE_SERIAL(CPosition)


protected:
	int m_iOffset;// �û��ṩ��ƫ����
};






}// namespace DecorateMessage