// MyDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"

#include "RichEditCtrlLog.h"
#include "PropertySheetMain.h"


// CMyDlg �Ի���
class CMyDlg : public CDialog
{
// ����
public:
	CMyDlg(CWnd* pParent = NULL);	// ��׼���캯��
	~CMyDlg();

// �Ի�������
	enum { IDD = IDD_QQ_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()


public:
	afx_msg LRESULT OnKeyboardHookFirst(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnKeyboardHookNext(WPARAM wParam, LPARAM lParam);
	CPropertySheetMain m_PropSheetMain;

	BOOL m_bCtrlPressed;
	BOOL m_bAltPressed;
	BOOL m_bShiftPressed;

	// hook��ȷ�Ϻ�, ���ô˺���, ת����Ϣ����
	void TransQQMessage();
	
	// ģ�ⰴ��
	UINT KeyboardInput(WORD wVk, WORD wScan = 0, DWORD dwFlags = 0);

	afx_msg void OnTimer(UINT_PTR nIDEvent);

	afx_msg void OnNcLButtonDblClk(UINT nHitTest, CPoint point);
	afx_msg void OnClose();
};











void gTrace(LPCTSTR s, ...);