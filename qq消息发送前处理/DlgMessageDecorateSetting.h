#pragma once
#include "afxwin.h"

#include "Decorate.h"
// CDlgMessageDecorateSetting 对话框

class CDlgMessageDecorateSetting : public CDialog
{
	DECLARE_DYNAMIC(CDlgMessageDecorateSetting)

public:
	CDlgMessageDecorateSetting(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgMessageDecorateSetting();

// 对话框数据
	enum { IDD = IDD_DIALOG_MESSAGE_DECORATE_SETTING };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);

public:

	// 窗口标题
	LPCTSTR m_strTitle;

	// 工具提示控件
	CToolTipCtrl m_ToolTipCtrl;

	// 字符修饰的数据
	DecorateMessage::CDecorateContent m_DecorateContent;

	// 条件数据
	CEdit m_EditConditionKeyword;
//	CString m_strConditionKeyword;


	// 位置数据
	CEdit m_EditPositionOffset;
//	int m_iPositionOffset;


	// 动作数据
	CEdit m_EditActionAdd;
//	CString m_strActionAdd;

	CEdit m_EditActionDelete;
//	CString m_strActionDelete;

	CEdit m_EditActionReplaceRange;
//	int m_iActionReplaceRange;

	CEdit m_EditActionReplace;
//	CString m_strActionReplace;
	




	// 按钮状态
//	int m_iRadioCondition;
//	int m_iRadioPosition;
//	int m_iRadioAction;


	// 几个Edit的通知, 用来更改Radio状态的
	afx_msg void OnEnSetfocusEditConditionKeyword();
	afx_msg void OnEnSetfocusEditActionAdd();
	afx_msg void OnEnSetfocusEditActionDelete();
	afx_msg void OnEnSetfocusEditActionReplaceRange();
	afx_msg void OnEnSetfocusEditActionReplace();

};


