// SingleThread.h : main header file for the SINGLETHREAD application
//

#if !defined(AFX_SINGLETHREAD_H__77DF8C92_1FF5_43B7_93F4_45932139A96F__INCLUDED_)
#define AFX_SINGLETHREAD_H__77DF8C92_1FF5_43B7_93F4_45932139A96F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSingleThreadApp:
// See SingleThread.cpp for the implementation of this class
//

class CSingleThreadApp : public CWinApp
{
public:
	CSingleThreadApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSingleThreadApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSingleThreadApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SINGLETHREAD_H__77DF8C92_1FF5_43B7_93F4_45932139A96F__INCLUDED_)
