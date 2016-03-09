// PropertyPageRuningLog.cpp : 实现文件
//

#include "stdafx.h"
#include "qq消息发送前处理.h"
#include "PropertyPageRuningLog.h"


// CPropertyPageRuningLog 对话框

IMPLEMENT_DYNAMIC(CPropertyPageRuningLog, CPropertyPage)

CPropertyPageRuningLog::CPropertyPageRuningLog()
	: CPropertyPage(CPropertyPageRuningLog::IDD)
{
	g_pRichEditTraceTarget = &m_RichEditLog;
}

CPropertyPageRuningLog::~CPropertyPageRuningLog()
{
}

void CPropertyPageRuningLog::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RICHEDIT_LOG, m_RichEditLog);
}


BEGIN_MESSAGE_MAP(CPropertyPageRuningLog, CPropertyPage)

END_MESSAGE_MAP()


// CPropertyPageRuningLog 消息处理程序

CRichEditCtrlLog *g_pRichEditTraceTarget;

void gTrace(LPCTSTR s, ...)
{
	// 处理字符
	CTime time = CTime::GetCurrentTime();
	CString strTime = time.Format(_T("%H:%M:%S "));
	va_list args;
	va_start(args, s);
	CString strV;
	strV.FormatV(s, args);
	CString str = strTime + strV;
	va_end(args);

	// 移动插入符
	g_pRichEditTraceTarget->SendMessage(EM_SETSEL, -1, -1);

	// 输出文字
	SETTEXTEX ste;
	ste.flags = ST_SELECTION;
	ste.codepage = 1200;
	g_pRichEditTraceTarget->SendMessage(EM_SETTEXTEX, (WPARAM)&ste, (LPARAM)str.GetString());

	// 移动滚动条
	g_pRichEditTraceTarget->SendMessage(WM_VSCROLL, SB_BOTTOM);
}
void CPropertyPageRuningLog::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CPropertyPage::OnClose();
}
