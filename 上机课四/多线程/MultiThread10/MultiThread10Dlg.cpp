// MultiThread10Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "MultiThread10.h"
#include "MultiThread10Dlg.h"

#include "afxmt.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


CSemaphore semaphoreWrite(2,2);
char g_Array[10];


/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMultiThread10Dlg dialog

CMultiThread10Dlg::CMultiThread10Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMultiThread10Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMultiThread10Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMultiThread10Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMultiThread10Dlg)
	DDX_Control(pDX, IDC_C, m_ctrlC);
	DDX_Control(pDX, IDC_B, m_ctrlB);
	DDX_Control(pDX, IDC_A, m_ctrlA);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMultiThread10Dlg, CDialog)
	//{{AFX_MSG_MAP(CMultiThread10Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_START, OnStart)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMultiThread10Dlg message handlers

BOOL CMultiThread10Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	for(int i=0;i<10;i++)
	{
		g_Array[i]='I';
	}
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMultiThread10Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMultiThread10Dlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMultiThread10Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMultiThread10Dlg::OnStart() 
{
	CWinThread *pWriteA=AfxBeginThread(WriteA,
		&m_ctrlA,
		THREAD_PRIORITY_NORMAL,
		0,
		CREATE_SUSPENDED);
	pWriteA->ResumeThread();

	CWinThread *pWriteB=AfxBeginThread(WriteB,
		&m_ctrlB,
		THREAD_PRIORITY_NORMAL,
		0,
		CREATE_SUSPENDED);
	pWriteB->ResumeThread();

	CWinThread *pWriteC=AfxBeginThread(WriteC,
		&m_ctrlC,
		THREAD_PRIORITY_NORMAL,
		0,
		CREATE_SUSPENDED);
	pWriteC->ResumeThread();

	
}
UINT WriteA(LPVOID pParam)
{
	CEdit *pEdit=(CEdit*)pParam;
	pEdit->SetWindowText("");
	WaitForSingleObject(semaphoreWrite.m_hObject,INFINITE);
	CString str;
	for(int i=0;i<10;i++)
	{
        pEdit->GetWindowText(str);
		g_Array[i]='A';
		str=str+g_Array[i];
	    pEdit->SetWindowText(str);
		Sleep(1000);
	}
	ReleaseSemaphore(semaphoreWrite.m_hObject,1,NULL);
	return 0;

}
UINT WriteB(LPVOID pParam)
{
	CEdit *pEdit=(CEdit*)pParam;
	pEdit->SetWindowText("");
	WaitForSingleObject(semaphoreWrite.m_hObject,INFINITE);
	CString str;
	for(int i=0;i<10;i++)
	{

        pEdit->GetWindowText(str);
		g_Array[i]='B';
		str=str+g_Array[i];
	    pEdit->SetWindowText(str);
		Sleep(1000);
	}
	ReleaseSemaphore(semaphoreWrite.m_hObject,1,NULL);
	return 0;

}
UINT WriteC(LPVOID pParam)
{
	CEdit *pEdit=(CEdit*)pParam;
	pEdit->SetWindowText("");
	WaitForSingleObject(semaphoreWrite.m_hObject,INFINITE);
	for(int i=0;i<10;i++)
	{
		g_Array[i]='C';
	    pEdit->SetWindowText(g_Array);
		Sleep(1000);
	}
	ReleaseSemaphore(semaphoreWrite.m_hObject,1,NULL);
	return 0;

}
