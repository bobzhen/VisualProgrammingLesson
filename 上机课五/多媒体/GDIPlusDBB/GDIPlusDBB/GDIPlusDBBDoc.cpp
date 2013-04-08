// GDIPlusDBBDoc.cpp : implementation of the CGDIPlusDBBDoc class
//

#include "stdafx.h"
#include "GDIPlusDBB.h"

#include "GDIPlusDBBDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGDIPlusDBBDoc

IMPLEMENT_DYNCREATE(CGDIPlusDBBDoc, CDocument)

BEGIN_MESSAGE_MAP(CGDIPlusDBBDoc, CDocument)
	//{{AFX_MSG_MAP(CGDIPlusDBBDoc)
	ON_COMMAND(ID_MAP1, OnMap1)
	ON_COMMAND(ID_MAP2, OnMap2)
	ON_COMMAND(ID_MAP3, OnMap3)
	ON_COMMAND(ID_FILE_NEW, OnFileNew)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGDIPlusDBBDoc construction/destruction

CGDIPlusDBBDoc::CGDIPlusDBBDoc()
{
	// 初始化
	m_pStrMapName = _T("");
	m_pStrMapPath = _T("");

	//AfxMessageBox(GetEXEPath());
	m_pStrMapPath = GetEXEPath();
}

CGDIPlusDBBDoc::~CGDIPlusDBBDoc()
{
}

BOOL CGDIPlusDBBDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CGDIPlusDBBDoc serialization

void CGDIPlusDBBDoc::Serialize(CArchive& ar)
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
// CGDIPlusDBBDoc diagnostics

#ifdef _DEBUG
void CGDIPlusDBBDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CGDIPlusDBBDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGDIPlusDBBDoc commands

// 地图一
void CGDIPlusDBBDoc::OnMap1() 
{
	m_pStrMapName = "shanghai.JPG";
	m_pStrMapName.MakeLower();

	this->UpdateAllViews(NULL);
}

// 地图二
void CGDIPlusDBBDoc::OnMap2() 
{
	m_pStrMapName = "shaoxing.JPG";
	m_pStrMapName.MakeLower();

	this->UpdateAllViews(NULL);
}

// 地图三
void CGDIPlusDBBDoc::OnMap3() 
{
	m_pStrMapName = "taiyuan.JPG";
	m_pStrMapName.MakeLower();

	this->UpdateAllViews(NULL);
}

// 获得程序路径
CString CGDIPlusDBBDoc::GetEXEPath()
{
	char chPath[MAX_PATH] = "";
	GetModuleFileName(NULL, chPath, MAX_PATH);
	(strrchr(chPath,'\\'))[1] = 0; 

	CString pStrResult(chPath);
	return pStrResult;
}

// 中国地图
void CGDIPlusDBBDoc::OnFileNew() 
{
	m_pStrMapName = "china.JPG";
	m_pStrMapName.MakeLower();

	this->UpdateAllViews(NULL);
}
