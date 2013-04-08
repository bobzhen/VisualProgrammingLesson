// MultiThread7Dlg.h : header file
//

#if !defined(AFX_MULTITHREAD7DLG_H__B489C005_F137_4CB5_8FD8_9879D1C42FA4__INCLUDED_)
#define AFX_MULTITHREAD7DLG_H__B489C005_F137_4CB5_8FD8_9879D1C42FA4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CalculateThread.h"


#define WM_DISPLAY WM_USER+2

/////////////////////////////////////////////////////////////////////////////
// CMultiThread7Dlg dialog

class CMultiThread7Dlg : public CDialog
{
// Construction
public:
	CMultiThread7Dlg(CWnd* pParent = NULL);	// standard constructor
	CCalculateThread* m_pCalculateThread;

// Dialog Data
	//{{AFX_DATA(CMultiThread7Dlg)
	enum { IDD = IDD_MULTITHREAD7_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultiThread7Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	int nAddend;
	LRESULT OnDisplay(WPARAM wParam,LPARAM lParam);
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMultiThread7Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	afx_msg void OnRadio3();
	afx_msg void OnSum();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MULTITHREAD7DLG_H__B489C005_F137_4CB5_8FD8_9879D1C42FA4__INCLUDED_)
