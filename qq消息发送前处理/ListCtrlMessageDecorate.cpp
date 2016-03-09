// ListCtrlMessageDecorate.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "qq��Ϣ����ǰ����.h"
#include "ListCtrlMessageDecorate.h"
#include "Decorate.h"
#include "MyDlg.h"

using namespace DecorateMessage;

// CListCtrlMessageDecorate

IMPLEMENT_DYNAMIC(CListCtrlMessageDecorate, CListCtrl)

CListCtrlMessageDecorate::CListCtrlMessageDecorate()
{

}

CListCtrlMessageDecorate::~CListCtrlMessageDecorate()
{
}


BEGIN_MESSAGE_MAP(CListCtrlMessageDecorate, CListCtrl)
	ON_WM_CLOSE()
END_MESSAGE_MAP()



// CListCtrlMessageDecorate ��Ϣ�������


void CListCtrlMessageDecorate::PreSubclassWindow()
{
	// TODO: �ڴ����ר�ô����/����û���

	SetExtendedStyle(LVS_EX_FULLROWSELECT);

	CRect rt;
	GetClientRect(&rt);

	int iWidth = rt.Width() - 20;

	InsertColumn(0, _T("����:"));
	InsertColumn(1, _T("����:"));

	SetColumnWidth(0, iWidth / 2);
	SetColumnWidth(1, iWidth / 2);





	try
	{
		// ���ر����decorate����
		CFile file(_T("DecorateSetting"), CFile::modeRead | CFile::shareDenyWrite);
		CArchive ar(&file, CArchive::load);

		gTrace(_T("�����ϴ����η���.\r\n"));

		int iCount;

		ar >> iCount;

		for (int i = 0; i < iCount; ++i)
		{
			CDecorate *p = new CDecorate;
			ar >> *p;
			Add(p);
		}


	}
	catch (CFileException *pException)
	{
		pException->m_cause;
		pException->Delete();


		// ���� ���س�ʼ��decorate����
		gTrace(_T("����Ԥ�����η���.\r\n"));

		CDecorateContent dc;

		// ÿ�� ��4���ո�
		dc.iConditionType = CDecorateContent::CONDITION_EACHLINE;
		dc.iPositionType = CDecorateContent::POSITION_BEGIN;
		dc.iActionType = CDecorateContent::ACTION_ADD;
		dc.strAdd = _T("    ");
		Add(new CDecorate(dc));

		dc.iConditionType = CDecorateContent::CONDITION_KEYWORD;
		dc.strKeyword = _T("");
		//POSITION_END = 2,
		//POSITION_LINE_END = 5
		dc.iPositionType = CDecorateContent::POSITION_END;
		dc.iActionType = CDecorateContent::ACTION_ADD;
		dc.strAdd = _T("");





		// ���ھ��
#define D(keyword, add) \
dc.strKeyword = keyword;\
dc.iPositionType = CDecorateContent::POSITION_LINE_END;\
dc.strAdd = add;\
Add(new CDecorate(dc));

		//�� /����
		D(_T("��"), _T("/����"));
		//����  �� /΢Ц
		D(_T("����"), _T("/΢Ц"));
		//��ô�� /���
		D(_T("��ô��"), _T("/���"));
		//���� /����
		D(_T("����"), _T("/����"));


		// ���ڴʺ�
#undef D
#define D(keyword, add) \
dc.strKeyword = keyword;\
dc.iPositionType = CDecorateContent::POSITION_END;\
dc.strAdd = add;\
Add(new CDecorate(dc));


		//�ٺ� �� /�ɰ�
		D(_T("�ٺ�"), _T("/�ɰ�"));

		//�Ǻ� �� /��Ц
		D(_T("�Ǻ�"), _T("/��Ц"));

		//���� �� /͵Ц
		D(_T("����"), _T("/͵Ц"));

		//��  �� /΢Ц
		D(_T("��"), _T("/΢Ц"));

		

		//�� �� /����
		D(_T("��"), _T("/����"));

		//ô �� /����
		D(_T("ô"), _T("/����"));

		//���� �� /����
		D(_T("����"), _T("/����"));

		//... �� /����
		D(_T("..."), _T("/����"));

		// �Բ��� �� /���
		D(_T("�Բ���"), _T("/���"));

		//��Ǹ /�ѹ�
		D(_T("��Ǹ"), _T("/�ѹ�"));

		//sorry /�ѹ�
		D(_T("sorry"), _T("/�ѹ�"));

		//���� /����
		D(_T("����"), _T("/����"));

		

		//����� /ί��
		D(_T("�����"), _T("/ί��"));

		//��! /��
		D(_T("��!"), _T("/��"));

		//���� /ǿ
		D(_T("����"), _T("/ǿ"));

		//̫���� /ǿ
		D(_T("̫����"), _T("/ǿ"));

		//���� /ǿ
		D(_T("����"), _T("/ǿ"));

		//���� /�ܶ�
		D(_T("����"), _T("/�ܶ�"));

		//�͵� /���
		D(_T("�͵�"), _T("/���"));

		//�� /��
		D(_T("��"), _T("/��"));

		//�� /̫��
		D(_T("��"), _T("/̫��"));

		

		//˯ /����
		D(_T("˯"), _T("/����"));

		//��� /ʤ��
		D(_T("���"), _T("/ʤ��"));

		//�ߺ� /ʤ��
		D(_T("�ߺ�"), _T("/����"));

		//��� /��ȭ
		D(_T("���"), _T("/��ȭ"));

		

		//������ /��ҹ
		D(_T("������"), _T("/��ҹ"));

		//���� /��ҹ
		D(_T("����"), _T("/��ҹ"));

		//������ /��ҹ
		D(_T("������"), _T("/��ҹ"));

		//�� /����
		D(_T("��"), _T("/����"));

		//���� /����
		D(_T("����"), _T("/����"));

		//�� /����
		D(_T("��"), _T("/����"));

		//��� /΢Ц
		D(_T("���"), _T("/΢Ц"));

		//���Ϻ� /��Ƥ
		D(_T("���Ϻ�"), _T("/��Ƥ"));

		//����� /��Ƥ
		D(_T("�����"), _T("/��Ƥ"));

		//�ð� /��Ƥ
		D(_T("�ð�"), _T("/��Ƥ"));

		//����� /̫��
		D(_T("�����"), _T("/̫��"));

		//����� /��Ƥ
		D(_T("�����"), _T("/��Ƥ"));

		//���Ϻ� /����
		D(_T("���Ϻ�"), _T("/����"));

		//��ҹ /����
		D(_T("��ҹ"), _T("/����"));

		//�� /����
		D(_T("��"), _T("/����"));


#undef D
	}















	CListCtrl::PreSubclassWindow();
}



// ����index
int CListCtrlMessageDecorate::Add(const CDecorate *p)
{
	CString strCondition, strAction;
	TransToString(*p, strCondition, strAction);

	int i = GetItemCount();
	InsertItem(i, strCondition.GetString());
	SetItemData(i, (DWORD_PTR)p);
	SetItemText(i, 1, strAction.GetString());

	return i;
}

CDecorate *CListCtrlMessageDecorate::Delete(int iIndex)
{
	CDecorate *p = (CDecorate *)GetItemData(iIndex);
	DeleteItem(iIndex);
	return p;
}

CDecorate *CListCtrlMessageDecorate::Get(int iIndex)
{
	return (CDecorate *)GetItemData(iIndex);
}

CDecorate *CListCtrlMessageDecorate::Set(int iIndex, CDecorate *pNew)
{
	CDecorate *p = (CDecorate *)GetItemData(iIndex);

	SetItemData(iIndex, (DWORD_PTR)pNew);

	CString strCondition, strAction;
	TransToString(*pNew, strCondition, strAction);
	SetItemText(iIndex, 0, strCondition.GetString());
	SetItemText(iIndex, 1, strAction.GetString());

	return p;
}

void CListCtrlMessageDecorate::Exchange(int iIndex1, int iIndex2)
{
	// ��ʱ����
	DWORD_PTR dp;
	CString strCondition, strAction;

	// ����
	strCondition = GetItemText(iIndex1, 0);
	strAction = GetItemText(iIndex1, 1);
	dp = GetItemData(iIndex1);

	// �û���һ��
	SetItemText(iIndex1, 0,
		GetItemText(iIndex2, 0));
	SetItemText(iIndex1, 1,
		GetItemText(iIndex2, 1));
	SetItemData(iIndex1,
		GetItemData(iIndex2));

	// �û��ڶ���
	SetItemText(iIndex2, 0, strCondition);
	SetItemText(iIndex2, 1, strAction);
	SetItemData(iIndex2, dp);
}


// ��DecorateContentת�����ַ���
void CListCtrlMessageDecorate::TransToString(const DecorateMessage::CDecorate &decorate,
	CString &strCondition, CString &strAction)
{
	CString strT;
	strCondition.Empty();

	switch (decorate.m_DecorateContent.iConditionType)
	{
	case CDecorateContent::CONDITION_WHOLEMESSAGE:
		strCondition += _T("��ȫ����Ϣ");
		break;
	case CDecorateContent::CONDITION_EACHLINE:
		strCondition += _T("��ÿ����Ϣ");
		break;
	case CDecorateContent::CONDITION_KEYWORD:
		strCondition += _T("�ڹؼ���");
		strCondition += decorate.m_DecorateContent.strKeyword;
		break;
	}

	switch (decorate.m_DecorateContent.iPositionType)
	{
	case CDecorateContent::POSITION_BEGIN:
		strCondition += _T("�Ŀ�ʼλ��");
		break;
	case CDecorateContent::POSITION_END:
		strCondition += _T("����ֹλ��");
		break;
	case CDecorateContent::POSITION_MIDDLE:
		strCondition += _T("���м�λ��");
		break;
	case CDecorateContent::POSITION_LINE_BEGIN:
		strCondition += _T("���п�ʼλ��");
		break;
	case CDecorateContent::POSITION_LINE_END:
		strCondition += _T("������ֹλ��");
		break;
	case CDecorateContent::POSITION_LINE_MIDDLE:
		strCondition += _T("�����м�λ��");
		break;
	}

	// �ж��Ƿ���Ҫ����ƫ��
	if (decorate.m_DecorateContent.iPositionOffset < 0)
	{
		strCondition += _T("����ƫ��");
		strT.Format(_T("%d"), -decorate.m_DecorateContent.iPositionOffset);
		strCondition += strT;
		strCondition += _T("���ַ�");
	}
	else if (decorate.m_DecorateContent.iPositionOffset > 0)
	{
		strCondition += _T("����ƫ��");
		strT.Format(_T("%d"), decorate.m_DecorateContent.iPositionOffset);
		strCondition += strT;
		strCondition += _T("���ַ�");
	}



	strAction.Empty();

	switch (decorate.m_DecorateContent.iActionType)
	{
	case CDecorateContent::ACTION_ADD:
		strAction += _T("����");
		strAction += decorate.m_DecorateContent.strAdd;
		break;
	case CDecorateContent::ACTION_DELETE:
		strAction += _T("ɾ��");
		if (decorate.m_DecorateContent.iDeleteRange < 0)
		{
			strAction += _T("���");
			strT.Format(_T("%d"), -decorate.m_DecorateContent.iDeleteRange);
			strAction += strT;
			strAction += _T("���ַ�");
		}
		else
		{
			strAction += _T("�ұ�");
			strT.Format(_T("%d"), decorate.m_DecorateContent.iDeleteRange);
			strAction += strT;
			strAction += _T("���ַ�");
		}
		break;
	case CDecorateContent::ACTION_REPLACE:
		strAction += _T("�滻");
		if (decorate.m_DecorateContent.iReplaceRange < 0)
		{
			strAction += _T("���");
			strT.Format(_T("%d"), -decorate.m_DecorateContent.iReplaceRange);
			strAction += strT;
			strAction += _T("���ַ���");
			strAction += decorate.m_DecorateContent.strReplace;
		}
		else
		{
			strAction += _T("�ұ�");
			strT.Format(_T("%d"), decorate.m_DecorateContent.iReplaceRange);
			strAction += strT;
			strAction += _T("���ַ���");
			strAction += decorate.m_DecorateContent.strReplace;
		}
		break;
	}

}

void CListCtrlMessageDecorate::OnClose()
{
	CFile file(_T("DecorateSetting"), CFile::modeCreate | CFile::modeWrite);
	CArchive ar(&file, CArchive::store);


	int iCount = GetItemCount();

	ar << iCount;

	for (int i = 0; i < iCount; ++i)
	{
		CDecorate *p = Get(i);
		ar << *p;
	}
}