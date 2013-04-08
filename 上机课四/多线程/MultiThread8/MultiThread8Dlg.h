// MultiThread8Dlg.h : header file
//

#if !defined(AFX_MULTITHREAD8DLG_H__0A1B9449_793C_429C_B671_2E7FF421D455__INCLUDED_)
#define AFX_MULTITHREAD8DLG_H__0A1B9449_793C_429C_B671_2E7FF421D455__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


UINT WriteW(LPVOID pParam);
UINT WriteD(LPVOID pParam);


/////////////////////////////////////////////////////////////////////////////
// CMultiThread8Dlg dialog

class CMultiThread8Dlg : public CDialog
{
// Construction
public:
	CMultiThread8Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMultiThread8Dlg)
	enum { IDD = IDD_MULTITHREAD8_DIALOG };
	CEdit	m_ctrlD;
	CEdit	m_ctrlW;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultiThread8Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMultiThread8Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnWritew();
	afx_msg void OnWrited();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MULTITHREAD8DLG_H__0A1B9449_793C_429C_B671_2E7FF421D455__INCLUDED_)
