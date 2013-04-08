// bDlg.cpp : implementation file
//

#include "stdafx.h"
#include "b.h"
#include "bDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

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
// CBDlg dialog

CBDlg::CBDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBDlg)
	m_edit = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBDlg)
	DDX_Control(pDX, IDC_CHECK1, m_sync);
	DDX_Text(pDX, IDC_EDIT1, m_edit);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CBDlg, CDialog)
	//{{AFX_MSG_MAP(CBDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBDlg message handlers

BOOL CBDlg::OnInitDialog()
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
	
	// TODO: Add extra initialization here
	m_sync.SetCheck(1);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CBDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CBDlg::OnPaint() 
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
HCURSOR CBDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CBDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	m_edit="";
	
	CFile filetext;
	if (filetext.Open("1.txt",CFile::modeRead))
	{
		char buffer[512];
		UINT uBytesRead;
		while(uBytesRead=filetext.Read(buffer,sizeof(buffer)-1))
		{
			buffer[uBytesRead]='\0';
			m_edit+=CString(buffer);

		}
		filetext.Close();
		UpdateData(false);
	}
	else
		AfxMessageBox("file cannot open!");
	
}


class CMyfile
{
public:
	CMyfile()
	{
		
		InitializeCriticalSection(&cs);
	}
	~CMyfile()
	{
		DeleteCriticalSection(&cs);

	}
	void msglog(char* buffer,int length,int wait)
	{
		static int i=0;
		CString a;
		a.Format("%d#",i++);
		if (m_bSync) EnterCriticalSection(&cs);
		fwrite("\n", 1, 1, fstream);
		fwrite(a+CString('-',50), 52, 1, fstream);
		fwrite("\n", 1, 1, fstream);
		fwrite(buffer, length, 1, fstream);	
		Sleep(wait);
		fwrite("\n", 1, 1, fstream);
		fwrite(a+CString('-',50), 52, 1, fstream);
		fflush(fstream);
	 	if (m_bSync) LeaveCriticalSection(&cs);
	
	}

	bool openfile(CString filename,bool bSync)
	{
		m_filename=filename;
		m_bSync=bSync;
		if((fstream=fopen(filename, "wt")) == NULL) 
			return false ;
		else
			return true;
	}
	void closefile()
	{
		fclose(fstream);
		
	}

protected:
     CRITICAL_SECTION cs;
	 FILE* fstream;
	 CString m_filename;
	 bool m_bSync;
	
private:
};

UINT threadFunc( LPVOID p);
void CBDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	
    CMyfile file;
	if (m_sync.GetCheck()==1)
    	file.openfile("1.txt",true);//同步
	else
		file.openfile("1.txt",false);//异步

	CWinThread* thd[10];
	HANDLE hThd[10];
	for(int i=0;i<10;i++)
	{
		thd[i]=AfxBeginThread(threadFunc,&file);
		Sleep(10);//故意制造线程启动时间的不一致
		hThd[i]=thd[i]->m_hThread;
	}
	WaitForMultipleObjects(10,hThd,true,INFINITE);//等待所有线程结束
	file.closefile();
	AfxMessageBox("ok");
	
}
UINT threadFunc( LPVOID p)
{
 	CMyfile* file=(CMyfile*)p;
	long lThreadID = ::AfxGetThread()->m_nThreadID;
	CString a;
	a.Format("thread %d",lThreadID);

	
    for (int i=0;i<100;i++)
	{
		CTime time=CTime::GetCurrentTime();
		CString str=time.Format("%y-%m-%d %H:%M:%S");
		str=str+"--------->"+a;
		file->msglog(str.GetBuffer(str.GetLength()),str.GetLength(),lThreadID/100);
	}

	return 1;
	
	
}
