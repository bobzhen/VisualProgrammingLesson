// FDCTDlg.h : header file
//

#if !defined(AFX_FDCTDLG_H__C89DA67C_D7B6_42C3_8562_E8AE70F751D8__INCLUDED_)
#define AFX_FDCTDLG_H__C89DA67C_D7B6_42C3_8562_E8AE70F751D8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFDCTDlg dialog
typedef struct
{
	//CString str;
	int row;
	int col;
    void *data;
	bool m_bfinished;
	DWORD m_start,m_end;//“‘∫¡√Îº∆;
	
	 
}RUNINFO;

class CFDCTDlg : public CDialog
{
// Construction
public:
	void DrawFreqImg(double *src,int cx,int cy,int x,int y);
	void DrawImg(double *src,int cx,int cy,int x,int y);
	void CharData2DoubleData(char * ch,double *du);
	void DrawImg(char *src,int cx,int cy,int x,int y);
	void WriteFile(CString filename,int row,int col,double *data);
	CFDCTDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CFDCTDlg)
	enum { IDD = IDD_FDCT_DIALOG };
	CButton	m_radio;
	CButton	m_IDCT;
	CButton	m_DCT;
	CString	m_status;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFDCTDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	int m_row,m_col;
	char *data;
	double *m_buffer;
	bool m_loaded;
	bool m_bHaveProcess;
	bool m_bDCTed;
	bool m_bIDCTed;
	bool m_bFreqImg;
	bool m_bTimeImg;
	RUNINFO info;


	// Generated message map functions
	//{{AFX_MSG(CFDCTDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnRead();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnClose();
	afx_msg void OnDct();
	afx_msg void OnIdct();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FDCTDLG_H__C89DA67C_D7B6_42C3_8562_E8AE70F751D8__INCLUDED_)
