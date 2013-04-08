// MultiThread10Dlg.h : header file
//

#if !defined(AFX_MULTITHREAD10DLG_H__D6A8ED1F_0375_4CD3_B29C_821E0A456BDB__INCLUDED_)
#define AFX_MULTITHREAD10DLG_H__D6A8ED1F_0375_4CD3_B29C_821E0A456BDB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


UINT WriteA(LPVOID pParam);
UINT WriteB(LPVOID pParam);
UINT WriteC(LPVOID pParam);



/////////////////////////////////////////////////////////////////////////////
// CMultiThread10Dlg dialog

class CMultiThread10Dlg : public CDialog
{
// Construction
public:
	CMultiThread10Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMultiThread10Dlg)
	enum { IDD = IDD_MULTITHREAD10_DIALOG };
	CEdit	m_ctrlC;
	CEdit	m_ctrlB;
	CEdit	m_ctrlA;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultiThread10Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMultiThread10Dlg)
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

#endif // !defined(AFX_MULTITHREAD10DLG_H__D6A8ED1F_0375_4CD3_B29C_821E0A456BDB__INCLUDED_)
