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

	// str是整个字符串
	// 返回值表示下一个未修改字符的偏移值, 
	// 若函数失败, 返回UINT(-1)
	virtual UINT Action(CString &str, UINT uiIndex, const POINT &pt);

	DECLARE_SERIAL(CActionReplace)

	void Serialize(CArchive& ar);

private:
	int m_iRange;
	CString m_strReplace;
	UINT m_uiReplaceLen;
};





}// namespace DecorateMessage