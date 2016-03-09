#include "StdAfx.h"
#include "ActionAdd.h"

using namespace DecorateMessage;

IMPLEMENT_SERIAL(CActionAdd, CAction, 0x1)

CActionAdd::CActionAdd()
: m_uiAddLen(0)
{
}

CActionAdd::CActionAdd(const CString &strAdd)
: m_strAdd(strAdd)
{
	m_uiAddLen = (UINT)m_strAdd.GetLength();
}

CActionAdd::~CActionAdd(void)
{
}



// str是整个字符串
// 返回值表示下一个未修改字符的偏移值, 
// 若函数失败, 返回UINT(-1)
/*virtual*/ UINT CActionAdd::Action(CString &str, UINT uiIndex, const POINT &pt)
{
	str.Insert(uiIndex, m_strAdd.GetString());

	return pt.y + m_uiAddLen;
}

void CActionAdd::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << m_uiAddLen;
		ar << m_strAdd;
	}
	else
	{
		ar >> m_uiAddLen;
		ar >> m_strAdd;
	}

	CAction::Serialize(ar);
}