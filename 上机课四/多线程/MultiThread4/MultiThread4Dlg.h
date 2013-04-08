// MultiThread4Dlg.h : header file
//

#if !defined(AFX_MULTITHREAD4DLG_H__2D21AE69_B137_4595_8BE0_653023B1AB2A__INCLUDED_)
#define AFX_MULTITHREAD4DLG_H__2D21AE69_B137_4595_8BE0_653023B1AB2A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMultiThread4Dlg dialog

class CMultiThread4Dlg : public CDialog
{
// Construction
public:
	CMultiThread4Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMultiThread4Dlg)
	enum { IDD = IDD_MULTITHREAD4_DIALOG };
	long	m_nCount;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultiThread4Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMultiThread4Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTest();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MULTITHREAD4DLG_H__2D21AE69_B137_4595_8BE0_653023B1AB2A__INCLUDED_)
