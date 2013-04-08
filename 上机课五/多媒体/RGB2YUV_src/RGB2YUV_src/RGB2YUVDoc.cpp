// RGB2YUVDoc.cpp : implementation of the CRGB2YUVDoc class
//

#include "stdafx.h"
#include "RGB2YUV.h"

#include "RGB2YUVDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRGB2YUVDoc

IMPLEMENT_DYNCREATE(CRGB2YUVDoc, CDocument)

BEGIN_MESSAGE_MAP(CRGB2YUVDoc, CDocument)
	//{{AFX_MSG_MAP(CRGB2YUVDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRGB2YUVDoc construction/destruction

CRGB2YUVDoc::CRGB2YUVDoc()
{
	// TODO: add one-time construction code here

}

CRGB2YUVDoc::~CRGB2YUVDoc()
{
}

BOOL CRGB2YUVDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CRGB2YUVDoc serialization

void CRGB2YUVDoc::Serialize(CArchive& ar)
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
// CRGB2YUVDoc diagnostics

#ifdef _DEBUG
void CRGB2YUVDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRGB2YUVDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRGB2YUVDoc commands
