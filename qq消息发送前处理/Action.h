#pragma once
#include "afx.h"

namespace DecorateMessage
{

class CAction :
	public CObject
{
public:
	CAction(void);
	virtual ~CAction(void);

	// str�������ַ���
	// ptֻ����������ֵ, ȷ������ֵ����һ��δ�޸ĵ��ַ�
	// ����ֵ��ʾ��һ��δ�޸��ַ���ƫ��ֵ, 
	// ������ʧ��, ����UINT(-1)
	virtual UINT Action(CString &str, UINT uiIndex, const POINT &pt);

	DECLARE_SERIAL(CAction)

	void Serialize(CArchive& ar);


};





}// namespace DecorateMessage