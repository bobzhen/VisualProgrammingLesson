// GDIPlusDBBView.cpp : implementation of the CGDIPlusDBBView class
//

#include "stdafx.h"
#include "GDIPlusDBB.h"

#include "GDIPlusDBBDoc.h"
#include "GDIPlusDBBView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGDIPlusDBBView

IMPLEMENT_DYNCREATE(CGDIPlusDBBView, CScrollView)

BEGIN_MESSAGE_MAP(CGDIPlusDBBView, CScrollView)
	//{{AFX_MSG_MAP(CGDIPlusDBBView)
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGDIPlusDBBView construction/destruction

CGDIPlusDBBView::CGDIPlusDBBView()
{
	// TODO: add construction code here

}

CGDIPlusDBBView::~CGDIPlusDBBView()
{
}

BOOL CGDIPlusDBBView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CGDIPlusDBBView drawing

void CGDIPlusDBBView::OnDraw(CDC* pDC)
{
	CGDIPlusDBBDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	
	// TODO: add draw code for native data here
	pDC->BitBlt(0,0,pDoc->m_nMapWidth,pDoc->m_nMapHeight,&m_memDC,0,0,SRCCOPY);
}

void CGDIPlusDBBView::OnInitialUpdate()
{
	CGDIPlusDBBDoc* pDoc = GetDocument();

	GdiplusStartup(&m_gdiplusToken, &m_gdiplusStartupInput, NULL);

	// 显示默认中国地图
	USES_CONVERSION;
	pDoc->m_pStrMapName = "china.jpg";
	CString pStrFullPath = pDoc->m_pStrMapPath + pDoc->m_pStrMapName;
	LPWSTR wStrFullPath = A2W(pStrFullPath);
	Image imgDefault(wStrFullPath);
	// 滚动条大小
	CSize sizeTotal;
	sizeTotal.cx = imgDefault.GetWidth();
	sizeTotal.cy = imgDefault.GetHeight();
	SetScrollSizes(MM_TEXT, sizeTotal);

	// 准备画布
	CDC * pDC = this->GetDC();
	m_memDC.CreateCompatibleDC(NULL);
	m_memBitmap.CreateCompatibleBitmap(pDC,2000,2000);
	ReleaseDC(pDC);

	CScrollView::OnInitialUpdate();
}

/////////////////////////////////////////////////////////////////////////////
// CGDIPlusDBBView printing

BOOL CGDIPlusDBBView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CGDIPlusDBBView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CGDIPlusDBBView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CGDIPlusDBBView diagnostics

#ifdef _DEBUG
void CGDIPlusDBBView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CGDIPlusDBBView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CGDIPlusDBBDoc* CGDIPlusDBBView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGDIPlusDBBDoc)));
	return (CGDIPlusDBBDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGDIPlusDBBView message handlers

void CGDIPlusDBBView::OnDestroy() 
{
	CScrollView::OnDestroy();
	
	// TODO: Add your message handler code here
	GdiplusShutdown(m_gdiplusToken);
}

void CGDIPlusDBBView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	CGDIPlusDBBDoc* pDoc = GetDocument();

	// 贴上画布
	m_pOldBitmap = m_memDC.SelectObject(&m_memBitmap);
	m_memDC.FillSolidRect(0,0,2000,2000,RGB(100,100,100));

	// 贴图
	CString pStrFullPath = pDoc->m_pStrMapPath + pDoc->m_pStrMapName;
	USES_CONVERSION;
	LPWSTR wStr = A2W(pStrFullPath);
	Image img(wStr);
	pDoc->m_nMapWidth = img.GetWidth();
	pDoc->m_nMapHeight = img.GetHeight();
	Graphics g(m_memDC.GetSafeHdc());
	g.DrawImage(&img,0,0,img.GetWidth(),img.GetHeight());

	// 恢复
	m_memDC.SelectObject(m_pOldBitmap);

	// 刷新
	Invalidate();
}
