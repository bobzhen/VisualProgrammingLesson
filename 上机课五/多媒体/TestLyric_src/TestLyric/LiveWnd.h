#pragma once

#include <vector>

using namespace std;

typedef struct tagTime{
  int     lineNum;
  float   timeValue;
  int     dd;//横向距离(用于水平滚动模式)
}TIMETAG;

float StrToSS(LPCSTR lpszTag);
int   CompareTime(TIMETAG& tag1, TIMETAG& tag2);
// CLiveWnd

#define   WM_NOTIFY_LYRIC   WM_USER + 1265

class CLiveWnd : public CWnd
{
	DECLARE_DYNAMIC(CLiveWnd)

public:
	CLiveWnd();
	virtual ~CLiveWnd();


public: 

	BOOL    Create(CWnd* parent);
	BOOL    Initialize(); //创建GDI资源
	void    Cleanup();  //释放GDI资源
	BOOL    TextToScreen( void ); //画歌词到窗口中
	BOOL    Start();//开启定时器
	void    Stop(); //停止定时器
	void    ClearLyrics(); //清理歌词内容
    void    ResetParam();
	void    UpdateDC(); //窗口大小改变时重建相关的GDI资源

    inline  int     GetLineCount(); //获得所有歌词的行数（包括重复唱的）
	inline  float   GetTimeValue(int lineNumber); //获得某行歌词的时间标签

	void     SetFadeIn(BOOL flag) { m_bFadeEffect = flag; }
    
    
	int     GetX(int); //获得某行歌词相对窗口左上角的横坐标
	int     GetY(int); //获得某行歌词相对窗口左上角的纵坐标
	int     GetPlayPos(); //获取当前播放的时间点
	int     GetHorzLen(int Index); //获得某行歌词显示的横坐标
	int     GetHorzTextW(int Index); //获得某行歌词的显示宽度
	void    SetHorzData(); //计算水平滚动模式下每句歌词显示到窗口中的横坐标
	void    Sort(); //将所有歌词按时间标签排序
    void    DrawHighlightedLine(int); //画高亮的一行
	void    AddTimeTag(LPCSTR lpszTag, int lineNumber); //添加一个新的时间标签到数组
    void    AddWord(LPCSTR lpszWord); //添加新的一句歌词到数组中
	void    SetHorzionalMode(); //水平滚动模式
	void    SetVerticalMode(); //垂直滚动模式
    void    SetTextStateColor(COLORREF clrNormal, COLORREF clrHighlighted); //设置歌词字体背景和高亮颜色
	void    Forwards(int millisecond);//前进
	void    Backwards(int millisecond);//后退
    BOOL    ReadFile(LPCSTR lpszFile); //读取歌词文件(.lrc)
	BOOL    SpliceLine(LPCSTR line, int lineNumber); //解析歌词文件的一行
	LPCSTR  GetString(int number); //获取某一行歌词

	std::vector<TIMETAG> m_vTimeTags; //歌词播放的时间标签
	std::vector<CString> m_vWords; //存储每句歌词


private: 

private: 
	CWnd*    m_pParent;
	HDC      m_dcMemoryDC;
	HDC      m_dcWinDC;
	int      m_iDrawHeight;
	int      m_iDrawWidth;
	int      m_iDrawX;
	int      m_iDrawY;

	int      m_nTextHeight;
	int      m_nTextSpace;

    int      m_iTextOutX;
	int      m_iTextOutY;

	int      m_iTimeInterval;
	int      m_iCurrent;
	int      m_iStartedPos;
    int      m_iScrollTotal;
	int      m_iMouseWheelTotal;
    int      m_iTime;

	 HWND    m_hWindow;
	CRect    m_rectangle;
	HBITMAP  m_hMemoryBitmap;
	HBRUSH   m_hBrushBackground;
	HFONT    m_hFont;
	COLORREF m_clrForeground;
	COLORREF m_clrBackground;
    COLORREF m_clrTextHighlighted;
	BOOL     m_bVertical; 

	BOOL     m_bFadeEffect; //是否淡入淡出
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int  OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTimer(UINT nIDEvent); //定时器函数
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnDestroy();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg BOOL OnMouseWheel( UINT nFlags, short zDelta, CPoint pt ); //处理鼠标滚轮消息
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);  //处理按键消息
};


