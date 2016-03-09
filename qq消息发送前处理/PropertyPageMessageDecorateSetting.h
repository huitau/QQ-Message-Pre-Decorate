#pragma once
#include "afxcmn.h"

#include "Decorate.h"

// CPropertyPageMessageDecorateSetting 对话框

#include "ListCtrlMessageDecorate.h"
#include "afxwin.h"

class CPropertyPageMessageDecorateSetting : public CPropertyPage
{
	DECLARE_DYNAMIC(CPropertyPageMessageDecorateSetting)

public:
	CPropertyPageMessageDecorateSetting();
	virtual ~CPropertyPageMessageDecorateSetting();

// 对话框数据
	enum { IDD = IDD_PROPPAGE_MESSAGE_DECORATE_SETTING };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

	virtual BOOL OnInitDialog();


public:
	// 加工文字
	void DecorateString(CString &str);

	// 列表框
	CListCtrlMessageDecorate m_ListCtrlDecorateMessage;


	// Decorate副本, 用来第二次添加时, 保持第一次的内容, 比较方便点
	DecorateMessage::CDecorateContent m_DecorateContent;

	

	// 几个按钮响应函数
	afx_msg void OnBnClickedButtonAdd();
	afx_msg void OnBnClickedButtonChange();
	afx_msg void OnBnClickedButtonDelete();


	CButton m_ButtonAdd;
	CButton m_ButtonChange;
	CButton m_ButtonDelete;
	CButton m_ButtonUp;
	CButton m_ButtonDown;

	// 响应鼠标按下, 来设置几个按钮的状态
	afx_msg void OnNMClickListDecorateMessage(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButtonUp();
	afx_msg void OnBnClickedButtonDown();
	afx_msg void OnClose();
};
