// MultiThread1.h : main header file for the MULTITHREAD1 application
//

#if !defined(AFX_MULTITHREAD1_H__2E191358_2862_49DA_85D7_62685DEE780B__INCLUDED_)
#define AFX_MULTITHREAD1_H__2E191358_2862_49DA_85D7_62685DEE780B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMultiThread1App:
// See MultiThread1.cpp for the implementation of this class
//

class CMultiThread1App : public CWinApp
{
public:
	CMultiThread1App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultiThread1App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMultiThread1App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MULTITHREAD1_H__2E191358_2862_49DA_85D7_62685DEE780B__INCLUDED_)
