// audio2.h : main header file for the AUDIO2 application
//

#if !defined(AFX_AUDIO2_H__75E68CCF_AF12_4A36_AF8D_07049B6034FB__INCLUDED_)
#define AFX_AUDIO2_H__75E68CCF_AF12_4A36_AF8D_07049B6034FB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CAudio2App:
// See audio2.cpp for the implementation of this class
//

class CAudio2App : public CWinApp
{
public:
	CAudio2App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAudio2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CAudio2App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AUDIO2_H__75E68CCF_AF12_4A36_AF8D_07049B6034FB__INCLUDED_)
