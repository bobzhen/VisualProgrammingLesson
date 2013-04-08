// MultiThread1Dlg.h : header file
//

#if !defined(AFX_MULTITHREAD1DLG_H__A30782EC_E0CF_402A_9B54_22DC05F87ECF__INCLUDED_)
#define AFX_MULTITHREAD1DLG_H__A30782EC_E0CF_402A_9B54_22DC05F87ECF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMultiThread1Dlg dialog
void ThreadFunc();

class CMultiThread1Dlg : public CDialog
{
// Construction
public:
	CMultiThread1Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMultiThread1Dlg)
	enum { IDD = IDD_MULTITHREAD1_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultiThread1Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	DWORD ThreadID;
	HANDLE hThread;

	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMultiThread1Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnStop();
	afx_msg void OnStart();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MULTITHREAD1DLG_H__A30782EC_E0CF_402A_9B54_22DC05F87ECF__INCLUDED_)
