// GDIPlusDBBView.h : interface of the CGDIPlusDBBView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GDIPLUSDBBVIEW_H__39271BC5_2783_4C18_AC6C_84C65012444A__INCLUDED_)
#define AFX_GDIPLUSDBBVIEW_H__39271BC5_2783_4C18_AC6C_84C65012444A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CGDIPlusDBBView : public CScrollView
{
protected: // create from serialization only
	CGDIPlusDBBView();
	DECLARE_DYNCREATE(CGDIPlusDBBView)

// Attributes
public:
	CGDIPlusDBBDoc* GetDocument();
	GdiplusStartupInput m_gdiplusStartupInput;			// GDI+
	ULONG_PTR m_gdiplusToken;							// GDI+
	CDC m_memDC;
	CBitmap m_memBitmap;
	CBitmap * m_pOldBitmap;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGDIPlusDBBView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CGDIPlusDBBView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CGDIPlusDBBView)
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in GDIPlusDBBView.cpp
inline CGDIPlusDBBDoc* CGDIPlusDBBView::GetDocument()
   { return (CGDIPlusDBBDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GDIPLUSDBBVIEW_H__39271BC5_2783_4C18_AC6C_84C65012444A__INCLUDED_)
