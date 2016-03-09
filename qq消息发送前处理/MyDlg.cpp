// MyDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "qq��Ϣ����ǰ����.h"
#include "MyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "MessageDefine.h"
#include "RichEditCtrlLog.h"

#pragma comment(lib, "qq��Ϣ����ǰ����_DLL.lib")
#include "D:\\C++ Programs\\Win32\\Win32 Dynamic-Link Library\\120807 qq��Ϣ����ǰ����_DLL\\qq��Ϣ����ǰ����_DLL\\qq��Ϣ����ǰ����_DLL.h"


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CMyDlg �Ի���



CMyDlg::CMyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyDlg::IDD, pParent)
	, m_bCtrlPressed(FALSE)
	, m_bAltPressed(FALSE)
	, m_bShiftPressed(FALSE)
	, m_PropSheetMain(_T(""), this)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CMyDlg::~CMyDlg()
{
	ReleaseHook();
}

void CMyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMyDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_KEYBOARD_HOOK_FIRST, OnKeyboardHookFirst)
	ON_MESSAGE(WM_KEYBOARD_HOOK_NEXT, OnKeyboardHookNext)
	ON_WM_TIMER()
	ON_WM_NCLBUTTONDBLCLK()
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CMyDlg ��Ϣ�������

BOOL CMyDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	if (MessageBox(_T("\r\n\
�����ʾ��ÿ�γ��������������, �����д������, ֻ��һ����Ϣ��ʾ.\r\n\r\n\
\r\n\
�����������л�ʹ�ü�����.\r\n\r\n\
�뽫����������Ҫ����ճ������, ��������������ݶ�ʧ!\r\n\r\n\
���ȷ����������; ���ȡ���˳�����, �Ҳ����޸���������������."),
		0, MB_OKCANCEL | MB_ICONINFORMATION) == IDCANCEL)
	{
		ExitProcess(-1);
		return FALSE;
	}

	m_PropSheetMain.Create(this, WS_CHILD | WS_VISIBLE);

	SetHook(m_hWnd);////////////////////////////////////////////////////////////////

	
	gTrace(_T("˫����������м�¼.\r\n"));

	OpenClipboard();
	EmptyClipboard();
	gTrace(_T("��ռ���������.\r\n"));
	CloseClipboard();



	gTrace(_T("�����������.\r\n"));
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMyDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMyDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMyDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// ����TRUE, ��Ϣ�Ѵ���, ����ҪCallNextHook;  ����FALSE, ����CallNextHook
afx_msg LRESULT CMyDlg::OnKeyboardHookFirst(WPARAM wParam, LPARAM lParam)
{
	AfxTrace(_T("OnKeyboardHook %X %X\r\n"), wParam, lParam);
	if (wParam == VK_SHIFT)
	{
		if ((HIWORD(lParam) & KF_UP) == FALSE)// set to 0 for WM_KEYDOWN
			m_bShiftPressed = TRUE;
		else if ((HIWORD(lParam) & KF_UP))// set to 1 for WM_KEYUP 
			m_bShiftPressed = FALSE;
	}
	else if (wParam == VK_CONTROL)
	{
		if ((HIWORD(lParam) & KF_UP) == FALSE)// set to 0 for WM_KEYDOWN
			m_bCtrlPressed = TRUE;
		else if ((HIWORD(lParam) & KF_UP))// set to 1 for WM_KEYUP 
			m_bCtrlPressed = FALSE;
	}
	else if (wParam == VK_MENU)
	{
		if ((HIWORD(lParam) & KF_UP) == FALSE)// set to 0 for WM_KEYDOWN
			m_bAltPressed = TRUE;
		else if ((HIWORD(lParam) & KF_UP))// set to 1 for WM_KEYUP 
			m_bAltPressed = FALSE;
	}
	else if (wParam == m_PropSheetMain.m_PropBaseSetting.m_msm.iVirtualKey )// ��Ҫ��Ӧ�ļ�
	{
		// �ж��Ƿ�����Ѷ����
		CWnd *pWnd = GetForegroundWindow();
		wchar_t wc[500];
		GetClassName(pWnd->m_hWnd, wc, 500);
		if (lstrcmp(wc, _T("TXGuiFoundation")) == 0)

			if ((HIWORD(lParam) & KF_UP) == FALSE)// �ǰ���״̬
			{
				// �����ܼ��Ƿ���
				BOOL bExternKeyPressed = FALSE;
				if (m_PropSheetMain.m_PropBaseSetting.m_msm.iExternKey == VK_CONTROL && m_bCtrlPressed)
					bExternKeyPressed = TRUE;
				else if (m_PropSheetMain.m_PropBaseSetting.m_msm.iExternKey == VK_MENU && m_bAltPressed)
					bExternKeyPressed = TRUE;
				else if (m_PropSheetMain.m_PropBaseSetting.m_msm.iExternKey == VK_SHIFT && m_bShiftPressed)
					bExternKeyPressed = TRUE;

				if (bExternKeyPressed)
					return KHF_DONOT_CALLNEXTHOOKEX | KHF_POSTNEXTMESSAGE;
			}
			else// ����״̬, ����ҪpostNextmessage�� ��Ҳ����qq�յ������������������Ϣ
			{
				return KHF_DONOT_CALLNEXTHOOKEX;
			}
	}

	return 0;
}

afx_msg LRESULT CMyDlg::OnKeyboardHookNext(WPARAM wParam, LPARAM lParam)
{
	TransQQMessage();
	return 0;
}

// hook��ȷ�Ϻ�, ���ô˺���, ת����Ϣ����
void CMyDlg::TransQQMessage()
{
	AfxTrace(_T("TransQQMessage\r\n"));

	// ȫѡ����
	KeyboardInput(VK_CONTROL);
	KeyboardInput('A');
	KeyboardInput('A', 0, KEYEVENTF_KEYUP);
	KeyboardInput(VK_CONTROL, 0, KEYEVENTF_KEYUP);

	// ��������
	KeyboardInput(VK_CONTROL);
	KeyboardInput('C');
	KeyboardInput('C', 0, KEYEVENTF_KEYUP);
	KeyboardInput(VK_CONTROL, 0, KEYEVENTF_KEYUP);

	SetTimer(1, m_PropSheetMain.m_PropBaseSetting.m_iSleepTime, NULL);

}

UINT CMyDlg::KeyboardInput(WORD wVk, WORD wScan, DWORD dwFlags)
{
	INPUT ip = { 0 };
	ip.type = INPUT_KEYBOARD;
	ip.ki.wVk = wVk;
	ip.ki.wScan = 0;
	ip.ki.dwFlags = dwFlags;
	return SendInput(1, &ip, sizeof(INPUT));
}

void CMyDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	if (nIDEvent == 1)
	{
		// �򿪼�����
		OpenClipboard();

		// ��ȡ����������
		HANDLE hUText = GetClipboardData(CF_UNICODETEXT);

		CString str = (wchar_t *)GlobalLock(hUText);

		GlobalUnlock(hUText);

		// �жϼ������Ƿ�Ϊ��, Ϊ������qq��Ϣ
		if (str.IsEmpty())
		{
			gTrace(_T("������Ҫ���͵�����.\r\n"));

			// �رռ�����
			CloseClipboard();

			KillTimer(1);
			return ;
		}

		// ��qq���ھ��, ��������Ϣ
		CWnd *pWnd = GetForegroundWindow();

		gTrace(_T("��Ҫ����: %s\r\n"), str.GetString());

		// ��������
		m_PropSheetMain.m_PropDecorateSetting.DecorateString(str);

		gTrace(_T("���ִ����: %s\r\n"), str.GetString());

/////////////////////////////////////////////////////////////////////////////
// �޸ļ���������

		// ��ռ�����
		EmptyClipboard();
		// �����ڴ�
		hUText = GlobalAlloc(GHND, (str.GetLength() + 1) * sizeof(TCHAR));
		// �����ڴ�
		void *p = GlobalLock(hUText);
		// �ڴ渳ֵ
		memcpy(p, str.GetString(), (str.GetLength() + 1) * sizeof(TCHAR));
		// �����ڴ�
		GlobalUnlock(hUText);
		// ���ü���������
		SetClipboardData(CF_UNICODETEXT, hUText);
		// �رռ�����
		CloseClipboard();

		// ճ������
		pWnd->SendMessage(WM_PASTE);

		// ��������
		SetHookState(FALSE);
		KeyboardInput(m_PropSheetMain.m_PropBaseSetting.m_msm.iExternKey);
		KeyboardInput(m_PropSheetMain.m_PropBaseSetting.m_msm.iVirtualKey);
		KeyboardInput(m_PropSheetMain.m_PropBaseSetting.m_msm.iVirtualKey, 0, KEYEVENTF_KEYUP);
		KeyboardInput(m_PropSheetMain.m_PropBaseSetting.m_msm.iExternKey, 0, KEYEVENTF_KEYUP);
		SetTimer(2, m_PropSheetMain.m_PropBaseSetting.m_iSleepTime, NULL);

		gTrace(_T("���ַ��ͽ���.\r\n"));

		KillTimer(1);
	}
	else if (nIDEvent == 2)
	{
		SetHookState(TRUE);

		// ��ռ�����
		OpenClipboard();
		EmptyClipboard();
		CloseClipboard();

		KillTimer(2);
	}

	CDialog::OnTimer(nIDEvent);
}

void CMyDlg::OnNcLButtonDblClk(UINT nHitTest, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CString str(_T("abcdefg\r\nhijklmn\r\nopqrst\r\n"));
//	CString str(_T("abcdefg\r\nhijklmn\r\nopqrst\r\nuvwxyz\r\nabcdefg\r\nhijklmn\r\nopqrst\r\nuvwxyz"));

	// ��������
	m_PropSheetMain.m_PropDecorateSetting.DecorateString(str);

	CDialog::OnNcLButtonDblClk(nHitTest, point);
}

void CMyDlg::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	m_PropSheetMain.OnClose();

	CDialog::OnClose();
}
