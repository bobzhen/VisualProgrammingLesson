// CTestSelDrawPic.h : main header file for the CTESTSELDRAWPIC application
//

#if !defined(AFX_CTESTSELDRAWPIC_H__2FBC98F5_CBF1_4F2F_B09B_1134C0DB7F74__INCLUDED_)
#define AFX_CTESTSELDRAWPIC_H__2FBC98F5_CBF1_4F2F_B09B_1134C0DB7F74__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CCTestSelDrawPicApp:
// See CTestSelDrawPic.cpp for the implementation of this class
//

class CCTestSelDrawPicApp : public CWinApp
{
public:
	CCTestSelDrawPicApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCTestSelDrawPicApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CCTestSelDrawPicApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CTESTSELDRAWPIC_H__2FBC98F5_CBF1_4F2F_B09B_1134C0DB7F74__INCLUDED_)
