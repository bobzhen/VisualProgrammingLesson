// audio2Dlg.h : header file
//

#if !defined(AFX_AUDIO2DLG_H__ED9BB19A_81F5_4EAC_A39A_8EF723702621__INCLUDED_)
#define AFX_AUDIO2DLG_H__ED9BB19A_81F5_4EAC_A39A_8EF723702621__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CAudio2Dlg dialog
#define  INP_BUFFER_SIZE 16384
class CAudio2Dlg : public CDialog
{
// Construction
public:
	CAudio2Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CAudio2Dlg)
	enum { IDD = IDD_AUDIO2_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAudio2Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	BOOL bEnding;
	DWORD dwDataLength;
	HWAVEIN hWaveIn;
	HWAVEOUT hWaveOut;
	PBYTE pBuffer1,pBuffer2,pSaveBuffer,pNewBuffer;
	PWAVEHDR pWaveHdr1,pWaveHdr2;
    WAVEFORMATEX waveform;
	// Generated message map functions
	//{{AFX_MSG(CAudio2Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnMM_WIM_OPEN(UINT wParam,LONG lParam);
	afx_msg void OnMM_WIM_DATA(UINT wParam,LONG lParam);
	afx_msg void OnMM_WIM_CLOSE(UINT wParam,LONG lParam);
	afx_msg void OnMM_WOM_OPEN(UINT wParam,LONG lParam);
	afx_msg void OnMM_WOM_DONE(UINT wParam,LONG lParam);
	afx_msg void OnMM_WOM_CLOSE(UINT wParam,LONG lParam);
	afx_msg void OnRecStart();
	afx_msg void OnRecStop();
	afx_msg void OnPlayStart();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AUDIO2DLG_H__ED9BB19A_81F5_4EAC_A39A_8EF723702621__INCLUDED_)
