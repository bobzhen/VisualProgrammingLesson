#if !defined(AFX_DRAWTEST_H__50BC4C02_F5C9_4001_9FE0_6105B5E205DA__INCLUDED_)
#define AFX_DRAWTEST_H__50BC4C02_F5C9_4001_9FE0_6105B5E205DA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DrawTest.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDrawTest dialog

class CDrawTest : public CDialog
{
// Construction
public:
	CDrawTest(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDrawTest)
	enum { IDD = IDD_DIALOG1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

    void DrawWave(CDC *pDC);
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDrawTest)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL
private:
		CDC *pDC;             //屏幕绘图设备
		CDC memDC;            //内存绘图设备
		int m_High;           //绘图起点
		int m_Low;            //绘图终点
     	int m_lCount[1024];   //数据存储数组
		int m_now;            //记录波形当前点
// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDrawTest)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAWTEST_H__50BC4C02_F5C9_4001_9FE0_6105B5E205DA__INCLUDED_)
