#pragma once
#include "richeditctrllog.h"

// CPropertyPageRuningLog �Ի���

class CPropertyPageRuningLog : public CPropertyPage
{
	DECLARE_DYNAMIC(CPropertyPageRuningLog)

public:
	CPropertyPageRuningLog();
	virtual ~CPropertyPageRuningLog();

// �Ի�������
	enum { IDD = IDD_PROPPAGE_RUNING_LOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CRichEditCtrlLog m_RichEditLog;
	afx_msg void OnClose();
};









extern CRichEditCtrlLog *g_pRichEditTraceTarget;
void gTrace(LPCTSTR s, ...);