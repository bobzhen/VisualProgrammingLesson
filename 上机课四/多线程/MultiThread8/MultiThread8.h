// MultiThread8.h : main header file for the MULTITHREAD8 application
//

#if !defined(AFX_MULTITHREAD8_H__39422E2B_14BD_4106_B6C1_C14E62133F87__INCLUDED_)
#define AFX_MULTITHREAD8_H__39422E2B_14BD_4106_B6C1_C14E62133F87__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMultiThread8App:
// See MultiThread8.cpp for the implementation of this class
//

class CMultiThread8App : public CWinApp
{
public:
	CMultiThread8App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultiThread8App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMultiThread8App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MULTITHREAD8_H__39422E2B_14BD_4106_B6C1_C14E62133F87__INCLUDED_)
