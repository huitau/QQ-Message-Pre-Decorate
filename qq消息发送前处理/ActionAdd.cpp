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



// str�������ַ���
// ����ֵ��ʾ��һ��δ�޸��ַ���ƫ��ֵ, 
// ������ʧ��, ����UINT(-1)
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