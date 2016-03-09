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

	// 返回index
	int Add(const CDecorate *p);

	CDecorate *Delete(int iIndex);

	CDecorate *Get(int iIndex);

	CDecorate *Set(int iIndex, CDecorate *pNew);

	void Exchange(int iIndex1, int iIndex2);



	// 把DecorateContent转换成字符串
	void TransToString(const DecorateMessage::CDecorate &decorate,
		CString &strCondition, CString &strAction);

protected:
	DECLARE_MESSAGE_MAP()

	virtual void PreSubclassWindow();

public:
	void OnClose();
};


