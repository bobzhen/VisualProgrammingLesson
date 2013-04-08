// FigureDoc.cpp : CFigureDoc 类的实现
//

#include "stdafx.h"
#include "Figure.h"

#include "FigureDoc.h"
#include "MainFrm.h "
#include "FigureView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFigureDoc

IMPLEMENT_DYNCREATE(CFigureDoc, CDocument)

BEGIN_MESSAGE_MAP(CFigureDoc, CDocument)
END_MESSAGE_MAP()


// CFigureDoc 构造/析构

CFigureDoc::CFigureDoc()
{
	// TODO: 在此添加一次性构造代码

}

CFigureDoc::~CFigureDoc()
{
}

BOOL CFigureDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CFigureDoc 序列化

void CFigureDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}


// CFigureDoc 诊断

#ifdef _DEBUG
void CFigureDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CFigureDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CFigureDoc 命令

BOOL CFigureDoc::OnSaveDocument(LPCTSTR lpszPathName)
{
	// TODO: 在此添加专用代码和/或调用基类
	CMainFrame *pMain = (CMainFrame *)AfxGetApp()->m_pMainWnd; 
	CFigureView *pView = (CFigureView *)pMain->GetActiveView();
	pView->m_imageFile.Save(lpszPathName);
	return TRUE;
}
