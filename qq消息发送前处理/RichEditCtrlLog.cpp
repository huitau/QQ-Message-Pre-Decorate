// RichEditCtrlLog.cpp : 实现文件
//

#include "stdafx.h"
#include "qq消息发送前处理.h"
#include "RichEditCtrlLog.h"
#include "MyDlg.h"

// CRichEditCtrlLog

IMPLEMENT_DYNAMIC(CRichEditCtrlLog, CRichEditCtrl)

CRichEditCtrlLog::CRichEditCtrlLog()
{

}

CRichEditCtrlLog::~CRichEditCtrlLog()
{
}


BEGIN_MESSAGE_MAP(CRichEditCtrlLog, CRichEditCtrl)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()



// CRichEditCtrlLog 消息处理程序



void CRichEditCtrlLog::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	

	CRichEditCtrl::OnLButtonDown(nFlags, point);
}

void CRichEditCtrlLog::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	SetWindowText(_T(""));
	gTrace(_T("清除记录.\r\n"));
	CRichEditCtrl::OnLButtonDblClk(nFlags, point);
}

void CRichEditCtrlLog::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CRichEditCtrl::OnClose();
}
