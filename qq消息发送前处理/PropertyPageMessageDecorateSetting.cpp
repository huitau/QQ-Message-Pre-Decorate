// PropertyPageMessageDecorateSetting.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "qq��Ϣ����ǰ����.h"
#include "PropertyPageMessageDecorateSetting.h"
#include "DlgMessageDecorateSetting.h"


// CPropertyPageMessageDecorateSetting �Ի���
using namespace DecorateMessage;

IMPLEMENT_DYNAMIC(CPropertyPageMessageDecorateSetting, CPropertyPage)

CPropertyPageMessageDecorateSetting::CPropertyPageMessageDecorateSetting()
	: CPropertyPage(CPropertyPageMessageDecorateSetting::IDD)
{
	// ��ʼ��m_DecorateContent����������
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


// CPropertyPageMessageDecorateSetting ��Ϣ�������


BOOL CPropertyPageMessageDecorateSetting::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	// ֻ����Ӱ�ť��Ч
	m_ButtonAdd.EnableWindow(TRUE);
	m_ButtonChange.EnableWindow(FALSE);
	m_ButtonDelete.EnableWindow(FALSE);
	m_ButtonUp.EnableWindow(FALSE);
	m_ButtonDown.EnableWindow(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


// �ӹ�����
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDlgMessageDecorateSetting dlg;
	dlg.m_DecorateContent = m_DecorateContent;// ���ø���
	dlg.m_strTitle = _T("���");
	if (dlg.DoModal() == IDOK)
	{
		m_DecorateContent = dlg.m_DecorateContent;// ���渱��
		CDecorate *p = new CDecorate(m_DecorateContent);
		m_ListCtrlDecorateMessage.Add(p);
	}

	m_ListCtrlDecorateMessage.SetFocus();
}

void CPropertyPageMessageDecorateSetting::OnBnClickedButtonChange()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int iCount = m_ListCtrlDecorateMessage.GetItemCount();
	for (int iIndex = 0; iIndex < iCount; ++iIndex)
	{
		if (m_ListCtrlDecorateMessage.GetItemState(iIndex, LVIS_SELECTED))// ��ѡ��, Ҫ���������
		{
			CDecorate *p = m_ListCtrlDecorateMessage.Get(iIndex);
			CDlgMessageDecorateSetting dlg;
			dlg.m_DecorateContent = (*p).m_DecorateContent;
			dlg.m_strTitle = _T("�޸�");
			if (dlg.DoModal() == IDOK)
			{
				(*p).ReConstruct(dlg.m_DecorateContent);
				m_ListCtrlDecorateMessage.Set(iIndex, p);
				m_DecorateContent = (*p).m_DecorateContent;// ���渱��

			}
			break;// ֻ����һ��
		}
	}

	m_ListCtrlDecorateMessage.SetFocus();
}

void CPropertyPageMessageDecorateSetting::OnBnClickedButtonDelete()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int iCount = m_ListCtrlDecorateMessage.GetItemCount();
	for (int iIndex = 0; iIndex < iCount; ++iIndex)
	{
		if (m_ListCtrlDecorateMessage.GetItemState(iIndex, LVIS_SELECTED))// ��ѡ��, Ҫ���������
		{
			CDecorate *p = m_ListCtrlDecorateMessage.Delete(iIndex);
			delete p;
			break;// ֻ����һ��
		}
	}

	m_ListCtrlDecorateMessage.SetFocus();
}

void CPropertyPageMessageDecorateSetting::OnBnClickedButtonUp()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int iCount = m_ListCtrlDecorateMessage.GetItemCount();
	for (int iIndex = 0; iIndex < iCount; ++iIndex)
	{
		if (m_ListCtrlDecorateMessage.GetItemState(iIndex, LVIS_SELECTED))// ��ѡ��, Ҫ���������
		{
			m_ListCtrlDecorateMessage.Exchange(iIndex - 1, iIndex);
			break;// ֻ����һ��
		}
	}

	m_ListCtrlDecorateMessage.SetFocus();
}

void CPropertyPageMessageDecorateSetting::OnBnClickedButtonDown()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int iCount = m_ListCtrlDecorateMessage.GetItemCount();
	for (int iIndex = 0; iIndex < iCount; ++iIndex)
	{
		if (m_ListCtrlDecorateMessage.GetItemState(iIndex, LVIS_SELECTED))// ��ѡ��, Ҫ���������
		{
			m_ListCtrlDecorateMessage.Exchange(iIndex, iIndex + 1);
			break;// ֻ����һ��
		}
	}

	m_ListCtrlDecorateMessage.SetFocus();
}






// ���ڼ�����ť��״̬, ʹ��Ч��ָ�
void CPropertyPageMessageDecorateSetting::OnNMClickListDecorateMessage(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;

	int iCount = m_ListCtrlDecorateMessage.GetItemCount();

	if (pNMItemActivate->iItem == -1)// û��ѡ���κ���
	{
		// ֻ����Ӱ�ť��Ч
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
		if (pNMItemActivate->iItem == 0)// ѡ�е�һ��
			m_ButtonUp.EnableWindow(FALSE);// ���ư�ť��Ч
		else
			m_ButtonUp.EnableWindow(TRUE);// ���ư�ť��Ч


		if (pNMItemActivate->iItem == iCount - 1)// ѡ�����һ��
			m_ButtonDown.EnableWindow(FALSE);// ���ư�ť��Ч
		else
			m_ButtonDown.EnableWindow(TRUE);// ���ư�ť��Ч
	}

}

void CPropertyPageMessageDecorateSetting::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	m_ListCtrlDecorateMessage.OnClose();

	CPropertyPage::OnClose();
}