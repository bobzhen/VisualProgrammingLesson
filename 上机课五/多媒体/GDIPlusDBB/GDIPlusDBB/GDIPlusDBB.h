// GDIPlusDBB.h : main header file for the GDIPLUSDBB application
//

#if !defined(AFX_GDIPLUSDBB_H__2DCBB3C7_0D42_48E5_A2EA_69CADDD7F8EC__INCLUDED_)
#define AFX_GDIPLUSDBB_H__2DCBB3C7_0D42_48E5_A2EA_69CADDD7F8EC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CGDIPlusDBBApp:
// See GDIPlusDBB.cpp for the implementation of this class
//

class CGDIPlusDBBApp : public CWinApp
{
public:
	CGDIPlusDBBApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGDIPlusDBBApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CGDIPlusDBBApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GDIPLUSDBB_H__2DCBB3C7_0D42_48E5_A2EA_69CADDD7F8EC__INCLUDED_)
