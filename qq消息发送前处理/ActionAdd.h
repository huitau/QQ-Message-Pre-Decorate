#pragma once

#include "Action.h"

namespace DecorateMessage
{

class CActionAdd :
	public CAction
{
public:
	CActionAdd();
	CActionAdd(const CString &strAdd);
	~CActionAdd(void);

	// str�������ַ���
	// ����ֵ��ʾ��һ��δ�޸��ַ���ƫ��ֵ, 
	// ������ʧ��, ����UINT(-1)
	virtual UINT Action(CString &str, UINT uiIndex, const POINT &pt);

	DECLARE_SERIAL(CActionAdd)

	void Serialize(CArchive& ar);

private:
	CString m_strAdd;
	UINT m_uiAddLen;
};





}// namespace DecorateMessage