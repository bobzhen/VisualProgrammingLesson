// MultiThread7.h : main header file for the MULTITHREAD7 application
//

#if !defined(AFX_MULTITHREAD7_H__2ABECAE0_7EE1_49F5_A3E2_727A2BDB6718__INCLUDED_)
#define AFX_MULTITHREAD7_H__2ABECAE0_7EE1_49F5_A3E2_727A2BDB6718__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMultiThread7App:
// See MultiThread7.cpp for the implementation of this class
//

class CMultiThread7App : public CWinApp
{
public:
	CMultiThread7App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultiThread7App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMultiThread7App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MULTITHREAD7_H__2ABECAE0_7EE1_49F5_A3E2_727A2BDB6718__INCLUDED_)
