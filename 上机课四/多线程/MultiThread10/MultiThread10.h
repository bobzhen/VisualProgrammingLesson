// MultiThread10.h : main header file for the MULTITHREAD10 application
//

#if !defined(AFX_MULTITHREAD10_H__FAC49783_E409_4F75_B355_8F635DD1DBE9__INCLUDED_)
#define AFX_MULTITHREAD10_H__FAC49783_E409_4F75_B355_8F635DD1DBE9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMultiThread10App:
// See MultiThread10.cpp for the implementation of this class
//

class CMultiThread10App : public CWinApp
{
public:
	CMultiThread10App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultiThread10App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMultiThread10App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MULTITHREAD10_H__FAC49783_E409_4F75_B355_8F635DD1DBE9__INCLUDED_)
