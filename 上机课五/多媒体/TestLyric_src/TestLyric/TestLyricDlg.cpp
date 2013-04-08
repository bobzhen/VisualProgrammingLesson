// TestLyricDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "TestLyric.h"
#include "TestLyricDlg.h"
#include ".\testlyricdlg.h"

#define SLIDER_TIMER  11

#define MILLISECS_DIVIDE 10000L

const int MINIMUM_VOLUME=3000;

#define  WM_PENDING_STOP_PLAY  WM_USER+522


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTestLyricDlg 对话框

CTestLyricDlg::CTestLyricDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestLyricDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_iMainTime = 0;
	m_FilterGraph = NULL;
	m_SliderTimer = 0;
	m_FileTimeinNanos = 0;//文件播放总时间
}

void CTestLyricDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON2, m_TextColorNormal);
	DDX_Control(pDX, IDC_BUTTON3, m_TextHighlighted);
	DDX_Control(pDX, IDC_TIME_SLIDER, m_TimeSlider);
	DDX_Control(pDX, IDC_SLIDER_VOLUME, m_VolumeSlider);
}

BEGIN_MESSAGE_MAP(CTestLyricDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SIZE()
	ON_WM_TIMER()
	ON_WM_DROPFILES() //处理文件拖放消息
	ON_WM_HSCROLL()
	ON_WM_VSCROLL()
	ON_CBN_SELENDOK (IDC_COMBO_SCROLLMODE, OnSelectScrollMode)
	ON_BN_CLICKED(IDC_ADD_FILE, OnBnClickedAddFile)
	ON_BN_CLICKED(IDC_BUTTON_PLAY, OnButtonPlay)
	ON_BN_CLICKED(IDC_BUTTON_PAUSE, OnButtonPause)
	ON_BN_CLICKED(IDC_BUTTON_STOP, OnButtonStop)
	ON_MESSAGE(WM_GRAPHNOTIFY, OnGraphNotify)
	ON_MESSAGE(WM_PENDING_STOP_PLAY, OnPendingStopPlay)
	//}}AFX_MSG_MAP
	
	ON_BN_CLICKED(IDC_CHECK1, OnCheckFadeEffect)
END_MESSAGE_MAP()


// CTestLyricDlg 消息处理程序

BOOL CTestLyricDlg::OnInitDialog()
{

  	CDialog::OnInitDialog();

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

	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	CRect rc;
	GetWindowRect(&rc);
	 

	m_TimeSlider.SetRange(0, 1000);
	m_TimeSlider.SetPos(0);

	m_VolumeSlider.SetRange(0, MINIMUM_VOLUME, TRUE);

	DragAcceptFiles(TRUE); //接受文件拖放
    
	 BOOL ret = m_wndLyric.Create(this);
	 m_wndLyric.MoveWindow(200, 200, rc.Width(), 300);
	 m_wndLyric.ShowWindow(1);

	((CComboBox*)GetDlgItem(IDC_COMBO_AUDIO_FILE))->SetCurSel(0);

    ((CComboBox*)GetDlgItem(IDC_COMBO_SCROLLMODE))->AddString("垂直");
    ((CComboBox*)GetDlgItem(IDC_COMBO_SCROLLMODE))->AddString("水平");
	((CComboBox*)GetDlgItem(IDC_COMBO_SCROLLMODE))->SetCurSel(0);

	m_TextColorNormal.SetColor( RGB(125,158,192));
	m_TextHighlighted.SetColor( RGB(255,255,0) );

	return TRUE;  
}

void CTestLyricDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}


void CTestLyricDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作矩形中居中
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

//当用户拖动最小化窗口时系统调用此函数取得光标显示。
HCURSOR CTestLyricDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CTestLyricDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);
}


void CTestLyricDlg::OnSelectScrollMode()
{
  int nSel =  ((CComboBox*)GetDlgItem(IDC_COMBO_SCROLLMODE))->GetCurSel();
  if(nSel==0)//vertical
	  m_wndLyric.SetVerticalMode();
  else//horzional 
	  m_wndLyric.SetHorzionalMode();
 
}



BOOL CTestLyricDlg::OpenLyricFile(LPCSTR szFilePath)
{
  m_wndLyric.SetTextStateColor(m_TextColorNormal.GetColor(), m_TextHighlighted.GetColor());
  m_iMainTime = 0;

  BOOL bSuccess = FALSE;

  	WIN32_FIND_DATA fd;
	CString szPath = szFilePath;

	HANDLE hFind=FindFirstFile(szPath,&fd);


	if( hFind!=INVALID_HANDLE_VALUE )
	{
		if( szPath.Right(4) == ".lrc")
		{
		   bSuccess = TRUE;
		}	
	}
	
	if(hFind!=INVALID_HANDLE_VALUE)
		FindClose(hFind);

  if(bSuccess)
  { 
	 //读取歌词文件内容
	m_wndLyric.ReadFile(szPath);

  }
   
  return bSuccess;
}

//拖放文件消息响应
void CTestLyricDlg::OnDropFiles(HDROP hDropInfo )
{
	unsigned int cFile = 0, i = 0;
	CHAR szFileNname[MAX_PATH] = {'\0'};
	cFile = ::DragQueryFile( hDropInfo, 0xFFFFFFFF, NULL, MAX_PATH );
	for(i = 0; i < cFile; i++)
	{
		DWORD fileAttrib = 0x0;
		::DragQueryFile( hDropInfo, i, szFileNname, MAX_PATH );
		fileAttrib = GetFileAttributes(szFileNname);
		if (0x10 == (fileAttrib & FILE_ATTRIBUTE_DIRECTORY))
		{  // folder


		}
		else
		{   //file
			CString strFileType;
			CString strFilePath = szFileNname;
			strFilePath.MakeLower();
			strFileType = strFilePath.Mid(strFilePath.ReverseFind('.'));
			if(strFileType.Find(".wma")!=-1
				||strFileType.Find(".mp3")!=-1 
				|| strFileType.Find(".wav")!= -1)
			{
						
				  m_SourceFile = strFilePath;
		
				  //向ComboBox添加歌曲文件路径，并选择该歌曲
			      int index = ((CComboBox*)GetDlgItem(IDC_COMBO_AUDIO_FILE))->AddString(m_SourceFile);
		          ((CComboBox*)GetDlgItem(IDC_COMBO_AUDIO_FILE))->SetCurSel(index);

			}
			else
			{

				::MessageBox(NULL,_T("不支持该文件格式播放"),_T("提示"),MB_OK|MB_ICONINFORMATION);
			}
		}
	}
}

//向Combo中添加歌曲文件路径，并更新当前文件路径m_SourceFile为最新插入的项
void CTestLyricDlg::OnBnClickedAddFile()
{
	CString    strFilter = "";
	strFilter += "Audio File (*.mp3;*.wma;*.wav)|*.mp3;*.wma;*.wav|";
	strFilter += "All Files (*.*)|*.*|";

	CFileDialog dlgOpen(TRUE, NULL, NULL, OFN_PATHMUSTEXIST | OFN_HIDEREADONLY, strFilter, this);
	if (IDOK == dlgOpen.DoModal()) 
	{
		m_SourceFile = dlgOpen.GetPathName();

		  //向ComboBox添加歌曲文件路径，并选择该歌曲
		int index = ((CComboBox*)GetDlgItem(IDC_COMBO_AUDIO_FILE))->AddString(m_SourceFile);
		((CComboBox*)GetDlgItem(IDC_COMBO_AUDIO_FILE))->SetCurSel(index);
	}
}


void CTestLyricDlg::OnButtonPlay() 
{
	if(m_FilterGraph == NULL)
	{
	
		//获取歌曲文件路径
		CString szFileName;
		((CComboBox*)GetDlgItem(IDC_COMBO_AUDIO_FILE))->GetWindowText(szFileName);

			
		m_SourceFile = szFileName;

		if(m_SourceFile.IsEmpty())
		{
              MessageBox("你选择的文件路径为空！", "提示", MB_OK|MB_ICONWARNING);
			  return;
		}

	    //重建Directshow Graph
		 if(!CreateGraph())
		 {
            TRACE("CreateGraph() failed! \n");

			DestroyGraph();
		    m_FilterGraph = NULL;
			return;
		 }

		 	  
		 //获得文件播放时间长度
	     m_FilterGraph->GetDuration(&m_FileTimeinNanos);

		 TRACE("File duration: %ld ms\n", m_FileTimeinNanos/MILLISECS_DIVIDE);

		 long volume = m_FilterGraph->GetAudioVolume();

		 m_VolumeSlider.SetPos(volume);

		 /////////////////////////////////////////////////////

		CString strLyricFile;

		//根据歌曲文件名确定歌词文件名(歌词文件必须与歌曲文件位于同一目录)
		int pos = 0;
		if( (pos = szFileName.ReverseFind('.')) != -1)
		{
			 strLyricFile = szFileName.Left(pos);
			strLyricFile += ".lrc";
		} 
		else
		{
			return;
		}
        
		//在歌曲文件的目录下找歌词文件
		if(!OpenLyricFile(strLyricFile))
		{
           if(IDOK != MessageBox("歌词文件不存在，你仍然要播放该音乐文件吗？", "提示", MB_OK|MB_ICONWARNING))
		   {
			   m_wndLyric.Stop();
		       m_wndLyric.ClearLyrics();
			   return;
		   }
		   m_wndLyric.Stop();
		   m_wndLyric.ClearLyrics();
		}


	}

     //开始播放歌词
	 m_wndLyric.Start();



	//开始播放音乐
	if (m_FilterGraph)
	{
		m_FilterGraph->Run();
		//开启定时器
		if (m_SliderTimer == 0)
		{
			m_SliderTimer = SetTimer(SLIDER_TIMER, 100, NULL);
		}
	}
	
}

//暂停播放
void CTestLyricDlg::OnButtonPause() 
{
	if (m_FilterGraph)
	{
		m_FilterGraph->Pause();
		// Start a timer
		if (m_SliderTimer == 0)
		{
			m_SliderTimer = SetTimer(SLIDER_TIMER, 100, NULL);
		}
	}
}

//停止播放
void CTestLyricDlg::OnButtonStop() 
{
	if (m_FilterGraph)
	{
		m_FilterGraph->SetCurrentPosition(0);
		m_FilterGraph->Stop();

	    //停止定时器
		if (m_SliderTimer)
		{
			KillTimer(m_SliderTimer);
			m_SliderTimer = 0;
		}

		DestroyGraph();
		m_FilterGraph = NULL;
	}
	m_TimeSlider.SetPos(0);
}



BOOL CTestLyricDlg::CreateGraph(void)
{
	//先释放已创建的Filter Graph
	DestroyGraph();

	m_FilterGraph = new CDXGraph();
	if (m_FilterGraph->Create())
	{
		// 构建解码该文件的Directshow Filter Graph(使用智能连接方式)
		
		bool bSuccess = m_FilterGraph->RenderFile(m_SourceFile);
        if(!bSuccess)
			return FALSE;

		// Set video window and notification window
		//m_FilterGraph->SetDisplayWindow(mVideoWindow.GetSafeHwnd());
		
		m_FilterGraph->SetNotifyWindow(this->GetSafeHwnd());

		m_FilterGraph->Pause();

		return bSuccess;
	}
	return FALSE;
}

void CTestLyricDlg::DestroyGraph(void)
{
	if (m_FilterGraph)
	{
	
		m_FilterGraph->Stop();
		m_FilterGraph->SetNotifyWindow(NULL);

		delete m_FilterGraph;
		m_FilterGraph = NULL;
	}
}

//处理水平滑动条的拖动和点击消息
void CTestLyricDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
    if(nSBCode == SB_ENDSCROLL)  // 忽略 End scroll消息.
	  return;

	if (pScrollBar->GetSafeHwnd() == m_TimeSlider.GetSafeHwnd())
	{
		if (m_FilterGraph)
		{
			// 计算跳播的时间位置
			LONGLONG duration = 0;
			m_FilterGraph->GetDuration(&duration);
			LONGLONG pos = duration * m_TimeSlider.GetPos() / 1000;
			m_FilterGraph->SetCurrentPosition(pos);
		}		
	}

	else
	{
		CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
	}
}

void CTestLyricDlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
    if(nSBCode == SB_ENDSCROLL)  // 忽略 End scroll
	  return;

	if(pScrollBar->GetSafeHwnd() == m_VolumeSlider.GetSafeHwnd())
	{
	   if(m_FilterGraph)
	   {
		int nPosition = m_VolumeSlider.GetPos();
		int lVolume = -1 * nPosition;
			
		m_FilterGraph->SetAudioVolume(lVolume);
	   }
	}
	else
	{
		CDialog::OnVScroll(nSBCode, nPos, pScrollBar);
	}
}

// Deal with the graph events 
LRESULT CTestLyricDlg::OnGraphNotify(WPARAM inWParam, LPARAM inLParam)
{
	IMediaEventEx * pEvent = NULL;
	if (m_FilterGraph && (pEvent = m_FilterGraph->GetEventHandle()))
	{
		LONG   eventCode = 0, eventParam1 = 0, eventParam2 = 0;
		while (SUCCEEDED(pEvent->GetEvent(&eventCode, &eventParam1, &eventParam2, 0)))
		{ 
			// Spin through the events
			pEvent->FreeEventParams(eventCode, eventParam1, eventParam2);
			switch (eventCode)
			{
			case EC_COMPLETE:
				PostMessage(WM_PENDING_STOP_PLAY, 0, 0);
				break;
			case EC_USERABORT:
			case EC_ERRORABORT:
                PostMessage(WM_PENDING_STOP_PLAY, 0, 0);
				break;

			default:
				break;
			}
		}
	}
	return 0;
}

LRESULT CTestLyricDlg::OnPendingStopPlay(WPARAM wparam, LPARAM lparam)
{
	OnButtonStop();
   return 0;
}

void CTestLyricDlg::OnTimer(UINT nIDEvent) 
{
	if (nIDEvent == m_SliderTimer && m_FilterGraph)
	{
		LONGLONG pos = 0, duration = m_FileTimeinNanos;

		m_FilterGraph->GetCurrentPosition(&pos);
		//m_FilterGraph->GetDuration(&duration);

		// 获得播放新位置，并且更新进度条
		int newPos = int(pos * 1000 / duration);
		if (m_TimeSlider.GetPos() != newPos)
		{
			m_TimeSlider.SetPos(newPos);
		}

		long ms = pos / (MILLISECS_DIVIDE);
		//更新歌词当前时间
		m_iMainTime = ms;
	}

	CDialog::OnTimer(nIDEvent);
}

//返回时间单位为ms
int CTestLyricDlg::GetCurrentTime()
{
   return m_iMainTime;
}

//返回时间单位为ms
int CTestLyricDlg::GetSongTotalTime()
{
  int ms = m_FileTimeinNanos/ (MILLISECS_DIVIDE);
  return ms;
}

void CTestLyricDlg::OnCheckFadeEffect()
{
	if(((CButton*)GetDlgItem(IDC_CHECK1))->GetState() & 1)
		m_wndLyric.SetFadeIn(TRUE);
	else
		m_wndLyric.SetFadeIn(FALSE);
}
