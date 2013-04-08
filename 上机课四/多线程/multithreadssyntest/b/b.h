// b.h : main header file for the B application
//

#if !defined(AFX_B_H__29481576_898B_41C2_B2B7_C5B2746D591A__INCLUDED_)
#define AFX_B_H__29481576_898B_41C2_B2B7_C5B2746D591A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CBApp:
// See b.cpp for the implementation of this class
//

class CBApp : public CWinApp
{
public:
	CBApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_B_H__29481576_898B_41C2_B2B7_C5B2746D591A__INCLUDED_)
