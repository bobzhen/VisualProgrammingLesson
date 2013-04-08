// RecordHWndDlg.cpp : implementation file
//

#include "stdafx.h"
#include "RecordHWnd.h"
#include "RecordHWndDlg.h"



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
// CRecordHWndDlg dialog

CRecordHWndDlg::CRecordHWndDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRecordHWndDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRecordHWndDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	bRecording=FALSE;
	bPlaying=FALSE;
	bReverse=FALSE;
	bPaused=FALSE;
	bEnding=FALSE;
	bTerminating=FALSE;
	dwDataLength=0;
	dwRepetitions=1;
}

void CRecordHWndDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRecordHWndDlg)
	DDX_Control(pDX, IDC_STATIC1, m_mailCtrl);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CRecordHWndDlg, CDialog)
	//{{AFX_MSG_MAP(CRecordHWndDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_REC_START, OnRecStart)
	ON_BN_CLICKED(IDC_REC_STOP, OnRecStop)
	ON_MESSAGE(MM_WIM_OPEN,OnMM_WIM_OPEN)
	ON_MESSAGE(MM_WIM_DATA,OnMM_WIM_DATA)
	ON_MESSAGE(MM_WIM_CLOSE,OnMM_WIM_CLOSE)
	ON_MESSAGE(MM_WOM_OPEN,OnMM_WOM_OPEN)
	ON_MESSAGE(MM_WOM_DONE,OnMM_WOM_DONE)
	ON_MESSAGE(MM_WOM_CLOSE,OnMM_WOM_CLOSE)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_PLAY_START, OnPlayStart)
	ON_BN_CLICKED(IDC_PLAY_PAUSE, OnPlayPause)
	ON_BN_CLICKED(IDC_PLAY_STOP, OnPlayStop)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRecordHWndDlg message handlers

BOOL CRecordHWndDlg::OnInitDialog()
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
	//allocate memory for wave header
	pWaveHdr1=reinterpret_cast<PWAVEHDR>(malloc(sizeof(WAVEHDR)));
	pWaveHdr2=reinterpret_cast<PWAVEHDR>(malloc(sizeof(WAVEHDR)));
	
	//allocate memory for save buffer
	pSaveBuffer = reinterpret_cast<PBYTE>(malloc(1));
	///set mail
	m_mailCtrl.SetURL(_T("mailto:luan_ym@sina.com.cn"));

	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CRecordHWndDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CRecordHWndDlg::OnPaint() 
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
HCURSOR CRecordHWndDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CRecordHWndDlg::OnRecStart() 
{
	// TODO: Add your control notification handler code here
	//allocate buffer memory
	pBuffer1=(PBYTE)malloc(INP_BUFFER_SIZE);
	pBuffer2=(PBYTE)malloc(INP_BUFFER_SIZE);
	if (!pBuffer1 || !pBuffer2) {
		if (pBuffer1) free(pBuffer1);
		if (pBuffer2) free(pBuffer2);
		MessageBeep(MB_ICONEXCLAMATION);
		AfxMessageBox("Memory erro!");
		return ;
	}
	
	//open waveform audo for input
	
	waveform.wFormatTag=WAVE_FORMAT_PCM;
	waveform.nChannels=1;
	waveform.nSamplesPerSec=11025;
	waveform.nAvgBytesPerSec=11025;
	waveform.nBlockAlign=1;
	waveform.wBitsPerSample=8;
	waveform.cbSize=0;

	
	if (waveInOpen(&hWaveIn,WAVE_MAPPER,&waveform,(DWORD)this->m_hWnd,NULL,CALLBACK_WINDOW)) {
		free(pBuffer1);
		free(pBuffer2);
		MessageBeep(MB_ICONEXCLAMATION);
		AfxMessageBox("Audio can not be open!");
	}
	pWaveHdr1->lpData=(LPTSTR)pBuffer1;
	pWaveHdr1->dwBufferLength=INP_BUFFER_SIZE;
	pWaveHdr1->dwBytesRecorded=0;
	pWaveHdr1->dwUser=0;
	pWaveHdr1->dwFlags=0;
	pWaveHdr1->dwLoops=1;
	pWaveHdr1->lpNext=NULL;
	pWaveHdr1->reserved=0;
	
	waveInPrepareHeader(hWaveIn,pWaveHdr1,sizeof(WAVEHDR));
	
	pWaveHdr2->lpData=(LPTSTR)pBuffer2;
	pWaveHdr2->dwBufferLength=INP_BUFFER_SIZE;
	pWaveHdr2->dwBytesRecorded=0;
	pWaveHdr2->dwUser=0;
	pWaveHdr2->dwFlags=0;
	pWaveHdr2->dwLoops=1;
	pWaveHdr2->lpNext=NULL;
	pWaveHdr2->reserved=0;
	
	waveInPrepareHeader(hWaveIn,pWaveHdr2,sizeof(WAVEHDR));
	
	//////////////////////////////////////////////////////////////////////////
	pSaveBuffer = (PBYTE)realloc (pSaveBuffer, 1) ;
	// Add the buffers
	
	waveInAddBuffer (hWaveIn, pWaveHdr1, sizeof (WAVEHDR)) ;
	waveInAddBuffer (hWaveIn, pWaveHdr2, sizeof (WAVEHDR)) ;
	
	// Begin sampling
	
	bRecording = TRUE ;
	bEnding = FALSE ;
	dwDataLength = 0 ;
	waveInStart (hWaveIn) ;


	
	
}

void CRecordHWndDlg::OnRecStop() 
{
	// TODO: Add your control notification handler code here
	TRACE("rec stop \n");
	bEnding=TRUE;
	//Sleep(1500);

	
	waveInReset(hWaveIn);



	
}




void CRecordHWndDlg::OnMM_WIM_OPEN(UINT wParam, LONG lParam) 
{
	// TODO: Add your message handler code here and/or call default
	((CWnd *)(this->GetDlgItem(IDC_REC_START)))->EnableWindow(FALSE);
	((CWnd *)(this->GetDlgItem(IDC_REC_STOP)))->EnableWindow(TRUE);
	((CWnd *)(this->GetDlgItem(IDC_PLAY_START)))->EnableWindow(FALSE);
	((CWnd *)(this->GetDlgItem(IDC_PLAY_PAUSE)))->EnableWindow(FALSE);
	((CWnd *)(this->GetDlgItem(IDC_PLAY_STOP)))->EnableWindow(FALSE);
	SetTimer(1,100,NULL);
	bRecording=TRUE;


//	TRACE("MM_WIM_OPEN\n");
	
	
}

void CRecordHWndDlg::OnMM_WIM_DATA(UINT wParam, LONG lParam) 
{
	// TODO: Add your message handler code here and/or call default
	// Reallocate save buffer memory
	
	//////////////////////////////////////////////////////////////////////////
	
	pNewBuffer = (PBYTE)realloc (pSaveBuffer, dwDataLength +
		((PWAVEHDR) lParam)->dwBytesRecorded) ;
	
	if (pNewBuffer == NULL)
	{
		waveInClose (hWaveIn) ;
		MessageBeep (MB_ICONEXCLAMATION) ;
		AfxMessageBox("erro memory");
		return ;
	}
	
	pSaveBuffer = pNewBuffer ;
	//////////////////////////////////////////////////////////////////////////
	
	CopyMemory (pSaveBuffer + dwDataLength, ((PWAVEHDR) lParam)->lpData,
		((PWAVEHDR) lParam)->dwBytesRecorded) ;
	
	dwDataLength += ((PWAVEHDR) lParam)->dwBytesRecorded ;
	
	if (bEnding)
	{
		waveInClose (hWaveIn) ;
		return ;
	}

	
	// Send out a new buffer
	
	waveInAddBuffer (hWaveIn, (PWAVEHDR) lParam, sizeof (WAVEHDR)) ;
	TRACE("done input data\n");
	return ;

	
}

void CRecordHWndDlg::OnMM_WIM_CLOSE(UINT wParam, LONG lParam) 
{
	// TODO: Add your message handler code here and/or call default
	KillTimer(1);
	TRACE("MM_WIM_CLOSE\n");
	if (0==dwDataLength) {
		return;
	}
	

	waveInUnprepareHeader (hWaveIn, pWaveHdr1, sizeof (WAVEHDR)) ;
	waveInUnprepareHeader (hWaveIn, pWaveHdr2, sizeof (WAVEHDR)) ;
	
	free (pBuffer1) ;
	free (pBuffer2) ;
	
	if (dwDataLength > 0)
	{
		//enable play
		((CWnd *)(this->GetDlgItem(IDC_REC_START)))->EnableWindow(TRUE);
		((CWnd *)(this->GetDlgItem(IDC_REC_STOP)))->EnableWindow(FALSE);
		((CWnd *)(this->GetDlgItem(IDC_PLAY_START)))->EnableWindow(TRUE);
		((CWnd *)(this->GetDlgItem(IDC_PLAY_PAUSE)))->EnableWindow(FALSE);
		((CWnd *)(this->GetDlgItem(IDC_PLAY_STOP)))->EnableWindow(FALSE);
	}
	bRecording = FALSE ;
	((CWnd *)(this->GetDlgItem(IDC_REC_START)))->EnableWindow(TRUE);
	((CWnd *)(this->GetDlgItem(IDC_REC_STOP)))->EnableWindow(FALSE);
	
	
	
	
	return ;
	
}


void CRecordHWndDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	
	// TODO: Add your message handler code here
	CDialog::OnClose();
	if (bRecording) {
		bTerminating=TRUE;
		bEnding=TRUE;
		waveInReset(hWaveIn);
		TRACE("waveInReset\n");
		Sleep(500);
		//return CWinThread::ExitInstance();
	}
	if (bPlaying) {
		bTerminating=TRUE;
		bEnding=TRUE;
		waveOutReset(hWaveOut);
		Sleep(500);
		//return CWinThread::ExitInstance();
	}
	free (pWaveHdr1) ;
	free (pWaveHdr2) ;
	free (pSaveBuffer) ;
	
}

void CRecordHWndDlg::OnPlayStart() 
{
	
	// TODO: Add your control notification handler code here
	if (bPlaying) {
		waveOutReset(hWaveOut);
	}

	//open waveform audio for output
	waveform.wFormatTag		=	WAVE_FORMAT_PCM;
	waveform.nChannels		=	1;
	waveform.nSamplesPerSec	=11025;
	waveform.nAvgBytesPerSec=11025;
	waveform.nBlockAlign	=1;
	waveform.wBitsPerSample	=8;
	waveform.cbSize			=0;
	
	
	if (waveOutOpen(&hWaveOut,WAVE_MAPPER,&waveform,(DWORD)this->m_hWnd,NULL,CALLBACK_WINDOW)) {
		MessageBeep(MB_ICONEXCLAMATION);
		AfxMessageBox("Audio output erro");
	}
	

	return ;
	
}

void CRecordHWndDlg::OnPlayPause() 
{
	// TODO: Add your control notification handler code here
	if (!bPlaying) {
		return;
	}
	if (!bPaused) {
		waveOutPause(hWaveOut);
		bPaused = TRUE;
	}
	else
	{
		waveOutRestart(hWaveOut);
		bPaused=FALSE;
	}	
	return ;
	
}

void CRecordHWndDlg::OnPlayStop() 
{
	// TODO: Add your control notification handler code here
	if (!bPlaying) {
		return ;
	}
	bEnding=TRUE;
	waveOutReset(hWaveOut);
	return ;

	
}


void CRecordHWndDlg::OnMM_WOM_OPEN(UINT wParam, LONG lParam){
	TRACE("open MM_WOM_OPEN\n");
	// Set up header
	
	pWaveHdr1->lpData          = (LPTSTR)pSaveBuffer ;
	pWaveHdr1->dwBufferLength  = dwDataLength ;
	pWaveHdr1->dwBytesRecorded = 0 ;
	pWaveHdr1->dwUser          = 0 ;
	pWaveHdr1->dwFlags         = WHDR_BEGINLOOP | WHDR_ENDLOOP ;
	pWaveHdr1->dwLoops         = dwRepetitions ;
	pWaveHdr1->lpNext          = NULL ;
	pWaveHdr1->reserved        = 0 ;
	
	// Prepare and write
	
	waveOutPrepareHeader (hWaveOut, pWaveHdr1, sizeof (WAVEHDR)) ;
	waveOutWrite (hWaveOut, pWaveHdr1, sizeof (WAVEHDR)) ;
	
	bEnding = FALSE ;
	bPlaying = TRUE ;
	
	((CWnd *)(this->GetDlgItem(IDC_REC_START)))->EnableWindow(TRUE);
	((CWnd *)(this->GetDlgItem(IDC_REC_STOP)))->EnableWindow(FALSE);
	((CWnd *)(this->GetDlgItem(IDC_PLAY_START)))->EnableWindow(FALSE);
	((CWnd *)(this->GetDlgItem(IDC_PLAY_PAUSE)))->EnableWindow(TRUE);
	((CWnd *)(this->GetDlgItem(IDC_PLAY_STOP)))->EnableWindow(TRUE);
	

	
	
}

void CRecordHWndDlg::OnMM_WOM_DONE(UINT wParam, LONG lParam){

	TRACE("open MM_WOM_DONE\n");
	waveOutUnprepareHeader (hWaveOut, pWaveHdr1, sizeof (WAVEHDR)) ;
	waveOutClose (hWaveOut) ;
	
	bPaused = FALSE ;
	dwRepetitions = 1 ;
	bPlaying = FALSE ;	
	
	return  ;
	
}
void CRecordHWndDlg::OnMM_WOM_CLOSE(UINT wParam, LONG lParam){
	TRACE("open MM_WOM_CLOSE\n");
	bPaused = FALSE ;
	dwRepetitions = 1 ;
	bPlaying = FALSE ;	

	((CWnd *)(this->GetDlgItem(IDC_REC_START)))->EnableWindow(TRUE);
	((CWnd *)(this->GetDlgItem(IDC_REC_STOP)))->EnableWindow(FALSE);
	((CWnd *)(this->GetDlgItem(IDC_PLAY_START)))->EnableWindow(TRUE);
	((CWnd *)(this->GetDlgItem(IDC_PLAY_PAUSE)))->EnableWindow(FALSE);
	((CWnd *)(this->GetDlgItem(IDC_PLAY_STOP)))->EnableWindow(FALSE);
	return ;
	
}

void CRecordHWndDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	
	CDialog::OnTimer(nIDEvent);
	MMTIME mmTime;
	mmTime.wType=TIME_MS;
	TCHAR time[20];
	switch(nIDEvent) {
	case 1:
	waveInGetPosition(hWaveIn,&mmTime,sizeof(MMTIME));
	itoa(mmTime.u.ms/10000,time,10);
	((CWnd *)GetDlgItem(IDC_STATIC))->SetWindowText(time);
	}
	return;
}
