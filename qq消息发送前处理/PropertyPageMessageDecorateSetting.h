#pragma once
#include "afxcmn.h"

#include "Decorate.h"

// CPropertyPageMessageDecorateSetting �Ի���

#include "ListCtrlMessageDecorate.h"
#include "afxwin.h"

class CPropertyPageMessageDecorateSetting : public CPropertyPage
{
	DECLARE_DYNAMIC(CPropertyPageMessageDecorateSetting)

public:
	CPropertyPageMessageDecorateSetting();
	virtual ~CPropertyPageMessageDecorateSetting();

// �Ի�������
	enum { IDD = IDD_PROPPAGE_MESSAGE_DECORATE_SETTING };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

	virtual BOOL OnInitDialog();


public:
	// �ӹ�����
	void DecorateString(CString &str);

	// �б��
	CListCtrlMessageDecorate m_ListCtrlDecorateMessage;


	// Decorate����, �����ڶ������ʱ, ���ֵ�һ�ε�����, �ȽϷ����
	DecorateMessage::CDecorateContent m_DecorateContent;

	

	// ������ť��Ӧ����
	afx_msg void OnBnClickedButtonAdd();
	afx_msg void OnBnClickedButtonChange();
	afx_msg void OnBnClickedButtonDelete();


	CButton m_ButtonAdd;
	CButton m_ButtonChange;
	CButton m_ButtonDelete;
	CButton m_ButtonUp;
	CButton m_ButtonDown;

	// ��Ӧ��갴��, �����ü�����ť��״̬
	afx_msg void OnNMClickListDecorateMessage(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButtonUp();
	afx_msg void OnBnClickedButtonDown();
	afx_msg void OnClose();
};
