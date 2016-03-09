#include "StdAfx.h"
#include "ActionReplace.h"

using namespace DecorateMessage;

IMPLEMENT_SERIAL(CActionReplace, CAction, 0x1)

CActionReplace::CActionReplace()
: m_iRange(0)
, m_uiReplaceLen(0)
{
}

CActionReplace::CActionReplace(int iRange, const CString &strReplace)
: m_iRange(iRange)
, m_strReplace(strReplace)
{
	m_uiReplaceLen = m_strReplace.GetLength();
}

CActionReplace::~CActionReplace(void)
{
}



// str是整个字符串
// 返回值表示下一个未修改字符的偏移值, 
// 若函数失败, 返回UINT(-1)
/*virtual*/ UINT CActionReplace::Action(CString &str, UINT uiIndex, const POINT &pt)
{
	if (m_iRange < 0)// 向左替换
	{
		str.Delete(uiIndex + m_iRange, -m_iRange);
		str.Insert(uiIndex + m_iRange, m_strReplace.GetString());
		return uiIndex + m_iRange + m_uiReplaceLen;
	}
	else// 向右替换
	{
		str.Delete(uiIndex, m_iRange);
		str.Insert(uiIndex, m_strReplace.GetString());
		return uiIndex + m_uiReplaceLen;
	}

}

void CActionReplace::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << m_iRange;
		ar << m_uiReplaceLen;
		ar << m_strReplace;
	}
	else
	{
		ar >> m_iRange;
		ar >> m_uiReplaceLen;
		ar >> m_strReplace;
	}

	CAction::Serialize(ar);
}