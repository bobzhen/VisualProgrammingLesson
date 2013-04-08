// MultiThread3Dlg.h : header file
//

#if !defined(AFX_MULTITHREAD3DLG_H__4EF75688_34EB_4996_98A8_B9F6ACD29C3E__INCLUDED_)
#define AFX_MULTITHREAD3DLG_H__4EF75688_34EB_4996_98A8_B9F6ACD29C3E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMultiThread3Dlg dialog
struct threadInfo
{
	UINT nMilliSecond;
	CProgressCtrl* pctrlProgress;
};

UINT ThreadFunc(LPVOID lpParam);

class CMultiThread3Dlg : public CDialog
{
// Construction
public:
	CMultiThread3Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMultiThread3Dlg)
	enum { IDD = IDD_MULTITHREAD3_DIALOG };
	CProgressCtrl	m_ctrlProgress;
	int		m_nMilliSecond;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultiThread3Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HANDLE hThread;
    DWORD ThreadID;

	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMultiThread3Dlg)
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

#endif // !defined(AFX_MULTITHREAD3DLG_H__4EF75688_34EB_4996_98A8_B9F6ACD29C3E__INCLUDED_)
