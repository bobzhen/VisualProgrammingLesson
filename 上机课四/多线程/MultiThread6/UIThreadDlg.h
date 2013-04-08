#if !defined(AFX_UITHREADDLG_H__B205CE1F_1722_4163_94CE_39F5DD89F855__INCLUDED_)
#define AFX_UITHREADDLG_H__B205CE1F_1722_4163_94CE_39F5DD89F855__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// UIThreadDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CUIThreadDlg dialog

class CUIThreadDlg : public CDialog
{
// Construction
public:
	CUIThreadDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CUIThreadDlg)
	enum { IDD = IDD_UITHREADDLG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUIThreadDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CUIThreadDlg)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UITHREADDLG_H__B205CE1F_1722_4163_94CE_39F5DD89F855__INCLUDED_)
