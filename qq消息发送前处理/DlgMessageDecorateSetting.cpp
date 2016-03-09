// DlgMessageDecorateSetting.cpp : 实现文件
//

#include "stdafx.h"
#include "qq消息发送前处理.h"
#include "DlgMessageDecorateSetting.h"


// CDlgMessageDecorateSetting 对话框

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


// CDlgMessageDecorateSetting 消息处理程序

BOOL CDlgMessageDecorateSetting::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_ToolTipCtrl.Create(this);

	m_ToolTipCtrl.AddTool(&m_EditConditionKeyword, _T("在此输入关键词"));
	m_ToolTipCtrl.AddTool(&m_EditPositionOffset, _T("在此输入偏移量. 正值表示向右偏移, 负值表示向左偏移"));
	m_ToolTipCtrl.AddTool(&m_EditActionAdd, _T("在此输入要添加的文字"));
	m_ToolTipCtrl.AddTool(&m_EditActionDelete, _T("在此输入要删除的文字范围. 正值表示向右删除, 负值表示向左删除"));
	m_ToolTipCtrl.AddTool(&m_EditActionReplaceRange, _T("在此输入要替换的文字范围. 正值表示右边文字被替换, 负值表示左边文字被替换"));
	m_ToolTipCtrl.AddTool(&m_EditActionReplace, _T("在此输入要替换的文字"));

	SetWindowText(m_strTitle);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

BOOL CDlgMessageDecorateSetting::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
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
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_DecorateContent.iConditionType = 2;
	UpdateData(FALSE);
}




void CDlgMessageDecorateSetting::OnEnSetfocusEditActionAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_DecorateContent.iActionType = 0;
	UpdateData(FALSE);
}

void CDlgMessageDecorateSetting::OnEnSetfocusEditActionDelete()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_DecorateContent.iActionType = 1;
	UpdateData(FALSE);
}

void CDlgMessageDecorateSetting::OnEnSetfocusEditActionReplaceRange()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_DecorateContent.iActionType = 2;
	UpdateData(FALSE);
}

void CDlgMessageDecorateSetting::OnEnSetfocusEditActionReplace()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_DecorateContent.iActionType = 2;
	UpdateData(FALSE);
}
