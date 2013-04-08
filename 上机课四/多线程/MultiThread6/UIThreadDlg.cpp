// UIThreadDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MultiThread6.h"
#include "UIThreadDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUIThreadDlg dialog


CUIThreadDlg::CUIThreadDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CUIThreadDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CUIThreadDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CUIThreadDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUIThreadDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CUIThreadDlg, CDialog)
	//{{AFX_MSG_MAP(CUIThreadDlg)
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUIThreadDlg message handlers

void CUIThreadDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	AfxMessageBox("You Clicked The Left Button!");
	CDialog::OnLButtonDown(nFlags, point);
}
