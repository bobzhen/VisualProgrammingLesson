// RecordHWndDlg.h : header file
//

#if !defined(AFX_RECORDHWNDDLG_H__DDBDC7D2_2F8D_4926_AC87_1625A6BBBFB1__INCLUDED_)
#define AFX_RECORDHWNDDLG_H__DDBDC7D2_2F8D_4926_AC87_1625A6BBBFB1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "HyperLink.h"
/////////////////////////////////////////////////////////////////////////////
// CRecordHWndDlg dialog
#define  INP_BUFFER_SIZE 16384

class CRecordHWndDlg : public CDialog
{
// Construction
public:
	CRecordHWndDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CRecordHWndDlg)
	enum { IDD = IDD_RECORDHWND_DIALOG };
	CHyperLink	m_mailCtrl;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRecordHWndDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	BOOL bRecording,bPlaying,bReverse,bPaused,bEnding,bTerminating;
	DWORD dwDataLength,dwRepetitions;
	HWAVEIN hWaveIn;
	HWAVEOUT hWaveOut;
	PBYTE pBuffer1,pBuffer2,pSaveBuffer,pNewBuffer;
	PWAVEHDR pWaveHdr1,pWaveHdr2;
	/*
	static TCHAR szOpenError[] =_T("Erro opening waveform audio!");
	static TCHAR szMemError[] =_T("Erro allocationg memory!");*/
	
	WAVEFORMATEX waveform;

	// Generated message map functions
	//{{AFX_MSG(CRecordHWndDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnRecStart();
	afx_msg void OnRecStop();
	afx_msg void OnMM_WIM_OPEN(UINT wParam,LONG lParam);
	afx_msg void OnMM_WIM_DATA(UINT wParam,LONG lParam);
	afx_msg void OnMM_WIM_CLOSE(UINT wParam,LONG lParam);
	afx_msg void OnMM_WOM_OPEN(UINT wParam,LONG lParam);
	afx_msg void OnMM_WOM_DONE(UINT wParam,LONG lParam);
	afx_msg void OnMM_WOM_CLOSE(UINT wParam,LONG lParam);
	afx_msg void OnDestroy();
	afx_msg void OnPlayStart();
	afx_msg void OnPlayPause();
	afx_msg void OnPlayStop();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RECORDHWNDDLG_H__DDBDC7D2_2F8D_4926_AC87_1625A6BBBFB1__INCLUDED_)
