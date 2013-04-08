#if !defined(AFX_CALCULATETHREAD_H__EA957367_D3FE_4661_978C_48B7F4DA98F4__INCLUDED_)
#define AFX_CALCULATETHREAD_H__EA957367_D3FE_4661_978C_48B7F4DA98F4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CalculateThread.h : header file
//


#define WM_CALCULATE WM_USER+1



/////////////////////////////////////////////////////////////////////////////
// CCalculateThread thread

class CCalculateThread : public CWinThread
{
	DECLARE_DYNCREATE(CCalculateThread)
protected:
	CCalculateThread();           // protected constructor used by dynamic creation

// Attributes
public:

// Operations
public:
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCalculateThread)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation
protected:
	afx_msg LONG OnCalculate(UINT wParam,LONG lParam);
	virtual ~CCalculateThread();

	// Generated message map functions
	//{{AFX_MSG(CCalculateThread)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CALCULATETHREAD_H__EA957367_D3FE_4661_978C_48B7F4DA98F4__INCLUDED_)
