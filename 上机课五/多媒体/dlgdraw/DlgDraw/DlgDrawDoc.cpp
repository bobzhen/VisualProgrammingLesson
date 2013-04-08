// DlgDrawDoc.cpp : implementation of the CDlgDrawDoc class
//

#include "stdafx.h"
#include "DlgDraw.h"

#include "DlgDrawDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgDrawDoc

IMPLEMENT_DYNCREATE(CDlgDrawDoc, CDocument)

BEGIN_MESSAGE_MAP(CDlgDrawDoc, CDocument)
	//{{AFX_MSG_MAP(CDlgDrawDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgDrawDoc construction/destruction

CDlgDrawDoc::CDlgDrawDoc()
{
	// TODO: add one-time construction code here

}

CDlgDrawDoc::~CDlgDrawDoc()
{
}

BOOL CDlgDrawDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDlgDrawDoc serialization

void CDlgDrawDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CDlgDrawDoc diagnostics

#ifdef _DEBUG
void CDlgDrawDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDlgDrawDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDlgDrawDoc commands
