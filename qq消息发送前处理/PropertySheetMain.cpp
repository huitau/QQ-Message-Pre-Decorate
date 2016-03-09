// PropertySheetMain.cpp : 实现文件
//

#include "stdafx.h"
#include "qq消息发送前处理.h"
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
	// log 标签放第一个, 因为其他标签会调用gTrace, 此时要保证log页内窗口已创建完, 不然IsWindow报错
	AddPage(&m_PropRuningLog);
	AddPage(&m_PropBaseSetting);
	AddPage(&m_PropDecorateSetting);
}

CPropertySheetMain::~CPropertySheetMain()
{
}


BEGIN_MESSAGE_MAP(CPropertySheetMain, CPropertySheet)

END_MESSAGE_MAP()


// CPropertySheetMain 消息处理程序
BOOL CPropertySheetMain::OnInitDialog()
{
	BOOL bResult = CPropertySheet::OnInitDialog();

	// TODO:  在此添加您的专用代码
	SetActivePage(1);
	SetActivePage(2);
	SetActivePage(0);
	return bResult;
}

void CPropertySheetMain::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	m_PropBaseSetting.OnClose();
	m_PropRuningLog.OnClose();
	m_PropDecorateSetting.OnClose();

	CPropertySheet::OnClose();
}
