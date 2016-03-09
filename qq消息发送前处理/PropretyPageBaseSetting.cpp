// PropretyPageBaseSetting.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "qq��Ϣ����ǰ����.h"
#include "PropretyPageBaseSetting.h"
#include "MyDlg.h"


// CPropretyPageBaseSetting �Ի���

IMPLEMENT_DYNAMIC(CPropretyPageBaseSetting, CPropertyPage)

CPropretyPageBaseSetting::CPropretyPageBaseSetting()
	: CPropertyPage(CPropretyPageBaseSetting::IDD)
	, m_iSleepTime(100)
	, m_iRadioQQMessageSendHotKey(0)
	, m_strQQMessageSendKey(_T("ENTER"))
{
	// ��ʼ����Ϣ���ͷ�ʽ
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


// CPropretyPageBaseSetting ��Ϣ�������

void CPropretyPageBaseSetting::OnEnKillfocusEditSleepTime()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData();
//	gTrace(_T("Sleepʱ�����޸�Ϊ%d����.\r\n"), m_iSleepTime);
}

void CPropretyPageBaseSetting::OnEnKillfocusEditQqMessageSendKey()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData();

	int iLen = m_strQQMessageSendKey.GetLength();

	if (iLen == 0)
	{
		MessageBox(_T("������������QQ��Ϣʱ���µĿ�ݼ�"));
//		gTrace(_T("������������QQ��Ϣʱ���µĿ�ݼ�.\r\n"));
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
		MessageBox(_T("������Ŀ�ݼ���������, ������һ��Ӣ���ַ���ENTER."));
//		gTrace(_T("������Ŀ�ݼ���������, ������һ��Ӣ���ַ���ENTER.\r\n"));
		m_EditQQMessageSendKey.SetFocus();
		return ;
	}
//	gTrace(_T("QQ��Ϣ���ͼ����޸�Ϊ%s.\r\n"), m_strQQMessageSendKey.GetString());
}

void CPropretyPageBaseSetting::OnBnKillfocusRadioCtrl()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData();
	switch (m_iRadioQQMessageSendHotKey)
	{
	case 0:
		m_msm.iExternKey = VK_CONTROL;
//		gTrace(_T("QQ��Ϣ���͹��ܼ����޸�ΪCTRL.\r\n"));
		break;
	case 1:
		m_msm.iExternKey = VK_MENU;
//		gTrace(_T("QQ��Ϣ���͹��ܼ����޸�ΪALT.\r\n"));
		break;
	case 2:
		m_msm.iExternKey = VK_SHIFT;
//		gTrace(_T("QQ��Ϣ���͹��ܼ����޸�ΪSHIFT.\r\n"));
		break;
	}
}

void CPropretyPageBaseSetting::OnBnKillfocusRadioAlt()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData();
	switch (m_iRadioQQMessageSendHotKey)
	{
	case 0:
		m_msm.iExternKey = VK_CONTROL;
//		gTrace(_T("QQ��Ϣ���͹��ܼ����޸�ΪCTRL.\r\n"));
		break;
	case 1:
		m_msm.iExternKey = VK_MENU;
//		gTrace(_T("QQ��Ϣ���͹��ܼ����޸�ΪALT.\r\n"));
		break;
	case 2:
		m_msm.iExternKey = VK_SHIFT;
//		gTrace(_T("QQ��Ϣ���͹��ܼ����޸�ΪSHIFT.\r\n"));
		break;
	}
}

void CPropretyPageBaseSetting::OnBnKillfocusRadioShift()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData();
	switch (m_iRadioQQMessageSendHotKey)
	{
	case 0:
		m_msm.iExternKey = VK_CONTROL;
//		gTrace(_T("QQ��Ϣ���͹��ܼ����޸�ΪCTRL.\r\n"));
		break;
	case 1:
		m_msm.iExternKey = VK_MENU;
//		gTrace(_T("QQ��Ϣ���͹��ܼ����޸�ΪALT.\r\n"));
		break;
	case 2:
		m_msm.iExternKey = VK_SHIFT;
//		gTrace(_T("QQ��Ϣ���͹��ܼ����޸�ΪSHIFT.\r\n"));
		break;
	}
}

void CPropretyPageBaseSetting::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	
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
	// TODO: �ڴ����ר�ô����/����û���

	try
	{
		// ���ر����decorate����
		CFile file(_T("BaseSetting"), CFile::modeRead | CFile::shareDenyWrite);
		CArchive ar(&file, CArchive::load);

		gTrace(_T("�����ϴ����÷���.\r\n"));

		ar >> m_iSleepTime;
		ar >> m_iRadioQQMessageSendHotKey;
		ar >> m_strQQMessageSendKey;
		ar >> m_msm;

	}
	catch (CFileException *pException)
	{
		pException->m_cause;
		pException->Delete();


		// ���� ���س�ʼ��decorate����
		gTrace(_T("����Ԥ�����÷���.\r\n"));
		// Ԥ���ڹ��캯����


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