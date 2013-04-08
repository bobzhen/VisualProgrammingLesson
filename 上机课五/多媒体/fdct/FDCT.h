// FDCT.h : main header file for the FDCT application
//

#if !defined(AFX_FDCT_H__6B8A5271_1CAA_412E_9CDA_730BCF0DF8F1__INCLUDED_)
#define AFX_FDCT_H__6B8A5271_1CAA_412E_9CDA_730BCF0DF8F1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFDCTApp:
// See FDCT.cpp for the implementation of this class
//

class CFDCTApp : public CWinApp
{
public:
	CFDCTApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFDCTApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFDCTApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FDCT_H__6B8A5271_1CAA_412E_9CDA_730BCF0DF8F1__INCLUDED_)
