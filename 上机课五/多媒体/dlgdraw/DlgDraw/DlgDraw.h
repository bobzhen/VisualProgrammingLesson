// DlgDraw.h : main header file for the DLGDRAW application
//

#if !defined(AFX_DLGDRAW_H__363B02DC_8BCC_4A57_B1E0_34405773978E__INCLUDED_)
#define AFX_DLGDRAW_H__363B02DC_8BCC_4A57_B1E0_34405773978E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDlgDrawApp:
// See DlgDraw.cpp for the implementation of this class
//

class CDlgDrawApp : public CWinApp
{
public:
	CDlgDrawApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgDrawApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CDlgDrawApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGDRAW_H__363B02DC_8BCC_4A57_B1E0_34405773978E__INCLUDED_)
