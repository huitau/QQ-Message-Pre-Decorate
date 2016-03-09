// PropertySheetMain.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "qq��Ϣ����ǰ����.h"
#include "PropertySheetMain.h"


// CPropertySheetMain

IMPLEMENT_DYNAMIC(CPropertySheetMain, CPropertySheet)

CPropertySheetMain::CPropertySheetMain(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{

}

CPropertySheetMain::CPropertySheetMain(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
	// log ��ǩ�ŵ�һ��, ��Ϊ������ǩ�����gTrace, ��ʱҪ��֤logҳ�ڴ����Ѵ�����, ��ȻIsWindow����
	AddPage(&m_PropRuningLog);
	AddPage(&m_PropBaseSetting);
	AddPage(&m_PropDecorateSetting);
}

CPropertySheetMain::~CPropertySheetMain()
{
}


BEGIN_MESSAGE_MAP(CPropertySheetMain, CPropertySheet)

END_MESSAGE_MAP()


// CPropertySheetMain ��Ϣ�������
BOOL CPropertySheetMain::OnInitDialog()
{
	BOOL bResult = CPropertySheet::OnInitDialog();

	// TODO:  �ڴ��������ר�ô���
	SetActivePage(1);
	SetActivePage(2);
	SetActivePage(0);
	return bResult;
}

void CPropertySheetMain::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	m_PropBaseSetting.OnClose();
	m_PropRuningLog.OnClose();
	m_PropDecorateSetting.OnClose();

	CPropertySheet::OnClose();
}
