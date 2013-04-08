// CTestSelDrawPicView.h : interface of the CCTestSelDrawPicView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CTESTSELDRAWPICVIEW_H__4856BE22_201E_4DE2_B428_F194CDE2DBE8__INCLUDED_)
#define AFX_CTESTSELDRAWPICVIEW_H__4856BE22_201E_4DE2_B428_F194CDE2DBE8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CCTestSelDrawPicView : public CView
{
protected: // create from serialization only
	CCTestSelDrawPicView();
	DECLARE_DYNCREATE(CCTestSelDrawPicView)

// Attributes
public:
	CCTestSelDrawPicDoc* GetDocument();
	
	// Operations
public:
	CBitmap m_bmpBk;
	CBitmap m_bmpFore;
	CDC m_dcBk;
	CDC m_dcFore;
	// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCTestSelDrawPicView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCTestSelDrawPicView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCTestSelDrawPicView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in CTestSelDrawPicView.cpp
inline CCTestSelDrawPicDoc* CCTestSelDrawPicView::GetDocument()
   { return (CCTestSelDrawPicDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CTESTSELDRAWPICVIEW_H__4856BE22_201E_4DE2_B428_F194CDE2DBE8__INCLUDED_)
