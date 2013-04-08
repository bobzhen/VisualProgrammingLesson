// CalculateThread.cpp : implementation file
//

#include "stdafx.h"
#include "MultiThread7.h"
#include "CalculateThread.h"


#include "MultiThread7Dlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCalculateThread

IMPLEMENT_DYNCREATE(CCalculateThread, CWinThread)

CCalculateThread::CCalculateThread()
{
}

CCalculateThread::~CCalculateThread()
{
}

BOOL CCalculateThread::InitInstance()
{
	// TODO:  perform and per-thread initialization here
	return TRUE;
}

int CCalculateThread::ExitInstance()
{
	// TODO:  perform any per-thread cleanup here
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CCalculateThread, CWinThread)
	//{{AFX_MSG_MAP(CCalculateThread)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
	ON_THREAD_MESSAGE(WM_CALCULATE,OnCalculate)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCalculateThread message handlers
LONG CCalculateThread::OnCalculate(UINT wParam,LONG lParam)
{
	int nTmpt=0;
	for(int i=0;i<=(int)wParam;i++)
	{
		nTmpt=nTmpt+i;
	}

	Sleep(500);
    ::PostMessage((HWND)(GetMainWnd()->GetSafeHwnd()),WM_DISPLAY,nTmpt,NULL);

	return 0;
}