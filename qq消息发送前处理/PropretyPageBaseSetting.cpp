// PropretyPageBaseSetting.cpp : 实现文件
//

#include "stdafx.h"
#include "qq消息发送前处理.h"
#include "PropretyPageBaseSetting.h"
#include "MyDlg.h"


// CPropretyPageBaseSetting 对话框

IMPLEMENT_DYNAMIC(CPropretyPageBaseSetting, CPropertyPage)

CPropretyPageBaseSetting::CPropretyPageBaseSetting()
	: CPropertyPage(CPropretyPageBaseSetting::IDD)
	, m_iSleepTime(100)
	, m_iRadioQQMessageSendHotKey(0)
	, m_strQQMessageSendKey(_T("ENTER"))
{
	// 初始化消息发送方式
	switch (m_iRadioQQMessageSendHotKey)
	{
	case 0:
		m_msm.iExternKey = VK_CONTROL;
		break;
	case 1:
		m_msm.iExternKey = VK_MENU;
		break;
	case 2:
		m_msm.iExternKey = VK_SHIFT;
		break;
	}
	
	int iLen = m_strQQMessageSendKey.GetLength();

	if (iLen == 1)
	{
		wchar_t w = *m_strQQMessageSendKey.GetString();
		m_msm.iVirtualKey = w;
	}
	else if (lstrcmpi(m_strQQMessageSendKey.GetString(), _T("enter")) == 0)
	{
		m_msm.iVirtualKey = VK_RETURN;
	}
}

CPropretyPageBaseSetting::~CPropretyPageBaseSetting()
{
}

void CPropretyPageBaseSetting::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_SLEEP_TIME, m_iSleepTime);
	DDV_MinMaxInt(pDX, m_iSleepTime, 0, 2147483647);
	DDX_Control(pDX, IDC_EDIT_QQ_MESSAGE_SEND_KEY, m_EditQQMessageSendKey);
	DDX_Radio(pDX, IDC_RADIO_CTRL, m_iRadioQQMessageSendHotKey);
	DDX_Text(pDX, IDC_EDIT_QQ_MESSAGE_SEND_KEY, m_strQQMessageSendKey);
}


BEGIN_MESSAGE_MAP(CPropretyPageBaseSetting, CPropertyPage)
	ON_EN_KILLFOCUS(IDC_EDIT_SLEEP_TIME, &CPropretyPageBaseSetting::OnEnKillfocusEditSleepTime)
	ON_EN_KILLFOCUS(IDC_EDIT_QQ_MESSAGE_SEND_KEY, &CPropretyPageBaseSetting::OnEnKillfocusEditQqMessageSendKey)
	ON_BN_KILLFOCUS(IDC_RADIO_CTRL, &CPropretyPageBaseSetting::OnBnKillfocusRadioCtrl)
	ON_BN_KILLFOCUS(IDC_RADIO_ALT, &CPropretyPageBaseSetting::OnBnKillfocusRadioAlt)
	ON_BN_KILLFOCUS(IDC_RADIO_SHIFT, &CPropretyPageBaseSetting::OnBnKillfocusRadioShift)

END_MESSAGE_MAP()


// CPropretyPageBaseSetting 消息处理程序

void CPropretyPageBaseSetting::OnEnKillfocusEditSleepTime()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
//	gTrace(_T("Sleep时间已修改为%d毫秒.\r\n"), m_iSleepTime);
}

void CPropretyPageBaseSetting::OnEnKillfocusEditQqMessageSendKey()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();

	int iLen = m_strQQMessageSendKey.GetLength();

	if (iLen == 0)
	{
		MessageBox(_T("请输入您发送QQ消息时按下的快捷键"));
//		gTrace(_T("请输入您发送QQ消息时按下的快捷键.\r\n"));
		m_EditQQMessageSendKey.SetFocus();
		return ;
	}
	else if (iLen == 1)
	{
		wchar_t w = *m_strQQMessageSendKey.GetString();
		m_msm.iVirtualKey = w;
	}
	else if (lstrcmpi(m_strQQMessageSendKey.GetString(), _T("enter")) == 0)
	{
		m_msm.iVirtualKey = VK_RETURN;
	}
	else
	{
		MessageBox(_T("您输入的快捷键不被承认, 请输入一个英文字符或ENTER."));
//		gTrace(_T("您输入的快捷键不被承认, 请输入一个英文字符或ENTER.\r\n"));
		m_EditQQMessageSendKey.SetFocus();
		return ;
	}
//	gTrace(_T("QQ消息发送键已修改为%s.\r\n"), m_strQQMessageSendKey.GetString());
}

void CPropretyPageBaseSetting::OnBnKillfocusRadioCtrl()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	switch (m_iRadioQQMessageSendHotKey)
	{
	case 0:
		m_msm.iExternKey = VK_CONTROL;
//		gTrace(_T("QQ消息发送功能键已修改为CTRL.\r\n"));
		break;
	case 1:
		m_msm.iExternKey = VK_MENU;
//		gTrace(_T("QQ消息发送功能键已修改为ALT.\r\n"));
		break;
	case 2:
		m_msm.iExternKey = VK_SHIFT;
//		gTrace(_T("QQ消息发送功能键已修改为SHIFT.\r\n"));
		break;
	}
}

void CPropretyPageBaseSetting::OnBnKillfocusRadioAlt()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	switch (m_iRadioQQMessageSendHotKey)
	{
	case 0:
		m_msm.iExternKey = VK_CONTROL;
//		gTrace(_T("QQ消息发送功能键已修改为CTRL.\r\n"));
		break;
	case 1:
		m_msm.iExternKey = VK_MENU;
//		gTrace(_T("QQ消息发送功能键已修改为ALT.\r\n"));
		break;
	case 2:
		m_msm.iExternKey = VK_SHIFT;
//		gTrace(_T("QQ消息发送功能键已修改为SHIFT.\r\n"));
		break;
	}
}

void CPropretyPageBaseSetting::OnBnKillfocusRadioShift()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	switch (m_iRadioQQMessageSendHotKey)
	{
	case 0:
		m_msm.iExternKey = VK_CONTROL;
//		gTrace(_T("QQ消息发送功能键已修改为CTRL.\r\n"));
		break;
	case 1:
		m_msm.iExternKey = VK_MENU;
//		gTrace(_T("QQ消息发送功能键已修改为ALT.\r\n"));
		break;
	case 2:
		m_msm.iExternKey = VK_SHIFT;
//		gTrace(_T("QQ消息发送功能键已修改为SHIFT.\r\n"));
		break;
	}
}

void CPropretyPageBaseSetting::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	
	CFile file(_T("BaseSetting"), CFile::modeCreate | CFile::modeWrite);
	CArchive ar(&file, CArchive::store);

	ar << m_iSleepTime;
	ar << m_iRadioQQMessageSendHotKey;
	ar << m_strQQMessageSendKey;
	ar << m_msm;

	CPropertyPage::OnClose();
}

void CPropretyPageBaseSetting::PreSubclassWindow()
{
	// TODO: 在此添加专用代码和/或调用基类

	try
	{
		// 加载保存的decorate内容
		CFile file(_T("BaseSetting"), CFile::modeRead | CFile::shareDenyWrite);
		CArchive ar(&file, CArchive::load);

		gTrace(_T("加载上次设置方案.\r\n"));

		ar >> m_iSleepTime;
		ar >> m_iRadioQQMessageSendHotKey;
		ar >> m_strQQMessageSendKey;
		ar >> m_msm;

	}
	catch (CFileException *pException)
	{
		pException->m_cause;
		pException->Delete();


		// 出错 加载初始的decorate数据
		gTrace(_T("加载预置设置方案.\r\n"));
		// 预置在构造函数中


	}

	CPropertyPage::PreSubclassWindow();
}

CArchive &operator << (CArchive &ar, CPropretyPageBaseSetting::MESSAGE_SEND_MODE &msm)
{
	msm.Serialize(ar);
	return ar;
}

CArchive &operator >> (CArchive &ar, CPropretyPageBaseSetting::MESSAGE_SEND_MODE &msm)
{
	msm.Serialize(ar);
	return ar;
}