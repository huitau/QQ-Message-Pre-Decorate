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



// str�������ַ���
// ����ֵ��ʾ��һ��δ�޸��ַ���ƫ��ֵ, 
// ������ʧ��, ����UINT(-1)
/*virtual*/ UINT CActionReplace::Action(CString &str, UINT uiIndex, const POINT &pt)
{
	if (m_iRange < 0)// �����滻
	{
		str.Delete(uiIndex + m_iRange, -m_iRange);
		str.Insert(uiIndex + m_iRange, m_strReplace.GetString());
		return uiIndex + m_iRange + m_uiReplaceLen;
	}
	else// �����滻
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