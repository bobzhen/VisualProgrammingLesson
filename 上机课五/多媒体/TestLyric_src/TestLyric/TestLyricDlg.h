// TestLyricDlg.h : 头文件
//

#pragma once


#include "LiveWnd.h"
#include "colourpickerxp.h"
#include "afxwin.h"
#include <streams.h>
#include "DXGraph.h"
#include "afxcmn.h"

// CTestLyricDlg 对话框
class CTestLyricDlg : public CDialog
{
// 构造
public:
	CTestLyricDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_TESTLYRIC_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

public:

	CSliderCtrl	      m_TimeSlider;
   	CSliderCtrl       m_VolumeSlider;
    CLiveWnd          m_wndLyric; //歌词显示窗口
	CColourPickerXP   m_TextColorNormal; 
	CColourPickerXP   m_TextHighlighted;
    int               m_iMainTime; //歌词播放当前时间

	int     GetSongTotalTime(); //获得文件总播放长度(单位: ms)
	int     GetCurrentTime(); //获得当前播放位置的时间(单位: ms)


	BOOL    CreateGraph(void);        // 创建播放音频的Filter Graph
	void    DestroyGraph(void);       // 析构Filter Graph

	BOOL    OpenLyricFile(LPCSTR szFilePath); //打开歌词文件

// 实现
protected:
	HICON m_hIcon;
	
	CDXGraph *   m_FilterGraph;     // Filter Graph封装
	CString      m_SourceFile;      // 文件路径
	UINT         m_SliderTimer;     // 定时器ID

	LONGLONG     m_FileTimeinNanos; //文件时间长度(单位为100纳秒, 等于10^(-4) ms )


	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	void  OnDropFiles(HDROP hDropInfo );
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnSelectScrollMode();
   	afx_msg void OnButtonPlay();
	afx_msg void OnButtonPause();
	afx_msg void OnButtonStop();
	afx_msg void OnBnClickedAddFile();
	afx_msg LRESULT OnGraphNotify(WPARAM inWParam, LPARAM inLParam);
	afx_msg LRESULT OnPendingStopPlay(WPARAM wparam, LPARAM lparam);
	afx_msg void OnCheckFadeEffect();
};
