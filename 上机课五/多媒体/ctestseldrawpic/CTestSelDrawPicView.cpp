// CTestSelDrawPicView.cpp : implementation of the CCTestSelDrawPicView class
//

#include "stdafx.h"
#include "CTestSelDrawPic.h"

#include "CTestSelDrawPicDoc.h"
#include "CTestSelDrawPicView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCTestSelDrawPicView

IMPLEMENT_DYNCREATE(CCTestSelDrawPicView, CView)

BEGIN_MESSAGE_MAP(CCTestSelDrawPicView, CView)
	//{{AFX_MSG_MAP(CCTestSelDrawPicView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCTestSelDrawPicView construction/destruction

CCTestSelDrawPicView::CCTestSelDrawPicView()
{
	// TODO: add construction code here

}

CCTestSelDrawPicView::~CCTestSelDrawPicView()
{
}

BOOL CCTestSelDrawPicView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CCTestSelDrawPicView drawing

void CCTestSelDrawPicView::OnDraw(CDC* pDC)
{
	CCTestSelDrawPicDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

	CBitmap* poldBk=m_dcBk.SelectObject(&m_bmpBk);   //选入背景图
	CBitmap* poldFore=m_dcFore.SelectObject(&m_bmpFore);
	
	CRect rect;
	GetClientRect(&rect);  //得到客户区矩形
	CDC maskDc;        //创建设备环境maskDc
	CBitmap maskBitmap;
	maskDc.CreateCompatibleDC(pDC);  //创建与当前设备相兼容的设备
	maskBitmap.CreateBitmap(rect.Width(),rect.Height(),1,1,NULL ); //创建一个单色图
	CBitmap* pOldMaskDCBitmap = maskDc.SelectObject( &maskBitmap ); //选入单色图
	CBrush brush(RGB(255,255,255));
	//	CBrush brush(RGB(134,112,124));
	CBrush * oldbrush;
	oldbrush=maskDc.SelectObject(&brush);
	maskDc.FillRect(&rect,&brush);
	//取得要消除的背景色值
	COLORREF clrTrans= m_dcFore.GetPixel(2, 2);

	// 设置前景图的背景色
	COLORREF clrSaveBk  = m_dcFore.SetBkColor(clrTrans);

	//将前景图拷贝到maskDc
	maskDc.BitBlt(0,0,rect.Width(),rect.Height(), &m_dcFore, 0,0,SRCCOPY); 
	//	pDC->BitBlt(0,0,rect.Width(), rect.Height(),&maskDc,0,0,SRCCOPY);

	//前景图与mask做‘与’运算	
	m_dcFore.SetBkColor(RGB(0,0,0));
	m_dcFore.SetTextColor(RGB(255,255,255));
	m_dcFore.BitBlt(0,0,rect.Width(), rect.Height(),&maskDc,0,0,SRCAND);
	//	pDC->BitBlt(0,0,rect.Width(), rect.Height(),&m_dcFore,0,0,SRCCOPY);

	//背景图与mask做‘与’运算
	m_dcBk.SetBkColor(RGB(255,255,255));
	m_dcBk.SetTextColor(RGB(0,0,0));
	m_dcBk.BitBlt(0,0,rect.Width(),rect.Height(),&maskDc,0,0,SRCAND);

	//背景图与前景图做‘或’运算	
	m_dcBk.BitBlt(rect.left,rect.top,rect.Width(),rect.Height(),&m_dcFore,0,0,SRCPAINT);
	//	pDC->BitBlt(0,0,rect.Width(), rect.Height(),&m_dcBk,0,0,SRCCOPY);

	//将合成后的图像显示
	pDC->BitBlt(0,0,rect.Width(),rect.Height(),&m_dcBk,0,0,SRCCOPY);
	
	pDC->SelectObject(oldbrush);
	m_dcBk.SelectObject(poldBk);
	m_dcFore.SelectObject(poldFore);
	
}

/////////////////////////////////////////////////////////////////////////////
// CCTestSelDrawPicView printing

BOOL CCTestSelDrawPicView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCTestSelDrawPicView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCTestSelDrawPicView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CCTestSelDrawPicView diagnostics

#ifdef _DEBUG
void CCTestSelDrawPicView::AssertValid() const
{
	CView::AssertValid();
}

void CCTestSelDrawPicView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCTestSelDrawPicDoc* CCTestSelDrawPicView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCTestSelDrawPicDoc)));
	return (CCTestSelDrawPicDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCTestSelDrawPicView message handlers

void CCTestSelDrawPicView::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	m_bmpBk.LoadBitmap(IDB_BK);  //将背景图载入
	m_bmpFore.LoadBitmap(IDB_FORE);  //将前景图载入
	CClientDC dc(this);     //获得当前客户区设备环境
	m_dcBk.CreateCompatibleDC(&dc);   //创建与当前设备相兼容的设备
	m_dcFore.CreateCompatibleDC(&dc); 
}
