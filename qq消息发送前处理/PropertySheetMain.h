#pragma once

#include "PropretyPageBaseSetting.h"
#include "PropertyPageRuningLog.h"
#include "PropertyPageMessageDecorateSetting.h"


// CPropertySheetMain

class CPropertySheetMain : public CPropertySheet
{
	DECLARE_DYNAMIC(CPropertySheetMain)

public:
	CPropertySheetMain(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CPropertySheetMain(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	virtual ~CPropertySheetMain();

protected:
	DECLARE_MESSAGE_MAP()


public:
	CPropretyPageBaseSetting m_PropBaseSetting;
	CPropertyPageRuningLog m_PropRuningLog;
	CPropertyPageMessageDecorateSetting m_PropDecorateSetting;

	virtual BOOL OnInitDialog();
	afx_msg void OnClose();
};


