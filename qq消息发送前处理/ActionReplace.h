#pragma once

#include "Action.h"

namespace DecorateMessage
{

class CActionReplace :
	public CAction
{
public:
	CActionReplace();
	CActionReplace(int iRange, const CString &strReplace);
	~CActionReplace(void);

	// str�������ַ���
	// ����ֵ��ʾ��һ��δ�޸��ַ���ƫ��ֵ, 
	// ������ʧ��, ����UINT(-1)
	virtual UINT Action(CString &str, UINT uiIndex, const POINT &pt);

	DECLARE_SERIAL(CActionReplace)

	void Serialize(CArchive& ar);

private:
	int m_iRange;
	CString m_strReplace;
	UINT m_uiReplaceLen;
};





}// namespace DecorateMessage