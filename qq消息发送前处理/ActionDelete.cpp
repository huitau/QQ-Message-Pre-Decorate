#include "StdAfx.h"
#include "ActionDelete.h"

using namespace DecorateMessage;

IMPLEMENT_SERIAL(CActionDelete, CAction, 0x1)

CActionDelete::CActionDelete()
: m_iRange(0)
{
}

CActionDelete::CActionDelete(int iRange)
: m_iRange(iRange)
{
}

CActionDelete::~CActionDelete(void)
{
}



// str�������ַ���
// ����ֵ��ʾ��һ��δ�޸��ַ���ƫ��ֵ, 
// ������ʧ��, ����UINT(-1)
/*virtual*/ UINT CActionDelete::Action(CString &str, UINT uiIndex, const POINT &pt)
{
	if (m_iRange < 0)// ����ɾ��
	{
		str.Delete(uiIndex + m_iRange, -m_iRange);
		return uiIndex + m_iRange;
	}
	else// ����ɾ
	{
		str.Delete(uiIndex, m_iRange);
		return uiIndex;
	}

}

void CActionDelete::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << m_iRange;
	}
	else
	{
		ar >> m_iRange;
	}

	CAction::Serialize(ar);
}