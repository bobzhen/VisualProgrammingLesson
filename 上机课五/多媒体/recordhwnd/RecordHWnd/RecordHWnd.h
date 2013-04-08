// RecordHWnd.h : main header file for the RECORDHWND application
//

#if !defined(AFX_RECORDHWND_H__A132D258_442C_46F4_BD89_0492FC29A55E__INCLUDED_)
#define AFX_RECORDHWND_H__A132D258_442C_46F4_BD89_0492FC29A55E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CRecordHWndApp:
// See RecordHWnd.cpp for the implementation of this class
//

class CRecordHWndApp : public CWinApp
{
public:
	CRecordHWndApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRecordHWndApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CRecordHWndApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RECORDHWND_H__A132D258_442C_46F4_BD89_0492FC29A55E__INCLUDED_)
