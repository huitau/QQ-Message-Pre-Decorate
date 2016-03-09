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

	// str是整个字符串
	// 返回值表示下一个未修改字符的偏移值, 
	// 若函数失败, 返回UINT(-1)
	virtual UINT Action(CString &str, UINT uiIndex, const POINT &pt);

	DECLARE_SERIAL(CActionDelete)

	void Serialize(CArchive& ar);

private:
	int m_iRange;
};





}// namespace DecorateMessage