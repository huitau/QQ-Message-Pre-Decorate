// PropertyPageRuningLog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "qq��Ϣ����ǰ����.h"
#include "PropertyPageRuningLog.h"


// CPropertyPageRuningLog �Ի���

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


// CPropertyPageRuningLog ��Ϣ�������

CRichEditCtrlLog *g_pRichEditTraceTarget;

void gTrace(LPCTSTR s, ...)
{
	// �����ַ�
	CTime time = CTime::GetCurrentTime();
	CString strTime = time.Format(_T("%H:%M:%S "));
	va_list args;
	va_start(args, s);
	CString strV;
	strV.FormatV(s, args);
	CString str = strTime + strV;
	va_end(args);

	// �ƶ������
	g_pRichEditTraceTarget->SendMessage(EM_SETSEL, -1, -1);

	// �������
	SETTEXTEX ste;
	ste.flags = ST_SELECTION;
	ste.codepage = 1200;
	g_pRichEditTraceTarget->SendMessage(EM_SETTEXTEX, (WPARAM)&ste, (LPARAM)str.GetString());

	// �ƶ�������
	g_pRichEditTraceTarget->SendMessage(WM_VSCROLL, SB_BOTTOM);
}
void CPropertyPageRuningLog::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CPropertyPage::OnClose();
}
