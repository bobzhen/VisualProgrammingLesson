// MultiThread4.h : main header file for the MULTITHREAD4 application
//

#if !defined(AFX_MULTITHREAD4_H__39D5AB7D_8956_4802_8882_83ABF9FE470C__INCLUDED_)
#define AFX_MULTITHREAD4_H__39D5AB7D_8956_4802_8882_83ABF9FE470C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMultiThread4App:
// See MultiThread4.cpp for the implementation of this class
//

class CMultiThread4App : public CWinApp
{
public:
	CMultiThread4App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultiThread4App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMultiThread4App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MULTITHREAD4_H__39D5AB7D_8956_4802_8882_83ABF9FE470C__INCLUDED_)
