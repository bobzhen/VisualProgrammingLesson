// MultiThread6Dlg.h : header file
//

#if !defined(AFX_MULTITHREAD6DLG_H__14D0FE00_69E1_4177_B786_DF78B882E558__INCLUDED_)
#define AFX_MULTITHREAD6DLG_H__14D0FE00_69E1_4177_B786_DF78B882E558__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMultiThread6Dlg dialog

class CMultiThread6Dlg : public CDialog
{
// Construction
public:
	CMultiThread6Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMultiThread6Dlg)
	enum { IDD = IDD_MULTITHREAD6_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultiThread6Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMultiThread6Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnUiThread();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MULTITHREAD6DLG_H__14D0FE00_69E1_4177_B786_DF78B882E558__INCLUDED_)
