#pragma once
#include "afxwin.h"

#include "Decorate.h"
// CDlgMessageDecorateSetting �Ի���

class CDlgMessageDecorateSetting : public CDialog
{
	DECLARE_DYNAMIC(CDlgMessageDecorateSetting)

public:
	CDlgMessageDecorateSetting(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgMessageDecorateSetting();

// �Ի�������
	enum { IDD = IDD_DIALOG_MESSAGE_DECORATE_SETTING };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);

public:

	// ���ڱ���
	LPCTSTR m_strTitle;

	// ������ʾ�ؼ�
	CToolTipCtrl m_ToolTipCtrl;

	// �ַ����ε�����
	DecorateMessage::CDecorateContent m_DecorateContent;

	// ��������
	CEdit m_EditConditionKeyword;
//	CString m_strConditionKeyword;


	// λ������
	CEdit m_EditPositionOffset;
//	int m_iPositionOffset;


	// ��������
	CEdit m_EditActionAdd;
//	CString m_strActionAdd;

	CEdit m_EditActionDelete;
//	CString m_strActionDelete;

	CEdit m_EditActionReplaceRange;
//	int m_iActionReplaceRange;

	CEdit m_EditActionReplace;
//	CString m_strActionReplace;
	




	// ��ť״̬
//	int m_iRadioCondition;
//	int m_iRadioPosition;
//	int m_iRadioAction;


	// ����Edit��֪ͨ, ��������Radio״̬��
	afx_msg void OnEnSetfocusEditConditionKeyword();
	afx_msg void OnEnSetfocusEditActionAdd();
	afx_msg void OnEnSetfocusEditActionDelete();
	afx_msg void OnEnSetfocusEditActionReplaceRange();
	afx_msg void OnEnSetfocusEditActionReplace();

};


