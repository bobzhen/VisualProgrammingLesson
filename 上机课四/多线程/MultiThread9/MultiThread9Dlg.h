// MultiThread9Dlg.h : header file
//

#if !defined(AFX_MULTITHREAD9DLG_H__92444928_69B0_4AAD_8F29_0C194922C20F__INCLUDED_)
#define AFX_MULTITHREAD9DLG_H__92444928_69B0_4AAD_8F29_0C194922C20F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


UINT WriteW(LPVOID pParam);
UINT WriteD(LPVOID pParam);


/////////////////////////////////////////////////////////////////////////////
// CMultiThread9Dlg dialog

class CMultiThread9Dlg : public CDialog
{
// Construction
public:
	CMultiThread9Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMultiThread9Dlg)
	enum { IDD = IDD_MULTITHREAD9_DIALOG };
	CEdit	m_ctrlW;
	CEdit	m_ctrlD;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultiThread9Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMultiThread9Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnWritew();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MULTITHREAD9DLG_H__92444928_69B0_4AAD_8F29_0C194922C20F__INCLUDED_)
