// DlgDrawView.cpp : implementation of the CDlgDrawView class
//

#include "stdafx.h"
#include "DlgDraw.h"

#include "DlgDrawDoc.h"
#include "DlgDrawView.h"

#include "DrawTest.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgDrawView

IMPLEMENT_DYNCREATE(CDlgDrawView, CView)

BEGIN_MESSAGE_MAP(CDlgDrawView, CView)
	//{{AFX_MSG_MAP(CDlgDrawView)
	ON_COMMAND(ID_BUTTON32771, OnButton32771)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgDrawView construction/destruction

CDlgDrawView::CDlgDrawView()
{
	// TODO: add construction code here

}

CDlgDrawView::~CDlgDrawView()
{
}

BOOL CDlgDrawView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDlgDrawView drawing

void CDlgDrawView::OnDraw(CDC* pDC)
{
	CDlgDrawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CDlgDrawView printing

BOOL CDlgDrawView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDlgDrawView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDlgDrawView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDlgDrawView diagnostics

#ifdef _DEBUG
void CDlgDrawView::AssertValid() const
{
	CView::AssertValid();
}

void CDlgDrawView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDlgDrawDoc* CDlgDrawView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDlgDrawDoc)));
	return (CDlgDrawDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDlgDrawView message handlers

void CDlgDrawView::OnButton32771() 
{
	// TODO: Add your command handler code here
	CDrawTest dlg;
	dlg.DoModal();
}
