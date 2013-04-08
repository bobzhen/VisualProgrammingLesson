// bDlg.h : header file
//

#if !defined(AFX_BDLG_H__01FC5752_0DEC_4E03_A42D_B54A6209CD91__INCLUDED_)
#define AFX_BDLG_H__01FC5752_0DEC_4E03_A42D_B54A6209CD91__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CBDlg dialog

class CBDlg : public CDialog
{
// Construction
public:
	CBDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CBDlg)
	enum { IDD = IDD_B_DIALOG };
	CButton	m_sync;
	CString	m_edit;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CBDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BDLG_H__01FC5752_0DEC_4E03_A42D_B54A6209CD91__INCLUDED_)
