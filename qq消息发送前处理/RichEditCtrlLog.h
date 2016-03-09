#pragma once


// CRichEditCtrlLog

class CRichEditCtrlLog : public CRichEditCtrl
{
	DECLARE_DYNAMIC(CRichEditCtrlLog)

public:
	CRichEditCtrlLog();
	virtual ~CRichEditCtrlLog();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnClose();
};


