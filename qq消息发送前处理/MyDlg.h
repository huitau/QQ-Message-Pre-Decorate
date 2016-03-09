// MyDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"

#include "RichEditCtrlLog.h"
#include "PropertySheetMain.h"


// CMyDlg 对话框
class CMyDlg : public CDialog
{
// 构造
public:
	CMyDlg(CWnd* pParent = NULL);	// 标准构造函数
	~CMyDlg();

// 对话框数据
	enum { IDD = IDD_QQ_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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

	// hook键确认后, 调用此函数, 转换消息内容
	void TransQQMessage();
	
	// 模拟按键
	UINT KeyboardInput(WORD wVk, WORD wScan = 0, DWORD dwFlags = 0);

	afx_msg void OnTimer(UINT_PTR nIDEvent);

	afx_msg void OnNcLButtonDblClk(UINT nHitTest, CPoint point);
	afx_msg void OnClose();
};











void gTrace(LPCTSTR s, ...);