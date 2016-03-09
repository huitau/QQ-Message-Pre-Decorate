#pragma once

#include "Action.h"

namespace DecorateMessage
{

class CActionDelete :
	public CAction
{
public:
	CActionDelete();
	CActionDelete(int iRange);
	~CActionDelete(void);

	// str�������ַ���
	// ����ֵ��ʾ��һ��δ�޸��ַ���ƫ��ֵ, 
	// ������ʧ��, ����UINT(-1)
	virtual UINT Action(CString &str, UINT uiIndex, const POINT &pt);

	DECLARE_SERIAL(CActionDelete)

	void Serialize(CArchive& ar);

private:
	int m_iRange;
};





}// namespace DecorateMessage