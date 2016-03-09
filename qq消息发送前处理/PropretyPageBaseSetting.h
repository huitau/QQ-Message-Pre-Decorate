#pragma once
#include "afxwin.h"


// CPropretyPageBaseSetting 对话框

class CPropretyPageBaseSetting : public CPropertyPage
{
	DECLARE_DYNAMIC(CPropretyPageBaseSetting)

public:
	CPropretyPageBaseSetting();
	virtual ~CPropretyPageBaseSetting();

// 对话框数据
	enum { IDD = IDD_PROPPAGE_BASE_SETTING };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m_iSleepTime;
	CEdit m_EditQQMessageSendKey;
	int m_iRadioQQMessageSendHotKey;
	afx_msg void OnEnKillfocusEditSleepTime();
	afx_msg void OnEnKillfocusEditQqMessageSendKey();
	afx_msg void OnBnKillfocusRadioCtrl();
	afx_msg void OnBnKillfocusRadioAlt();
	afx_msg void OnBnKillfocusRadioShift();
	CString m_strQQMessageSendKey;

	struct MESSAGE_SEND_MODE
	{
		void Serialize(CArchive &ar)
		{
			if (ar.IsStoring())
			{
				ar << iExternKey;
				ar << iVirtualKey;
			}
			else
			{
				ar >> iExternKey;
				ar >> iVirtualKey;
			}
		}
		int iExternKey;
		int iVirtualKey;
	} m_msm;
	
	afx_msg void OnClose();
protected:
	virtual void PreSubclassWindow();
};


CArchive &operator << (CArchive &ar, CPropretyPageBaseSetting::MESSAGE_SEND_MODE &msm);
//{
//	msm.Serialize(ar);
//	return ar;
//}

CArchive &operator >> (CArchive &ar, CPropretyPageBaseSetting::MESSAGE_SEND_MODE &msm);
//{
//	msm.Serialize(ar);
//	return ar;
//}