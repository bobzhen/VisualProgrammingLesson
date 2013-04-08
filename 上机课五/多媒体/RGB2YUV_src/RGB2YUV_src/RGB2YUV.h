// RGB2YUV.h : main header file for the RGB2YUV application
//

#if !defined(AFX_RGB2YUV_H__80636E62_95E0_49DB_BE5A_9FFA1218B30E__INCLUDED_)
#define AFX_RGB2YUV_H__80636E62_95E0_49DB_BE5A_9FFA1218B30E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CRGB2YUVApp:
// See RGB2YUV.cpp for the implementation of this class
//

class CRGB2YUVApp : public CWinApp
{
public:
	CRGB2YUVApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRGB2YUVApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CRGB2YUVApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RGB2YUV_H__80636E62_95E0_49DB_BE5A_9FFA1218B30E__INCLUDED_)
