// CTestSelDrawPicDoc.h : interface of the CCTestSelDrawPicDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CTESTSELDRAWPICDOC_H__2224264E_37BE_480E_AA4B_2354C45EF65C__INCLUDED_)
#define AFX_CTESTSELDRAWPICDOC_H__2224264E_37BE_480E_AA4B_2354C45EF65C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CCTestSelDrawPicDoc : public CDocument
{
protected: // create from serialization only
	CCTestSelDrawPicDoc();
	DECLARE_DYNCREATE(CCTestSelDrawPicDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCTestSelDrawPicDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCTestSelDrawPicDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCTestSelDrawPicDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CTESTSELDRAWPICDOC_H__2224264E_37BE_480E_AA4B_2354C45EF65C__INCLUDED_)
