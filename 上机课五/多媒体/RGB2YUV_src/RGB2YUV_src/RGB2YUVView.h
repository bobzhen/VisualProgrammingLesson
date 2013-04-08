// RGB2YUVView.h : interface of the CRGB2YUVView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_RGB2YUVVIEW_H__030DCC6C_047F_4548_8A87_E3B6F6B72325__INCLUDED_)
#define AFX_RGB2YUVVIEW_H__030DCC6C_047F_4548_8A87_E3B6F6B72325__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CRGB2YUVView : public CView
{
protected: // create from serialization only
	CRGB2YUVView();
	DECLARE_DYNCREATE(CRGB2YUVView)

// Attributes
public:
	CRGB2YUVDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRGB2YUVView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	void YUV2RGB(byte *pRGB, byte *pYUV);
	BOOL WriteYUV(byte *Video_Field0, byte *Video_Field1, int size);
	void RGB2YUV(byte *pRGB, byte *pYUV);
	virtual ~CRGB2YUVView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CRGB2YUVView)
	afx_msg void OnReadBmp();
	afx_msg void OnConvertPAL();
	afx_msg void OnReadPAL();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in RGB2YUVView.cpp
inline CRGB2YUVDoc* CRGB2YUVView::GetDocument()
   { return (CRGB2YUVDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RGB2YUVVIEW_H__030DCC6C_047F_4548_8A87_E3B6F6B72325__INCLUDED_)
