// RichEditCtrlLog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "qq��Ϣ����ǰ����.h"
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



// CRichEditCtrlLog ��Ϣ�������



void CRichEditCtrlLog::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	

	CRichEditCtrl::OnLButtonDown(nFlags, point);
}

void CRichEditCtrlLog::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	SetWindowText(_T(""));
	gTrace(_T("�����¼.\r\n"));
	CRichEditCtrl::OnLButtonDblClk(nFlags, point);
}

void CRichEditCtrlLog::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CRichEditCtrl::OnClose();
}
