// DlgMessageDecorateSetting.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "qq��Ϣ����ǰ����.h"
#include "DlgMessageDecorateSetting.h"


// CDlgMessageDecorateSetting �Ի���

using namespace DecorateMessage;

IMPLEMENT_DYNAMIC(CDlgMessageDecorateSetting, CDialog)

CDlgMessageDecorateSetting::CDlgMessageDecorateSetting(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgMessageDecorateSetting::IDD, pParent)
	, m_strTitle(NULL)
{
}

CDlgMessageDecorateSetting::~CDlgMessageDecorateSetting()
{
}

void CDlgMessageDecorateSetting::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_CONDITION_KEYWORD, m_EditConditionKeyword);

	DDX_Text(pDX, IDC_EDIT_CONDITION_KEYWORD, m_DecorateContent.strKeyword);

	DDX_Control(pDX, IDC_EDIT_POSITION_OFFSET, m_EditPositionOffset);
	DDX_Text(pDX, IDC_EDIT_POSITION_OFFSET, m_DecorateContent.iPositionOffset);

	DDX_Control(pDX, IDC_EDIT_ACTION_ADD, m_EditActionAdd);
	DDX_Text(pDX, IDC_EDIT_ACTION_ADD, m_DecorateContent.strAdd);
	DDX_Control(pDX, IDC_EDIT_ACTION_DELETE, m_EditActionDelete);
	DDX_Control(pDX, IDC_EDIT_ACTION_REPLACE_RANGE, m_EditActionReplaceRange);
	DDX_Control(pDX, IDC_EDIT_ACTION_REPLACE, m_EditActionReplace);
	DDX_Text(pDX, IDC_EDIT_ACTION_REPLACE, m_DecorateContent.strReplace);
	DDX_Radio(pDX, IDC_RADIO_CONDITION_WHOLEMESSAGE, m_DecorateContent.iConditionType);
	DDX_Radio(pDX, IDC_RADIO_POSITION_BEGIN, m_DecorateContent.iPositionType);
	DDX_Radio(pDX, IDC_RADIO_ACTION_ADD, m_DecorateContent.iActionType);
	DDX_Text(pDX, IDC_EDIT_ACTION_DELETE, m_DecorateContent.iDeleteRange);

	DDX_Text(pDX, IDC_EDIT_ACTION_REPLACE_RANGE, m_DecorateContent.iReplaceRange);
}

BEGIN_MESSAGE_MAP(CDlgMessageDecorateSetting, CDialog)
	ON_EN_SETFOCUS(IDC_EDIT_CONDITION_KEYWORD, &CDlgMessageDecorateSetting::OnEnSetfocusEditConditionKeyword)
	ON_EN_SETFOCUS(IDC_EDIT_ACTION_ADD, &CDlgMessageDecorateSetting::OnEnSetfocusEditActionAdd)
	ON_EN_SETFOCUS(IDC_EDIT_ACTION_DELETE, &CDlgMessageDecorateSetting::OnEnSetfocusEditActionDelete)
	ON_EN_SETFOCUS(IDC_EDIT_ACTION_REPLACE_RANGE, &CDlgMessageDecorateSetting::OnEnSetfocusEditActionReplaceRange)
	ON_EN_SETFOCUS(IDC_EDIT_ACTION_REPLACE, &CDlgMessageDecorateSetting::OnEnSetfocusEditActionReplace)
END_MESSAGE_MAP()


// CDlgMessageDecorateSetting ��Ϣ�������

BOOL CDlgMessageDecorateSetting::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_ToolTipCtrl.Create(this);

	m_ToolTipCtrl.AddTool(&m_EditConditionKeyword, _T("�ڴ�����ؼ���"));
	m_ToolTipCtrl.AddTool(&m_EditPositionOffset, _T("�ڴ�����ƫ����. ��ֵ��ʾ����ƫ��, ��ֵ��ʾ����ƫ��"));
	m_ToolTipCtrl.AddTool(&m_EditActionAdd, _T("�ڴ�����Ҫ��ӵ�����"));
	m_ToolTipCtrl.AddTool(&m_EditActionDelete, _T("�ڴ�����Ҫɾ�������ַ�Χ. ��ֵ��ʾ����ɾ��, ��ֵ��ʾ����ɾ��"));
	m_ToolTipCtrl.AddTool(&m_EditActionReplaceRange, _T("�ڴ�����Ҫ�滻�����ַ�Χ. ��ֵ��ʾ�ұ����ֱ��滻, ��ֵ��ʾ������ֱ��滻"));
	m_ToolTipCtrl.AddTool(&m_EditActionReplace, _T("�ڴ�����Ҫ�滻������"));

	SetWindowText(m_strTitle);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

BOOL CDlgMessageDecorateSetting::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	if(pMsg->message == WM_LBUTTONDOWN ||
		pMsg->message == WM_LBUTTONUP ||
		pMsg->message == WM_MOUSEMOVE)
	{
		m_ToolTipCtrl.RelayEvent(pMsg);
	}

	return CDialog::PreTranslateMessage(pMsg);
}



void CDlgMessageDecorateSetting::OnEnSetfocusEditConditionKeyword()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	m_DecorateContent.iConditionType = 2;
	UpdateData(FALSE);
}




void CDlgMessageDecorateSetting::OnEnSetfocusEditActionAdd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	m_DecorateContent.iActionType = 0;
	UpdateData(FALSE);
}

void CDlgMessageDecorateSetting::OnEnSetfocusEditActionDelete()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	m_DecorateContent.iActionType = 1;
	UpdateData(FALSE);
}

void CDlgMessageDecorateSetting::OnEnSetfocusEditActionReplaceRange()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	m_DecorateContent.iActionType = 2;
	UpdateData(FALSE);
}

void CDlgMessageDecorateSetting::OnEnSetfocusEditActionReplace()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	m_DecorateContent.iActionType = 2;
	UpdateData(FALSE);
}
