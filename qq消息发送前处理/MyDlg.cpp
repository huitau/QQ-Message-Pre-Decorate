// MyDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "qq消息发送前处理.h"
#include "MyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "MessageDefine.h"
#include "RichEditCtrlLog.h"

#pragma comment(lib, "qq消息发送前处理_DLL.lib")
#include "D:\\C++ Programs\\Win32\\Win32 Dynamic-Link Library\\120807 qq消息发送前处理_DLL\\qq消息发送前处理_DLL\\qq消息发送前处理_DLL.h"


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CMyDlg 对话框



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


// CMyDlg 消息处理程序

BOOL CMyDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	if (MessageBox(_T("\r\n\
这个提示框每次程序启动都会出现, 并非有错误产生, 只是一个信息提示.\r\n\r\n\
\r\n\
程序在运行中会使用剪贴板.\r\n\r\n\
请将剪贴板中重要内容粘贴到别处, 以免剪贴板中数据丢失!\r\n\r\n\
点击确定启动程序; 点击取消退出程序, 且不会修改您剪贴板中数据."),
		0, MB_OKCANCEL | MB_ICONINFORMATION) == IDCANCEL)
	{
		ExitProcess(-1);
		return FALSE;
	}

	m_PropSheetMain.Create(this, WS_CHILD | WS_VISIBLE);

	SetHook(m_hWnd);////////////////////////////////////////////////////////////////

	
	gTrace(_T("双击我清除运行记录.\r\n"));

	OpenClipboard();
	EmptyClipboard();
	gTrace(_T("清空剪贴板数据.\r\n"));
	CloseClipboard();



	gTrace(_T("程序启动完毕.\r\n"));
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMyDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMyDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// 返回TRUE, 消息已处理, 不需要CallNextHook;  返回FALSE, 调用CallNextHook
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
	else if (wParam == m_PropSheetMain.m_PropBaseSetting.m_msm.iVirtualKey )// 是要响应的键
	{
		// 判断是否是腾讯窗口
		CWnd *pWnd = GetForegroundWindow();
		wchar_t wc[500];
		GetClassName(pWnd->m_hWnd, wc, 500);
		if (lstrcmp(wc, _T("TXGuiFoundation")) == 0)

			if ((HIWORD(lParam) & KF_UP) == FALSE)// 是按下状态
			{
				// 看功能键是否按下
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
			else// 其他状态, 不需要postNextmessage了 但也不让qq收到其他关于这个键的消息
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

// hook键确认后, 调用此函数, 转换消息内容
void CMyDlg::TransQQMessage()
{
	AfxTrace(_T("TransQQMessage\r\n"));

	// 全选文字
	KeyboardInput(VK_CONTROL);
	KeyboardInput('A');
	KeyboardInput('A', 0, KEYEVENTF_KEYUP);
	KeyboardInput(VK_CONTROL, 0, KEYEVENTF_KEYUP);

	// 复制文字
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
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	if (nIDEvent == 1)
	{
		// 打开剪贴板
		OpenClipboard();

		// 获取剪贴板文字
		HANDLE hUText = GetClipboardData(CF_UNICODETEXT);

		CString str = (wchar_t *)GlobalLock(hUText);

		GlobalUnlock(hUText);

		// 判断剪贴板是否为空, 为空则无qq消息
		if (str.IsEmpty())
		{
			gTrace(_T("请输入要发送的文字.\r\n"));

			// 关闭剪贴板
			CloseClipboard();

			KillTimer(1);
			return ;
		}

		// 得qq窗口句柄, 用来发消息
		CWnd *pWnd = GetForegroundWindow();

		gTrace(_T("您要发送: %s\r\n"), str.GetString());

		// 修饰文字
		m_PropSheetMain.m_PropDecorateSetting.DecorateString(str);

		gTrace(_T("文字处理成: %s\r\n"), str.GetString());

/////////////////////////////////////////////////////////////////////////////
// 修改剪贴板内容

		// 清空剪贴板
		EmptyClipboard();
		// 分配内存
		hUText = GlobalAlloc(GHND, (str.GetLength() + 1) * sizeof(TCHAR));
		// 锁定内存
		void *p = GlobalLock(hUText);
		// 内存赋值
		memcpy(p, str.GetString(), (str.GetLength() + 1) * sizeof(TCHAR));
		// 解锁内存
		GlobalUnlock(hUText);
		// 设置剪贴板数据
		SetClipboardData(CF_UNICODETEXT, hUText);
		// 关闭剪贴板
		CloseClipboard();

		// 粘贴文字
		pWnd->SendMessage(WM_PASTE);

		// 发送文字
		SetHookState(FALSE);
		KeyboardInput(m_PropSheetMain.m_PropBaseSetting.m_msm.iExternKey);
		KeyboardInput(m_PropSheetMain.m_PropBaseSetting.m_msm.iVirtualKey);
		KeyboardInput(m_PropSheetMain.m_PropBaseSetting.m_msm.iVirtualKey, 0, KEYEVENTF_KEYUP);
		KeyboardInput(m_PropSheetMain.m_PropBaseSetting.m_msm.iExternKey, 0, KEYEVENTF_KEYUP);
		SetTimer(2, m_PropSheetMain.m_PropBaseSetting.m_iSleepTime, NULL);

		gTrace(_T("文字发送结束.\r\n"));

		KillTimer(1);
	}
	else if (nIDEvent == 2)
	{
		SetHookState(TRUE);

		// 清空剪贴板
		OpenClipboard();
		EmptyClipboard();
		CloseClipboard();

		KillTimer(2);
	}

	CDialog::OnTimer(nIDEvent);
}

void CMyDlg::OnNcLButtonDblClk(UINT nHitTest, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CString str(_T("abcdefg\r\nhijklmn\r\nopqrst\r\n"));
//	CString str(_T("abcdefg\r\nhijklmn\r\nopqrst\r\nuvwxyz\r\nabcdefg\r\nhijklmn\r\nopqrst\r\nuvwxyz"));

	// 修饰文字
	m_PropSheetMain.m_PropDecorateSetting.DecorateString(str);

	CDialog::OnNcLButtonDblClk(nHitTest, point);
}

void CMyDlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	m_PropSheetMain.OnClose();

	CDialog::OnClose();
}
