// CTestSelDrawPicDoc.cpp : implementation of the CCTestSelDrawPicDoc class
//

#include "stdafx.h"
#include "CTestSelDrawPic.h"

#include "CTestSelDrawPicDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCTestSelDrawPicDoc

IMPLEMENT_DYNCREATE(CCTestSelDrawPicDoc, CDocument)

BEGIN_MESSAGE_MAP(CCTestSelDrawPicDoc, CDocument)
	//{{AFX_MSG_MAP(CCTestSelDrawPicDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCTestSelDrawPicDoc construction/destruction

CCTestSelDrawPicDoc::CCTestSelDrawPicDoc()
{
	// TODO: add one-time construction code here

}

CCTestSelDrawPicDoc::~CCTestSelDrawPicDoc()
{
}

BOOL CCTestSelDrawPicDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CCTestSelDrawPicDoc serialization

void CCTestSelDrawPicDoc::Serialize(CArchive& ar)
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
// CCTestSelDrawPicDoc diagnostics

#ifdef _DEBUG
void CCTestSelDrawPicDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCTestSelDrawPicDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCTestSelDrawPicDoc commands
