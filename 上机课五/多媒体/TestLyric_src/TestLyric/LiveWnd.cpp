// LiveWnd.cpp : 实现文件
//

#include "stdafx.h"
#include "TestLyric.h"
#include "TestLyricDlg.h"
#include "LiveWnd.h"
#include <algorithm>
#include ".\livewnd.h"


#define MAX_WHEEL_DELTA 120*2

IMPLEMENT_DYNAMIC(CLiveWnd, CWnd)
CLiveWnd::CLiveWnd()
{
	m_iCurrent = -1;
	m_iTimeInterval = 100;//100ms
	m_nTextHeight   = 20;
	m_nTextSpace    = 5;
	m_iTextOutY     = 0;
	m_iTextOutX     = 0;
	m_iStartedPos   = 0;
    m_iScrollTotal  = 0;
    m_iMouseWheelTotal = 0;
	m_bVertical   = TRUE;
	m_bFadeEffect = FALSE; //淡入淡出
}

CLiveWnd::~CLiveWnd()
{
}


BEGIN_MESSAGE_MAP(CLiveWnd, CWnd)
	ON_WM_CREATE()
	ON_WM_TIMER()
	ON_WM_PAINT()
	ON_WM_DESTROY()
	ON_WM_SIZE()
	ON_WM_ERASEBKGND()
	ON_WM_MOUSEWHEEL()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()


/*
float StrToSS(LPCSTR lpszTag)
{
 CString strSS(lpszTag);
 int pos;
 if( (pos=strSS.Find(':'))!=-1){
	 CString szMM = strSS.Left(pos);
	 CString szSS = strSS.Mid(pos+1);
	 int   m = atoi(szMM.GetBuffer(0));
	 float s = atof(szSS.GetBuffer(0));
	 szMM.ReleaseBuffer();
	 szSS.ReleaseBuffer();
     return 60*m + s;
 }else{
   return 0.0;
 }
}
*/

//将字符串的时间转化为以秒为单位的浮点值
float StrToSS(LPCSTR lpszTag)
{
	int paramNums = 0;
	int minutes;
	float seconds;
	paramNums = _stscanf(lpszTag, _T("%d:%f"), &minutes, &seconds);
	if(paramNums != 2)
	{
		//ASSERT(0);
		return 1000000.f;
	}
	return 60*minutes + seconds;
}

//将标签按时间排序
int CompareTime(TIMETAG& tag1, TIMETAG& tag2)
{
	if(tag1.timeValue > tag2.timeValue)
		return 0;
	else
		return 1;

}

BOOL CLiveWnd::Create(CWnd* parent)
{
	CString strWndClass=AfxRegisterWndClass(0,::LoadCursor(AfxGetInstanceHandle(),IDC_ARROW),GetSysColorBrush(COLOR_WINDOW),NULL);
	m_pParent = parent;

    BOOL ret;
	ret = 	CreateEx(WS_EX_TOOLWINDOW, strWndClass, NULL,WS_POPUP|WS_OVERLAPPED|WS_CAPTION|WS_THICKFRAME,	CRect(50,50,150,200), this, NULL);
	return ret;
}

int CLiveWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	Initialize();
 
	//Start();
	return 0;
}

void CLiveWnd::OnDestroy()
{
	CWnd::OnDestroy();
	if(m_dcWinDC)
	  ::ReleaseDC(m_hWnd,m_dcWinDC);
}

BOOL CLiveWnd::Start( )
{
	KillTimer(3);

	m_iMouseWheelTotal = 0;

	if( SetTimer( 3, m_iTimeInterval,NULL) == 0 )
		return false;

	if( !TextToScreen() )
		return false;

	return true;
}

	
void CLiveWnd::Stop()
{
  KillTimer(3);
}

	
void CLiveWnd::ClearLyrics()
{
  m_vTimeTags.clear();
  m_vWords.clear();
  InvalidateRect(NULL);
}

BOOL CLiveWnd::Initialize( )
{
	Cleanup();

	CRect rc;
	GetClientRect(&rc);
	m_iDrawWidth  = rc.Width();    
	m_iDrawHeight = rc.Height();  

	m_rectangle.SetRect(0, 0, m_iDrawWidth,m_iDrawHeight);


	m_clrForeground   = RGB(0,130,198);//GetSysColor(COLOR_WINDOWTEXT);
	m_clrBackground   = RGB(0,0,0);
	
	m_dcWinDC    =  ::GetDC(m_hWnd);
	m_dcMemoryDC =  CreateCompatibleDC( m_dcWinDC );

	if( m_dcMemoryDC == NULL )
		return false;

	m_hMemoryBitmap = CreateCompatibleBitmap( m_dcWinDC, m_iDrawWidth, m_iDrawHeight );

	if( m_hMemoryBitmap == NULL )
		return false;	

	SetTextColor( m_dcMemoryDC, m_clrForeground );
	SetBkColor( m_dcMemoryDC, m_clrBackground );

	SelectObject( m_dcMemoryDC, m_hMemoryBitmap );

	m_hBrushBackground = CreateSolidBrush( m_clrBackground );

	//m_hFont = CreateFont(0,0,0,0,FW_NORMAL,0,0,0,DEFAULT_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH, "Fixedsys");
    LOGFONT logFont={sizeof(logFont)};
	logFont.lfCharSet=134;
	logFont.lfWidth=6;
	logFont.lfHeight=12;
	logFont.lfWeight=10;
	lstrcpy(logFont.lfFaceName,"宋体");
	m_hFont = ::CreateFontIndirect(&logFont);

	SelectObject( m_dcMemoryDC, m_hFont );

	return true;
}

BOOL CLiveWnd::ReadFile(LPCSTR lpszFile)
{
  CStdioFile file;
  if( !file.Open(lpszFile, CFile::modeRead) )
	  return FALSE;

 m_vTimeTags.clear();
 m_vWords.clear();

  CString line;
  int i = 0;
  while( file.ReadString(line)!= FALSE ) //读取每行字符串
  {
     //TRACE("%s\n", line);
	  if(!line.IsEmpty())//不是空行
	  {
		  //解析每一行
	      if(SpliceLine(line, i))
		  {
		    i++;
		  }
	  }
      line.Empty();
	 
   }
  file.Close();

  //最后增加一个无歌词的空行
  m_vWords.push_back("");
  TIMETAG tm;
  tm.lineNum = m_vWords.size()-1;
  tm.timeValue = ((CTestLyricDlg*)AfxGetMainWnd())->GetSongTotalTime(); //时间值为文件的总时间长度
  m_vTimeTags.push_back(tm);
  
  Sort();

  TRACE("TimeTag Count: %d, Word Count: %d \n", m_vTimeTags.size(), m_vWords.size());


   SetHorzData();

  return TRUE;
}

void CLiveWnd::AddTimeTag(LPCSTR lpszTag, int Number)
{
 TIMETAG tag;
 tag.lineNum   = Number;
 tag.timeValue = StrToSS(lpszTag);
 m_vTimeTags.push_back(tag);
 
 //TRACE( "%f\n", tag.timeValue*1000 );
}


void CLiveWnd::AddWord(LPCSTR lpszWord)
{
	m_vWords.push_back(lpszWord);
//	TRACE("%s\n", lpszWord);
}

//函数作用：切分一行歌词成多个带时间标签的歌词(一行歌词可以包含多个时间标签),重唱的歌词需要分配一个独立的时间标签；
// 时间标签存储在数组m_vTimeTags里, 每句歌词存储在数组m_vWords里，两个数组通过lineNumber做映射；
// 如果一行中有多个时间标签，表示这句歌词在几个不同时间里被重唱，m_vTimeTags里的多个时间标签可以对应m_vWords的相同的歌词内容
// 如果成功添加一行歌词（不包括带说明意义的标签），返回TRUE，否则返回FALSE
BOOL CLiveWnd::SpliceLine( LPCSTR lpsz, int lineNumber)
{
  CString str(lpsz);
  CString sz_time_tag;
  CString strHead;

   str.TrimLeft();
   str.TrimRight();

  int pos, pos2;
  pos = str.Find("[");
  if(pos == -1)
	  return FALSE;

  bool bAddStr = true;

  while(pos !=-1 )
  {

    str = str.Mid(pos+1);
    pos = str.Find("]");
	if(pos!=-1)
	{
	   if(lineNumber<5)
	   {
		   if( (pos2 = str.Find(":")) != -1)
		   {
			   strHead = str.Left(pos2);

				if( strHead== "ti" || strHead== "ar" || strHead=="by" || strHead=="al" || strHead == "offset" )
				{
					str = str.Left(str.GetLength()-1);
					bAddStr = false;
					break;
				}
		    }  
	   }
	    AddTimeTag(str.Left(pos),lineNumber);
        str = str.Mid(pos+1);
	}
	else
	{
		bAddStr = false;
		return bAddStr;
	}
	  
	pos = str.Find("[");

 }//while


  if(bAddStr)
  {
	str.TrimLeft();
    str.TrimRight();
    AddWord(str);
  }

  //TRACE("%d, %d \n", m_vTimeTags.size(), m_vWords.size());
  
  return bAddStr;
}

//计算水平滚动模式下每句歌词显示到窗口中的横向坐标
void CLiveWnd::SetHorzData()
{
  CString text;
  int nPre = 0;

  for(int i = 0; i<m_vTimeTags.size(); i++)
  {
   int len;
   int width;
   int iWordIndex = m_vTimeTags[i].lineNum;
   text = m_vWords[iWordIndex];
   len = text.GetLength();

   m_vTimeTags[i].dd = nPre;
   
   if(len==0)
       width = m_nTextSpace;
   else{
	   RECT rcText = {0,0,0,0};
       int textH = DrawTextEx( m_dcMemoryDC, text.GetBuffer(0), len, &rcText, DT_CALCRECT, 0 );
	   ASSERT( textH>0 && (rcText.right-rcText.left)>0 );
       width = rcText.right-rcText.left;
      }
    nPre += (width + m_nTextSpace);
  }
//  if(nPre>0)
//  	m_vTimeTags[m_vTimeTags.size()-1] = nPre;
}

void CLiveWnd::Sort()
{
  //使用stl排序算法
  sort(m_vTimeTags.begin(),m_vTimeTags.end(), CompareTime);
 // std::vector<TIMETAG>::iterator it;
  //for(it=m_vTimeTags.begin(); it!=m_vTimeTags.end();it++)
  //{
  // TRACE("%f,%d\n", (*it).timeValue, (*it).lineNum);
  //}
}




int CLiveWnd::GetX(int i)
{
 return m_iTextOutX + GetHorzLen(i);
}

int CLiveWnd::GetY(int i)
{
 return m_iTextOutY + i*m_nTextHeight;
}

int CLiveWnd::GetPlayPos()
{
  CTestLyricDlg* pDlg = (CTestLyricDlg*)m_pParent;
  return ((CTestLyricDlg*)m_pParent)->GetCurrentTime() + m_iMouseWheelTotal;
}


int CLiveWnd::GetHorzLen(int lineNumber)
{
  return m_vTimeTags[lineNumber].dd;
}

int CLiveWnd::GetHorzTextW(int Index)
{
  return GetHorzLen(Index+1) - GetHorzLen(Index);
}

LPCSTR CLiveWnd::GetString(int lineNumber)
{
 int number = m_vTimeTags[lineNumber].lineNum;
 ASSERT(number>=0 && number<m_vWords.size() );
 return m_vWords[number];
}

float CLiveWnd::GetTimeValue(int lineNumber)
{
	return (1000*m_vTimeTags[lineNumber].timeValue);
}

int CLiveWnd::GetLineCount()
{
  return m_vTimeTags.size();
}


void CLiveWnd::ResetParam()
{
	m_iCurrent = -1;
	m_nTextHeight   = 30;
	m_iTextOutY = 0;
	m_iTextOutX = 0;
	m_iStartedPos     = 0;
    m_iScrollTotal    = 0;
	m_iMouseWheelTotal = 0;
	m_rectangle.SetRect(0,0,0,0);
}

void CLiveWnd::Cleanup( void )
{
	DeleteObject( m_hMemoryBitmap );
	DeleteDC( m_dcMemoryDC );
	DeleteObject( m_hBrushBackground );
	DeleteObject( m_hFont );
}

void CLiveWnd::OnPaint()
{
	CPaintDC dc(this); 
    //TextToScreen();
	BitBlt( m_dcWinDC, 0, 0, m_iDrawWidth, m_iDrawHeight, m_dcMemoryDC, 0, 0, SRCCOPY );
}



void CLiveWnd::OnSize(UINT nType, int cx, int cy)
{
	CWnd::OnSize(nType, cx, cy);

	if(cx>0)
		m_iDrawWidth = cx;
	if(cy>0)
		m_iDrawHeight = cy;

	UpdateDC();

	TextToScreen();
	Invalidate();
}

void CLiveWnd::UpdateDC()
{
 	Cleanup();

	m_dcMemoryDC = CreateCompatibleDC( m_dcWinDC );

	if( m_dcMemoryDC == NULL )
		return ;

	m_hMemoryBitmap = CreateCompatibleBitmap( m_dcWinDC, m_iDrawWidth, m_iDrawHeight );

	if( m_hMemoryBitmap == NULL )
		return ;	

	SetTextColor( m_dcMemoryDC, m_clrForeground );
	SetBkColor( m_dcMemoryDC, m_clrBackground );

	SelectObject( m_dcMemoryDC, m_hMemoryBitmap );

	m_hBrushBackground = CreateSolidBrush( m_clrBackground );

//	m_hFont = CreateFont( 0,0,0,0,FW_NORMAL,0,0,0,DEFAULT_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH, "Fixedsys");
     LOGFONT logFont={sizeof(logFont)};
	logFont.lfCharSet=134;
	logFont.lfWidth=6;
	logFont.lfHeight=12;
	logFont.lfWeight=10;
	lstrcpy(logFont.lfFaceName,"宋体");
	m_hFont = ::CreateFontIndirect(&logFont);

	SelectObject( m_dcMemoryDC, m_hFont );

	m_rectangle.left   = 0;
	m_rectangle.top    = 0;
	m_rectangle.right  = m_iDrawWidth;
	m_rectangle.bottom = m_iDrawHeight;

}



BOOL CLiveWnd::OnEraseBkgnd(CDC* pDC)
{
	return TRUE;
}

void CLiveWnd::Backwards(int MiniSeconds)
{
 m_iMouseWheelTotal-=MiniSeconds;
}

void CLiveWnd::Forwards(int MiniSeconds)
{
 m_iMouseWheelTotal+=MiniSeconds;
}

void CLiveWnd::SetHorzionalMode()
{
   m_bVertical  = FALSE;
   m_iTextOutX = 0;

}

void CLiveWnd::SetVerticalMode()
{
	m_bVertical = TRUE;
	m_iTextOutY = 0;
}


void CLiveWnd::SetTextStateColor(COLORREF clrNormal, COLORREF clrHighlighted)
{
 m_clrForeground  = clrNormal;
 m_clrTextHighlighted = clrHighlighted;
}


void CLiveWnd::OnTimer(UINT nIDEvent)
{
	CWnd::OnTimer(nIDEvent);

	int CurrentTime = GetPlayPos();
	m_iTime = CurrentTime;

	int CurrentCentHeight = m_iDrawHeight/2 + m_nTextHeight;
    int CurrentCentWidth  = m_iDrawWidth/2  + m_nTextSpace;

	int i,lc,TY,TX;
	for(i = 0; i<= GetLineCount()-1; i++)
	{
      if(GetTimeValue(i) > CurrentTime ) break;
	}

	if(m_bVertical)
	{ 
	   if ( i >= 1 && i < GetLineCount() )
	   {
         lc = m_nTextHeight * (CurrentTime - GetTimeValue(i-1) ) / (GetTimeValue(i-1) - GetTimeValue(i));
		 CurrentCentHeight = lc + CurrentCentHeight;//当前高亮行的Y坐标
		 TY = CurrentCentHeight - (i - 1) * m_nTextHeight;   
	    }
	    else
	    {
         TY =  CurrentCentHeight - m_nTextHeight;
	    }

	   m_iCurrent = i-1;
	   
	   if( abs(m_iTextOutY-TY)>1 )
	   {
	    m_iTextOutY = TY;
        TextToScreen();
		InvalidateRect(m_rectangle, 0 );
        }
	 }//if
   
	else  //水平滚动
	{
         if ( i >= 1 && i < GetLineCount() )
		 {
			 int len = GetHorzTextW(i-1);
			// TRACE("%d,TextLen:%d,CurrentTime:%d\n",i-1, len,CurrentTime/1000);

		    lc = (GetHorzTextW(i-1))*(CurrentTime - GetTimeValue(i-1) ) / (GetTimeValue(i-1) - GetTimeValue(i));
		    CurrentCentWidth = lc + CurrentCentWidth;
	
           // int xx = GetHorzLen(i-1);
			TX = CurrentCentWidth - GetHorzLen(i-1); 
		 }
		 else
	     {
            TX =  CurrentCentWidth + m_nTextSpace;
	     }

	   m_iCurrent = i-1;
      
	   if(abs(m_iTextOutX- TX)>1)
	   {
		m_iTextOutX = TX;
        TextToScreen();
		InvalidateRect(m_rectangle, 0 );
        }	 
	}//else
    
	
//	UpdateWindow();
}


BOOL CLiveWnd::TextToScreen( void )
{
	DWORD dwRead = 0;
	
	FillRect( m_dcMemoryDC, &m_rectangle, m_hBrushBackground );
    SetBkMode(m_dcMemoryDC, TRANSPARENT);

	CRect rcLine;
	CString strWord;

	if(m_bVertical)   //垂直滚动
	{
	  for(int i = 0; i<GetLineCount(); i++)
	  {
		
		int y = GetY(i);
		if(y<-m_nTextHeight) continue;
		if(y>m_iDrawHeight)  break;

		rcLine.SetRect(0, y, m_iDrawWidth, y+m_nTextHeight);
		strWord = GetString(i);

		COLORREF cLeft,cRight,color;

		if(m_iCurrent-1 == i && i>=0 )
		{
			float iOnBand = m_iTime - GetTimeValue(m_iCurrent);
			float iDelta  = (GetTimeValue(m_iCurrent+1) - GetTimeValue(m_iCurrent))/2; //取相邻两个时间标签的时间间隔的一半为过渡时间

			if(m_bFadeEffect && iOnBand<iDelta) //淡出
			{
				cLeft  = m_clrTextHighlighted;
				cRight = m_clrForeground;
     			color = RGB((GetRValue(cRight)-GetRValue(cLeft))*((float)iOnBand)/iDelta +GetRValue(cLeft),
						(GetGValue(cRight)-GetGValue(cLeft))*((float)iOnBand)/iDelta +GetGValue(cLeft),
						(GetBValue(cRight)-GetBValue(cLeft))*((float)iOnBand)/iDelta +GetBValue(cLeft));
		
		        ::SetTextColor(m_dcMemoryDC, color);
			}
			else
			{
				::SetTextColor(m_dcMemoryDC, m_clrForeground);
			}
		}

		else if(m_iCurrent== i )
		{
		  
			float iOnBand = m_iTime - GetTimeValue(m_iCurrent);
			float iDelta  = ( GetTimeValue(m_iCurrent+1) - GetTimeValue(m_iCurrent) )/2; //取相邻两个时间标签的时间间隔的一半为过渡时间


			if(m_bFadeEffect && iOnBand<iDelta) //淡入
			{
				cLeft  = m_clrForeground;
				cRight = m_clrTextHighlighted;
     			color = RGB((GetRValue(cRight)-GetRValue(cLeft))*((float)iOnBand)/iDelta +GetRValue(cLeft),
						(GetGValue(cRight)-GetGValue(cLeft))*((float)iOnBand)/iDelta +GetGValue(cLeft),
						(GetBValue(cRight)-GetBValue(cLeft))*((float)iOnBand)/iDelta +GetBValue(cLeft));
		
		        ::SetTextColor(m_dcMemoryDC, color);
			}
			else
			{
				::SetTextColor(m_dcMemoryDC, m_clrTextHighlighted);
			}
		}
		
		else
		{
			 ::SetTextColor(m_dcMemoryDC, m_clrForeground);
		}

		DrawTextEx( m_dcMemoryDC, strWord.GetBuffer(0), strWord.GetLength(), &rcLine, DT_CENTER, 0 ); //居中显示
		strWord.ReleaseBuffer();
	  }//for

	}

	//水平滚动
	else
	{
      for(int i = 0; i<GetLineCount(); i++)
	  {
		int x = GetX(i);
		int w = GetHorzTextW(i);
		if(x<-w)               continue;
		if(x>m_iDrawWidth)     break;

		rcLine.SetRect(x, 0, x+w, m_iDrawHeight);
		strWord = GetString(i);

	 	COLORREF cLeft,cRight,color;

		if(m_iCurrent-1 == i && i>=0 )
		{
			float iOnBand = m_iTime - GetTimeValue(i+1);
			float iDelta  = 1000;

			if(m_bFadeEffect && iOnBand<iDelta)
			{
			cLeft  = m_clrTextHighlighted;
			cRight = m_clrForeground;
     	    color = RGB((GetRValue(cRight)-GetRValue(cLeft))*((float)iOnBand)/iDelta +GetRValue(cLeft),
			         (GetGValue(cRight)-GetGValue(cLeft))*((float)iOnBand)/iDelta +GetGValue(cLeft),
			         (GetBValue(cRight)-GetBValue(cLeft))*((float)iOnBand)/iDelta +GetBValue(cLeft));
			
			::SetTextColor(m_dcMemoryDC, color);
			}
			else
			{
				::SetTextColor(m_dcMemoryDC, m_clrForeground);
			}
		   
		}

		else if(m_iCurrent== i )
		{
		   ::SetTextColor(m_dcMemoryDC, m_clrTextHighlighted);
		}
		
		else
		{
			::SetTextColor(m_dcMemoryDC, m_clrForeground);
		}

	   DrawTextEx( m_dcMemoryDC, strWord.GetBuffer(0), strWord.GetLength(), &rcLine, 
		       DT_LEFT|DT_VCENTER|DT_SINGLELINE, 0 ); //左对齐显示
	   strWord.ReleaseBuffer();
	  }//for
	}

	return true;
}


BOOL CLiveWnd::OnMouseWheel( UINT nFlags, short zDelta, CPoint pt )
{
 
  //TRACE("delta is:%d\n",zDelta);
  static int nWheelDelta = 0;

  nWheelDelta+=zDelta;
  if(nWheelDelta >= MAX_WHEEL_DELTA || nWheelDelta<=-MAX_WHEEL_DELTA)
  {
   if(nWheelDelta<0)
	   Backwards(500);
   else
	   Forwards(500);

      nWheelDelta = 0;
  }
  return TRUE;
}


void CLiveWnd::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if(nChar == VK_UP)
	{
		 Forwards(500);
	}
	if(nChar == VK_DOWN)
	{
		 Backwards(500);
	}

	CWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}
