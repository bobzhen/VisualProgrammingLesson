// MultiThread9.h : main header file for the MULTITHREAD9 application
//

#if !defined(AFX_MULTITHREAD9_H__1A5EDAB0_D4BC_453D_B2F4_1811EFDD3C5C__INCLUDED_)
#define AFX_MULTITHREAD9_H__1A5EDAB0_D4BC_453D_B2F4_1811EFDD3C5C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMultiThread9App:
// See MultiThread9.cpp for the implementation of this class
//

class CMultiThread9App : public CWinApp
{
public:
	CMultiThread9App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultiThread9App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMultiThread9App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MULTITHREAD9_H__1A5EDAB0_D4BC_453D_B2F4_1811EFDD3C5C__INCLUDED_)
