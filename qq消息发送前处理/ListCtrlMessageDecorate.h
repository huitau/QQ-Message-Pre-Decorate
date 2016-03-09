#pragma once


// CListCtrlMessageDecorate

namespace DecorateMessage
{
	class CDecorateContent;
	class CDecorate;
}

using namespace DecorateMessage;

class CListCtrlMessageDecorate : public CListCtrl
{
	DECLARE_DYNAMIC(CListCtrlMessageDecorate)

public:
	CListCtrlMessageDecorate();
	virtual ~CListCtrlMessageDecorate();

	// ����index
	int Add(const CDecorate *p);

	CDecorate *Delete(int iIndex);

	CDecorate *Get(int iIndex);

	CDecorate *Set(int iIndex, CDecorate *pNew);

	void Exchange(int iIndex1, int iIndex2);



	// ��DecorateContentת�����ַ���
	void TransToString(const DecorateMessage::CDecorate &decorate,
		CString &strCondition, CString &strAction);

protected:
	DECLARE_MESSAGE_MAP()

	virtual void PreSubclassWindow();

public:
	void OnClose();
};


