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

	// str是整个字符串
	// pt只用来处理返回值, 确保返回值是下一个未修改的字符
	// 返回值表示下一个未修改字符的偏移值, 
	// 若函数失败, 返回UINT(-1)
	virtual UINT Action(CString &str, UINT uiIndex, const POINT &pt);

	DECLARE_SERIAL(CAction)

	void Serialize(CArchive& ar);


};





}// namespace DecorateMessage