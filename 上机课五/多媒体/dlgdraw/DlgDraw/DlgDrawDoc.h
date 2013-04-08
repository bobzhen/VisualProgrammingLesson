// DlgDrawDoc.h : interface of the CDlgDrawDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DLGDRAWDOC_H__6FEA0652_960F_4FA1_9D2B_03C2C2480473__INCLUDED_)
#define AFX_DLGDRAWDOC_H__6FEA0652_960F_4FA1_9D2B_03C2C2480473__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDlgDrawDoc : public CDocument
{
protected: // create from serialization only
	CDlgDrawDoc();
	DECLARE_DYNCREATE(CDlgDrawDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgDrawDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDlgDrawDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDlgDrawDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGDRAWDOC_H__6FEA0652_960F_4FA1_9D2B_03C2C2480473__INCLUDED_)
