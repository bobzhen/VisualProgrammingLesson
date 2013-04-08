// RGB2YUVDoc.h : interface of the CRGB2YUVDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_RGB2YUVDOC_H__5E386A52_257F_4B8F_A0DD_42524C68113E__INCLUDED_)
#define AFX_RGB2YUVDOC_H__5E386A52_257F_4B8F_A0DD_42524C68113E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CRGB2YUVDoc : public CDocument
{
protected: // create from serialization only
	CRGB2YUVDoc();
	DECLARE_DYNCREATE(CRGB2YUVDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRGB2YUVDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CRGB2YUVDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CRGB2YUVDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RGB2YUVDOC_H__5E386A52_257F_4B8F_A0DD_42524C68113E__INCLUDED_)
