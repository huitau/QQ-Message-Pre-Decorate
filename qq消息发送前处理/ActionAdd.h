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

	// str是整个字符串
	// 返回值表示下一个未修改字符的偏移值, 
	// 若函数失败, 返回UINT(-1)
	virtual UINT Action(CString &str, UINT uiIndex, const POINT &pt);

	DECLARE_SERIAL(CActionAdd)

	void Serialize(CArchive& ar);

private:
	CString m_strAdd;
	UINT m_uiAddLen;
};





}// namespace DecorateMessage