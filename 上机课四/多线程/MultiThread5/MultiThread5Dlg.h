// MultiThread5Dlg.h : header file
//

#if !defined(AFX_MULTITHREAD5DLG_H__F3169143_C4F3_4BB1_B505_ABB6A67CFA2E__INCLUDED_)
#define AFX_MULTITHREAD5DLG_H__F3169143_C4F3_4BB1_B505_ABB6A67CFA2E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMultiThread5Dlg dialog

struct threadInfo
{
	UINT nMilliSecond;
	CProgressCtrl* pctrlProgress;
};
UINT ThreadFunc(LPVOID lpParam);

class CMultiThread5Dlg : public CDialog
{
// Construction
public:
	CMultiThread5Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMultiThread5Dlg)
	enum { IDD = IDD_MULTITHREAD5_DIALOG };
	CProgressCtrl	m_ctrlProgress;
	int		m_nMilliSecond;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultiThread5Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CWinThread* pThread;
	
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMultiThread5Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnStart();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MULTITHREAD5DLG_H__F3169143_C4F3_4BB1_B505_ABB6A67CFA2E__INCLUDED_)
