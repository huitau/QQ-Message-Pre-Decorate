// PropertyPageMessageDecorateSetting.cpp : 实现文件
//

#include "stdafx.h"
#include "qq消息发送前处理.h"
#include "PropertyPageMessageDecorateSetting.h"
#include "DlgMessageDecorateSetting.h"


// CPropertyPageMessageDecorateSetting 对话框
using namespace DecorateMessage;

IMPLEMENT_DYNAMIC(CPropertyPageMessageDecorateSetting, CPropertyPage)

CPropertyPageMessageDecorateSetting::CPropertyPageMessageDecorateSetting()
	: CPropertyPage(CPropertyPageMessageDecorateSetting::IDD)
{
	// 初始化m_DecorateContent副本的数据
	m_DecorateContent.iPositionOffset = 0;
	m_DecorateContent.iDeleteRange = 0;
	m_DecorateContent.iReplaceRange = 0;
	m_DecorateContent.iConditionType = 0;
	m_DecorateContent.iPositionType = 0;
	m_DecorateContent.iActionType = 0;
}

CPropertyPageMessageDecorateSetting::~CPropertyPageMessageDecorateSetting()
{
}

void CPropertyPageMessageDecorateSetting::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_DECORATE_MESSAGE, m_ListCtrlDecorateMessage);
	DDX_Control(pDX, IDC_BUTTON_ADD, m_ButtonAdd);
	DDX_Control(pDX, IDC_BUTTON_CHANGE, m_ButtonChange);
	DDX_Control(pDX, IDC_BUTTON_DELETE, m_ButtonDelete);
	DDX_Control(pDX, IDC_BUTTON_UP, m_ButtonUp);
	DDX_Control(pDX, IDC_BUTTON_DOWN, m_ButtonDown);
}


BEGIN_MESSAGE_MAP(CPropertyPageMessageDecorateSetting, CPropertyPage)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CPropertyPageMessageDecorateSetting::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_CHANGE, &CPropertyPageMessageDecorateSetting::OnBnClickedButtonChange)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &CPropertyPageMessageDecorateSetting::OnBnClickedButtonDelete)
	ON_NOTIFY(NM_CLICK, IDC_LIST_DECORATE_MESSAGE, &CPropertyPageMessageDecorateSetting::OnNMClickListDecorateMessage)
	ON_BN_CLICKED(IDC_BUTTON_UP, &CPropertyPageMessageDecorateSetting::OnBnClickedButtonUp)
	ON_BN_CLICKED(IDC_BUTTON_DOWN, &CPropertyPageMessageDecorateSetting::OnBnClickedButtonDown)

END_MESSAGE_MAP()


// CPropertyPageMessageDecorateSetting 消息处理程序


BOOL CPropertyPageMessageDecorateSetting::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	// TODO:  在此添加额外的初始化

	// 只有添加按钮有效
	m_ButtonAdd.EnableWindow(TRUE);
	m_ButtonChange.EnableWindow(FALSE);
	m_ButtonDelete.EnableWindow(FALSE);
	m_ButtonUp.EnableWindow(FALSE);
	m_ButtonDown.EnableWindow(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


// 加工文字
void CPropertyPageMessageDecorateSetting::DecorateString(CString &str)
{
	int iCount = m_ListCtrlDecorateMessage.GetItemCount();
	for (int i = 0; i < iCount; ++i)
	{
		CDecorate *p = m_ListCtrlDecorateMessage.Get(i);
		p->Decorate(str);
	}
}
void CPropertyPageMessageDecorateSetting::OnBnClickedButtonAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	CDlgMessageDecorateSetting dlg;
	dlg.m_DecorateContent = m_DecorateContent;// 设置副本
	dlg.m_strTitle = _T("添加");
	if (dlg.DoModal() == IDOK)
	{
		m_DecorateContent = dlg.m_DecorateContent;// 保存副本
		CDecorate *p = new CDecorate(m_DecorateContent);
		m_ListCtrlDecorateMessage.Add(p);
	}

	m_ListCtrlDecorateMessage.SetFocus();
}

void CPropertyPageMessageDecorateSetting::OnBnClickedButtonChange()
{
	// TODO: 在此添加控件通知处理程序代码
	int iCount = m_ListCtrlDecorateMessage.GetItemCount();
	for (int iIndex = 0; iIndex < iCount; ++iIndex)
	{
		if (m_ListCtrlDecorateMessage.GetItemState(iIndex, LVIS_SELECTED))// 被选中, 要处理这个了
		{
			CDecorate *p = m_ListCtrlDecorateMessage.Get(iIndex);
			CDlgMessageDecorateSetting dlg;
			dlg.m_DecorateContent = (*p).m_DecorateContent;
			dlg.m_strTitle = _T("修改");
			if (dlg.DoModal() == IDOK)
			{
				(*p).ReConstruct(dlg.m_DecorateContent);
				m_ListCtrlDecorateMessage.Set(iIndex, p);
				m_DecorateContent = (*p).m_DecorateContent;// 保存副本

			}
			break;// 只处理一次
		}
	}

	m_ListCtrlDecorateMessage.SetFocus();
}

void CPropertyPageMessageDecorateSetting::OnBnClickedButtonDelete()
{
	// TODO: 在此添加控件通知处理程序代码
	int iCount = m_ListCtrlDecorateMessage.GetItemCount();
	for (int iIndex = 0; iIndex < iCount; ++iIndex)
	{
		if (m_ListCtrlDecorateMessage.GetItemState(iIndex, LVIS_SELECTED))// 被选中, 要处理这个了
		{
			CDecorate *p = m_ListCtrlDecorateMessage.Delete(iIndex);
			delete p;
			break;// 只处理一次
		}
	}

	m_ListCtrlDecorateMessage.SetFocus();
}

void CPropertyPageMessageDecorateSetting::OnBnClickedButtonUp()
{
	// TODO: 在此添加控件通知处理程序代码
	int iCount = m_ListCtrlDecorateMessage.GetItemCount();
	for (int iIndex = 0; iIndex < iCount; ++iIndex)
	{
		if (m_ListCtrlDecorateMessage.GetItemState(iIndex, LVIS_SELECTED))// 被选中, 要处理这个了
		{
			m_ListCtrlDecorateMessage.Exchange(iIndex - 1, iIndex);
			break;// 只处理一次
		}
	}

	m_ListCtrlDecorateMessage.SetFocus();
}

void CPropertyPageMessageDecorateSetting::OnBnClickedButtonDown()
{
	// TODO: 在此添加控件通知处理程序代码
	int iCount = m_ListCtrlDecorateMessage.GetItemCount();
	for (int iIndex = 0; iIndex < iCount; ++iIndex)
	{
		if (m_ListCtrlDecorateMessage.GetItemState(iIndex, LVIS_SELECTED))// 被选中, 要处理这个了
		{
			m_ListCtrlDecorateMessage.Exchange(iIndex, iIndex + 1);
			break;// 只处理一次
		}
	}

	m_ListCtrlDecorateMessage.SetFocus();
}






// 调节几个按钮的状态, 使无效或恢复
void CPropertyPageMessageDecorateSetting::OnNMClickListDecorateMessage(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;

	int iCount = m_ListCtrlDecorateMessage.GetItemCount();

	if (pNMItemActivate->iItem == -1)// 没有选中任何项
	{
		// 只有添加按钮有效
		m_ButtonAdd.EnableWindow(TRUE);
		m_ButtonChange.EnableWindow(FALSE);
		m_ButtonDelete.EnableWindow(FALSE);
		m_ButtonUp.EnableWindow(FALSE);
		m_ButtonDown.EnableWindow(FALSE);
	}
	else
	{
		m_ButtonAdd.EnableWindow(TRUE);
		m_ButtonChange.EnableWindow(TRUE);
		m_ButtonDelete.EnableWindow(TRUE);
		if (pNMItemActivate->iItem == 0)// 选中第一项
			m_ButtonUp.EnableWindow(FALSE);// 上移按钮无效
		else
			m_ButtonUp.EnableWindow(TRUE);// 上移按钮有效


		if (pNMItemActivate->iItem == iCount - 1)// 选中最后一项
			m_ButtonDown.EnableWindow(FALSE);// 下移按钮无效
		else
			m_ButtonDown.EnableWindow(TRUE);// 下移按钮有效
	}

}

void CPropertyPageMessageDecorateSetting::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	m_ListCtrlDecorateMessage.OnClose();

	CPropertyPage::OnClose();
}