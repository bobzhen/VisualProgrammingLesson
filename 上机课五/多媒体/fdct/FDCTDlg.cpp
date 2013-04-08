// FDCTDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FDCT.h"
#include "FDCTDlg.h"
#include <math.h>
#include "winbase.h"  //To use Function GetTickCount();
#define PI 3.1415926
#define TIMEFREQ 300

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
///////////////////////
//// The global variables
double *C=NULL;
double *temp_2D=NULL;
//////////////////////////// 
///////////////////////////////////////

///// the global functions will be  declared here
UINT ThreadProcWriteFile(LPVOID pParam);
UINT ThreadProcOldDct(LPVOID pParam);
UINT ThreadProcfastDct(LPVOID pParam);
UINT ThreadProcOldIDct(LPVOID pParam);
UINT ThreadProcfastIDct(LPVOID pParam);


////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();
	
	// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA
	
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL
	
	// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
//{{AFX_MSG_MAP(CAboutDlg)
// No message handlers
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFDCTDlg dialog

CFDCTDlg::CFDCTDlg(CWnd* pParent /*=NULL*/)
: CDialog(CFDCTDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFDCTDlg)
	m_status = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFDCTDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFDCTDlg)
	DDX_Control(pDX, IDC_RADIO1, m_radio);
	DDX_Control(pDX, IDC_IDCT, m_IDCT);
	DDX_Control(pDX, IDC_DCT, m_DCT);
	DDX_Text(pDX, IDC_STATUS, m_status);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFDCTDlg, CDialog)
//{{AFX_MSG_MAP(CFDCTDlg)
ON_WM_SYSCOMMAND()
ON_WM_PAINT()
ON_WM_QUERYDRAGICON()
ON_BN_CLICKED(IDC_READ, OnRead)
ON_WM_TIMER()
ON_WM_CLOSE()
ON_BN_CLICKED(IDC_DCT, OnDct)
ON_BN_CLICKED(IDC_IDCT, OnIdct)
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFDCTDlg message handlers

BOOL CFDCTDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	// Add "About..." menu item to system menu.
	
	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);
	
	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}
	
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	
	this->m_loaded=false;
	
	this->data=NULL;
	this->m_buffer=NULL;
	this->m_status="运行信息在此显示!";
	this->m_radio.SetCheck(1);
	this->m_bHaveProcess=false;
	this->m_bDCTed=false;
	this->m_bIDCTed=false;
	this->m_bFreqImg=false;
	this->m_bTimeImg=false;
	//info=NULL;
	UpdateData(false);
	
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CFDCTDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CFDCTDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting
		
		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);
		
		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;
		
		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
		if(this->m_loaded)
		{DrawImg(data,this->m_col,this->m_row,25,25);
		}
		if(this->m_bFreqImg)
		{
			DrawFreqImg(m_buffer,m_row,m_col,25,300);
		}
		if(this->m_bTimeImg)
		{
			DrawImg(this->m_buffer,this->m_row,this->m_col,320,25);
		}
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.

HCURSOR CFDCTDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
void CFDCTDlg::CharData2DoubleData(char * ch,double *du)
{
	int i,j;
	for(i=0;i<this->m_row;i++)
		for(j=0;j<this->m_col;j++)
		{
			du[i*this->m_col+j]=(double)(unsigned char)ch[i*this->m_col+j];
		}
}

void CFDCTDlg::OnRead() 
{
	// TODO: Add your control notification handler code here
	if(this->m_loaded)
	{
		this->m_status="图像已经载入!\r\n不用重复载入!";
        this->UpdateData(false);
	}
	else
	{
		this->m_status="读入图像文件...............";
		this->UpdateData(false);
		CFile cf;
		if(!cf.Open("GIRL.img",CFile::modeRead))
		{
			MessageBox("当前目录下没有找到文件“GIRL.img”!");
			exit(1);
		}
		int len=cf.GetLength();
		data=new char[len];
		cf.Read(data,len);
		int col=(int)(sqrt((double)len));
		this->m_col=col;
		this->m_row=col;
		this->m_status="进行画图!";
		this->UpdateData(false);
		DrawImg(data,this->m_col,this->m_row,25,25);
		
		this->m_loaded=true;
		this->m_status="正在图像数据以文本的方式存入文件“原始时域数据.txt”";
		///数据转换
		this->m_buffer=(double *) new double[m_col*m_row];
		this->CharData2DoubleData(data,m_buffer);
		this->UpdateData(false);
		
		// info.str="";
		info.col=col;
		info.row=col;
		info.data=(unsigned char *)data;
		info.m_bfinished=false;
		info.m_start=0;
		info.m_end=0;
		this->m_bHaveProcess=true;
		SetTimer(1,TIMEFREQ,NULL);
		
		AfxBeginThread(ThreadProcWriteFile,&info);
	}
	
	
	
	
}

void WriteFile(CString filename, int row, int col, unsigned char *data)
{
	CStdioFile cf;
	if(!cf.Open(filename,CFile::modeCreate|CFile::modeWrite|CFile::typeText,NULL))
		exit(1);
	CString str,str1;
	int i,j;
	for(i=0;i<row;i++)
	   { str.Empty();
	for(j=0;j<col;j++)
	{str1.Format("%3d ",data[i*col+j]);
	str+=str1;
	}
	cf.WriteString(str);
	cf.WriteString("\r\n");
	}
	cf.Close();
	
}
void WriteFile(CString filename, int row, int col, double *data)
{
	CStdioFile cf;
	if(!cf.Open(filename,CFile::modeCreate|CFile::modeWrite|CFile::typeText,NULL))
		exit(1);
	CString str,str1;
	int i,j;
	for(i=0;i<row;i++)
	   { str.Empty();
	for(j=0;j<col;j++)
	{str1.Format("%10f\t ",data[i*col+j]);
	str+=str1;
	}
	cf.WriteString(str);
	}
	cf.Close();
	
}
UINT ThreadProcWriteFile(LPVOID pParam)
{
	RUNINFO *ptempinfo=(RUNINFO *)pParam;
	ptempinfo->m_start=::GetTickCount();
	WriteFile("原始时域数据.txt",ptempinfo->row,ptempinfo->col,(unsigned char *)ptempinfo->data);
	ptempinfo->m_end=::GetTickCount();
	ptempinfo->m_bfinished=true;
	
	return 1;
	
	
}

void CFDCTDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	//this->UpdateData(false);
	CString strTemp;
	if(info.m_bfinished)
	{   
		strTemp.Format("\r\n使用了%d毫秒!",info.m_end-info.m_start);
		if(nIDEvent==1)
		{ KillTimer(1);		
		this->m_status="图像数据写入完毕!"+strTemp;
		this->m_bHaveProcess=false;
		this->UpdateData(false);
		}
		strTemp.Format("\r\n变换过程使用了%d毫秒!\r\n把数据写入文件使用了%d毫秒!",info.m_end-info.m_start,::GetTickCount()-info.m_end);
		if(nIDEvent==2)
		{			
			KillTimer(2);
			this->m_bIDCTed=false;
			this->m_bDCTed=true;
			this->m_status="普通DCT变换完成!"+strTemp+"\r\n数据见文件“普通DCT变换后的数据.txt”\r\n进行画图...";
			this->m_bHaveProcess=false;
			this->UpdateData(false);
			DrawFreqImg(m_buffer,m_row,m_col,25,300);
			this->m_bFreqImg=true;
			this->m_bTimeImg=false;
			
		}
		if(nIDEvent==3)
		{  			
			KillTimer(3);
			this->m_bIDCTed=false;
			this->m_bDCTed=true;			
			this->m_status="快速DCT变换完成!"+strTemp+"\r\n数据见文件“快速DCT变换后的数据.txt”\r\n进行画图...";
			this->m_bHaveProcess=false;
			this->UpdateData(false);
			DrawFreqImg(m_buffer,m_row,m_col,25,300);
			this->m_bFreqImg=true;
			this->m_bTimeImg=false;
			
		}
		if(nIDEvent==4)
		{  			
			KillTimer(2);
			this->m_bIDCTed=true;
			this->m_bDCTed=false;
			this->m_status="普通IDCT变换完成!"+strTemp+"\r\n数据见文件“普通IDCT变换后的数据.txt”\r\n进行画图...";
			this->m_bHaveProcess=false;
			this->UpdateData(false);
			DrawImg(this->m_buffer,this->m_row,this->m_col,320,25);
			this->m_bTimeImg=true;
			this->m_bFreqImg=false;
			
		}
		if(nIDEvent==5)
		{ 			
			KillTimer(5);
			this->m_bIDCTed=true;
			this->m_bDCTed=false;
			this->m_status="快速IDCT变换完成!"+strTemp+"\r\n数据见文件“快速IDCT变换后的数据.txt\r\n进行画图...”";
			this->m_bHaveProcess=false;
			this->UpdateData(false);
			DrawImg(this->m_buffer,this->m_row,this->m_col,320,25);
			this->m_bTimeImg=true;
			this->m_bFreqImg=false;
			
		}
	}
	else
	{ static int iTemp=0;
	   iTemp++;
	   strTemp.Format("\r\n已经使用了%d毫秒了!",::GetTickCount()-info.m_start);
	   if(!(iTemp%10))
		   this->m_status.Empty();
	   this->m_status+=strTemp;
	   UpdateData(false);
	   
	}
	CDialog::OnTimer(nIDEvent);
}

void CFDCTDlg::WriteFile(CString filename, int row, int col, double *data)
{
	CStdioFile cf;
	if(!cf.Open(filename,CFile::modeCreate|CFile::modeWrite|CFile::typeText,NULL))
		exit(1);
	CString str,str1;
	int i,j;
	for(i=0;i<row;i++)
	   { str.Empty();
	for(j=0;j<col;j++)
	{str1.Format("%8f ",data[i*col+j]);
	str+=str1;
	}
	cf.WriteString(str);
	}
	cf.Close();
	
}

void CFDCTDlg::DrawImg(char *src, int cx, int cy, int x, int y)
{
	CDC *pDC=GetDC();
	unsigned char temp;
	for(int i=0;i<cy;i++)
	   {	for(int j=0;j<cx;j++)
	{	temp=(unsigned char)src[i*cx+j];
	pDC->SetPixel(j+x,i+y,RGB(temp,temp,temp));
	
	}
	
	   
	}
	
	ReleaseDC(pDC);
	
}
void CFDCTDlg::DrawImg(double *src, int cx, int cy, int x, int y)
{
	CDC *pDC=GetDC();
	unsigned char temp;
	for(int i=0;i<cy;i++)
	{
		
		for(int j=0;j<cx;j++)
		{	temp=(unsigned char)src[i*cx+j];
		pDC->SetPixel(j+x,i+y,RGB(temp,temp,temp));
		
		}
		
		
	}
	
	ReleaseDC(pDC);
	
}
void CFDCTDlg::DrawFreqImg(double *src, int cx, int cy, int x, int y)
{  
	int i,j;
	double len,temp,nMax=-1000,nMin=1000;
	for(i=0;i<cy;i++)
		for(j=0;j<cx;j++)
		{ temp=src[i*cx+j];
		if(temp>nMax)
			nMax=temp;
		if(temp<nMin)
			nMin=temp;
		
		}
		len=nMax-nMin;
		if(len<0)
		{
			this->m_status="频域数据有误!\r\n未画频域数据!";
			UpdateData(false);
		}
		else
		{  CDC *pDC=GetDC();
		unsigned char tempchar;
		for( i=0;i<cy;i++)
		{
			
			for( j=0;j<cx;j++)
			{	
				tempchar=int(src[i*cx+j]/len*255);
				pDC->SetPixel(j+x,i+y,RGB(tempchar,tempchar,tempchar));
				
			}
			
			
		}
		
		ReleaseDC(pDC);
		
		}
		
		
}

void CFDCTDlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	if(data!=NULL) delete []data;
	if(m_buffer!=NULL) delete []m_buffer;
	
	CDialog::OnClose();
}

void CFDCTDlg::OnDct() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	if(!this->m_loaded)
	{
		MessageBox("请先读入图像数据!");
		return;
	}
	else
	{
		if(this->m_bDCTed)
		{
			this->m_status="已经进行过DCT变换!";
			UpdateData(false);
		}
		else
		{
			if(this->m_radio.GetCheck())
			{ 
				if(this->m_bHaveProcess)
				{
					this->m_status="另一进程正在运行中，请稍等!";
					UpdateData(false);
				}
				else
				{ this->m_status="进行普通DCT变换.......";
				UpdateData(false);
				info.col=m_col;
				info.row=m_row;
				info.m_bfinished=false;
				info.data=(double *)m_buffer;
				info.m_start=0;
				info.m_end=0;
				SetTimer(2,TIMEFREQ,NULL);
				AfxBeginThread(ThreadProcOldDct,&info);
				this->m_bHaveProcess=true;
				}
				
			}
			else
			{
				if(this->m_bHaveProcess)
				{
					this->m_status="另一进程正在运行中，请稍等!";
					UpdateData(false);
				}
				else
				{ this->m_status="进行快速DCT变换.......";
				UpdateData(false);
				info.col=m_col;
				info.row=m_row;
				info.m_bfinished=false;
				info.data=(double *)m_buffer;
				info.m_start=0;
				info.m_end=0;
				SetTimer(3,TIMEFREQ,NULL);
				AfxBeginThread(ThreadProcfastDct,&info);
				this->m_bHaveProcess=true;
				}
				
				
			}
		}
	}
}

void CFDCTDlg::OnIdct() 
{    
	// TODO: Add your control notification handler code here
	UpdateData(true);
	if(!this->m_loaded)
	{
		MessageBox("请先读入图像数据!");
		return;
		
	}
	else if(!this->m_bDCTed)
	{
		MessageBox("请先进行DCT变换!");
		return;
	}
	else
	{
		if(this->m_bIDCTed)
		{
			this->m_status="已经进行过IDCT变换!";
			UpdateData(false);
		}
		else{
			if(this->m_radio.GetCheck())
			{
				if(this->m_bHaveProcess)
				{
					this->m_status="另一进程正在运行中，请稍等!";
					UpdateData(false);
				}
				else
				{ this->m_status="进行普通IDCT变换.......";
				UpdateData(false);
				info.col=m_col;
				info.row=m_row;
				info.m_bfinished=false;
				info.data=(double *)m_buffer;
				info.m_start=0;
				info.m_end=0;
				SetTimer(4,TIMEFREQ,NULL);
				AfxBeginThread(ThreadProcOldIDct,&info);
				this->m_bHaveProcess=true;
				}
				
			}
			else
			{
				if(this->m_bHaveProcess)
				{
					this->m_status="另一进程正在运行中，请稍等!";
					UpdateData(false);
				}
				else
				{ this->m_status="进行快速IDCT变换.......";
				UpdateData(false);
				info.col=m_col;
				info.row=m_row;
				info.m_bfinished=false;
				info.data=(double *)m_buffer;
				info.m_start=0;
				info.m_end=0;
				SetTimer(5,TIMEFREQ,NULL);
				AfxBeginThread(ThreadProcfastIDct,&info);
				this->m_bHaveProcess=true;
				}
				
			}
		}
	}
}

void initIDCTParam(int deg)
{
	int total,halftotal,i,group,endstart,factor;
	total=1<<deg;
	if(C!=NULL) delete []C;
	C=(double *)new double[total];
	halftotal=total>>1;
	for(i=0;i<halftotal;i++)
		C[total-i-1]=(double)(2*i+1);
	
	for(group=0;group<deg-1;group++)
	{ 
		endstart=1<<(deg-1-group);
		int len=endstart>>1;
		factor=1<<(group+1);
		for(int j=0;j<len;j++)
			C[endstart-j-1]=factor*C[total-j-1];
	}
	for(i=1;i<total;i++)
		C[i]=1.0/(2.0*cos(C[i]*PI/(total<<1)));	
	
}

/* void fdct1(double *src,double *dst,int dg,int *deg)
{
if(*deg==1)
{
*dst=*src+*(src+1);
*(dst+1)=(*src-*(src+1))*cos(PI/4);
return;
}
else
{   
int len=1<<(*deg-dg);
for(int i=0;i<1<<(dg-1);i++)
*(dst+len*i)=*(dst+len*i)+*(dst+len*(1<<dg-i*len));
fdct1(src,dst,dg-1,deg);
for(i=0;i<1<<(dg-1);i++)
{
*(dst+len*i+1<<(deg-dg))=*(src+len*i+1<<(deg-dg))+*(src+len*(1<<dg-i*len)+1<<(deg-dg));
}
fdct1(src+1<<(deg-dg),dst+1<<(deg-dg),dg-1,deg);

  
	}
	
      
		}
		
*/
/* void oldDCT1(double *src,double *dst,int deg)
{

  int total=1<<deg;
  memset(dst,0,total*sizeof(double));
  for(int i=0;i<total;i++)
	 for(int j=0;j<total;j++)
	 {dst[i]+=src[j]*cos(PI/(2*total)*i*(2*j+1));}
	 // if(i==0)
	 //	 dst[i]=1/sqrt(2)*dst[i];
	 
	   
		 
}*/
int bitrev(int bi,int deg)
{
	int j=1,temp=0,degnum,halfnum;
	degnum=deg;
	//if(deg<0) return 0;
	if(deg==0) return bi;
	halfnum=1<<(deg-1);
	while(halfnum)
	{
		if(halfnum&bi)
			temp+=j;
		j<<=1;
		halfnum>>=1;
	}
	return temp;	
}
void fbitrev(double *f,int deg)
{    
	if(deg==1) return;
	int len=(1<<deg)-1;
	int i=1;
	int ii;
	double temp;
	while(i<len)
	{   ii=bitrev(i,deg); 
	if(ii>i)
	{  temp=f[ii];
		  f[ii]=f[i];
		  f[i]=temp;
	}
	i++;
	}
}

void swap(double &a,double &b)
{
	double temp;
	temp=a;
	a=b;
	b=temp;
}
void initDCTParam(int deg)
{
	int total,halftotal,i,group,endstart,factor;
	total=1<<deg;
	if(C!=NULL) delete []C;
	C=(double *)new double[total];
	halftotal=total>>1;
	for(i=0;i<halftotal;i++)
		C[total-i-1]=(double)(2*i+1);
	
	for(group=0;group<deg-1;group++)
	{ 
		endstart=1<<(deg-1-group);
		int len=endstart>>1;
		factor=1<<(group+1);
		for(int j=0;j<len;j++)
			C[endstart-j-1]=factor*C[total-j-1];
	}
	for(i=1;i<total;i++)
		C[i]=2.0*cos(C[i]*PI/(total<<1));	
	
}
void dct_forward(double *f,int deg)
{
	int i_deg,i_halfwing,total,wing,wings,winglen,halfwing;
	double temp1,temp2;
	total=1<<deg;
	for(i_deg=0;i_deg<deg;i_deg++)
	{
		wings=1<<i_deg;
		winglen=total>>i_deg;
		halfwing=winglen>>1;
		for(wing=0;wing<wings;wing++)
		{
			for(i_halfwing=0;i_halfwing<halfwing;i_halfwing++)
			{
				temp1=f[wing*winglen+i_halfwing];
				temp2=f[(wing+1)*winglen-1-i_halfwing];
				if(wing%2)
					swap(temp1,temp2);
				f[wing*winglen+i_halfwing]=temp1+temp2;
				f[(wing+1)*winglen-1-i_halfwing]=(temp1-temp2)*C[winglen-1-i_halfwing];
			}
		}
	}
}
void idct_backward(double *F,int deg)
{
	int i_deg,i_halfwing,total,wing,wings,winglen,halfwing;
	double temp1,temp2;
	total=1<<deg;
	for(i_deg=deg-1;i_deg>=0;i_deg--)
	{
		wings=1<<i_deg;
		winglen=total>>i_deg;
		halfwing=winglen>>1;
		for(wing=0;wing<wings;wing++)
		{
			for(i_halfwing=0;i_halfwing<halfwing;i_halfwing++)
			{
				temp1=F[wing*winglen+i_halfwing];
				temp2=F[(wing+1)*winglen-1-i_halfwing]*C[winglen-1-i_halfwing];
                if(wing%2)
				{
					F[wing*winglen+i_halfwing]=(temp1-temp2)*0.5;
					F[(wing+1)*winglen-1-i_halfwing]=(temp1+temp2)*0.5;
				}
				else
				{
					F[wing*winglen+i_halfwing]=(temp1+temp2)*0.5;
					F[(wing+1)*winglen-1-i_halfwing]=(temp1-temp2)*0.5;
				}
				
			}
		}
	}
	
}
void dct_backward(double *f,int deg)
{
	int total,i_deg,wing,wings,halfwing,winglen,i_halfwing,temp1,temp2;
    total=1<<deg;
	for(i_deg=deg-1;i_deg>=0;i_deg--)
	{
		wings=1<<i_deg;
		winglen=1<<(deg-i_deg);
		halfwing=winglen>>1;
		for(wing=0;wing<wings;wing++)
		{
			for(i_halfwing=0;i_halfwing<halfwing;i_halfwing++)
			{  //f[i_halfwing+wing*winglen]=f[i_halfwing+wing*winglen];
				if(i_halfwing==0)
					f[halfwing+wing*winglen+i_halfwing]=0.5*f[halfwing+wing*winglen+i_halfwing];
				else
				{
					temp1=bitrev(i_halfwing,deg-i_deg-1);
					temp2=bitrev(i_halfwing-1,deg-i_deg-1);
					f[halfwing+wing*winglen+temp1]=f[halfwing+wing*winglen+temp1]-f[halfwing+wing*winglen+temp2];
				}	
			}
		}
	}
}
void idct_forward(double *F,int deg)
{
	int total,i_deg,wing,wings,halfwing,winglen,i_halfwing,temp1,temp2;
    total=1<<deg;
	for(i_deg=0;i_deg<deg;i_deg++)
	{
		wings=1<<i_deg;
		winglen=1<<(deg-i_deg);
		halfwing=winglen>>1;
		for(wing=0;wing<wings;wing++)
		{
			for(i_halfwing=halfwing-1;i_halfwing>=0;i_halfwing--)
			{
				if(i_halfwing==0)
					F[halfwing+wing*winglen+i_halfwing]=2.0*F[halfwing+wing*winglen+i_halfwing];
				else
				{ 
					temp1=bitrev(i_halfwing,deg-i_deg-1);
					temp2=bitrev(i_halfwing-1,deg-i_deg-1);
					F[halfwing+wing*winglen+temp1]=F[halfwing+wing*winglen+temp1]+F[halfwing+wing*winglen+temp2];
				}
				
			}
		}
		
	}
	
} 
void fidct_1D_no_param(double *F,int deg)
{
	initIDCTParam(deg);
	F[0]=F[0]*sqrt(2.0);
	fbitrev(F,deg);
	idct_forward(F,deg);
	idct_backward(F,deg);
	
}

void fdct_1D_no_param(double *f,int deg)
{
	initDCTParam(deg);
	dct_forward(f,deg);
	dct_backward(f,deg);
	fbitrev(f,deg);
	f[0]=1/(sqrt(2.0))*f[0];
}
void fidct_1D(double *F,int deg)
{
	int total=1<<deg;
	double param=sqrt((double)total/2.0);
	for(int i=0;i<total;i++)
	{
		F[i]=param*F[i];
	}
	fidct_1D_no_param(F,deg);
}
void fdct_1D(double *f,int deg)
{
	fdct_1D_no_param(f,deg);
	int total=1<<deg;
	double param=sqrt(2.0/total);
	for(int i=0;i<total;i++)
		f[i]=param*f[i];
}

void init2D_Param(int rows,int cols)
{
	if(temp_2D!=NULL) delete[] temp_2D;
	temp_2D=(double *) new double[rows];
}
void fdct_2D(double *f,int deg_row,int deg_col)
{    
	
	int rows,cols,i_row,i_col;
	double	two_div_sqrtcolrow;
	rows=1<<deg_row;
	cols=1<<deg_col;
	init2D_Param(rows,cols);
	two_div_sqrtcolrow=2.0/(sqrt((double)(rows*cols)));
	
	for(i_row=0;i_row<rows;i_row++)
	{
		fdct_1D_no_param(f+i_row*cols,deg_col);
	}
	for(i_col=0;i_col<cols;i_col++)
	{
		for(i_row=0;i_row<rows;i_row++)
		{
			temp_2D[i_row]=f[i_row*cols+i_col];
		}
		fdct_1D_no_param(temp_2D,deg_row);
		for(i_row=0;i_row<rows;i_row++)
		{
			f[i_row*cols+i_col]=temp_2D[i_row]*two_div_sqrtcolrow;
		}
		
	}
	
}
void fidct_2D(double *F,int deg_row,int deg_col)
{    
	
	int rows,cols,i_row,i_col;
	double	sqrtcolrow_div_two;
	rows=1<<deg_row;
	cols=1<<deg_col;
	init2D_Param(rows,cols);
	sqrtcolrow_div_two=(sqrt((double)(rows*cols)))/2.0;
	
	for(i_row=0;i_row<rows;i_row++)
	{
		fidct_1D_no_param(F+i_row*cols,deg_col);
	}
	for(i_col=0;i_col<cols;i_col++)
	{
		for(i_row=0;i_row<rows;i_row++)
		{
			temp_2D[i_row]=F[i_row*cols+i_col];
		}
		fidct_1D_no_param(temp_2D,deg_row);
		for(i_row=0;i_row<rows;i_row++)
		{
			F[i_row*cols+i_col]=temp_2D[i_row]*sqrtcolrow_div_two;
		}
		
	}
	
}
void oldDCT(double *f,int row_deg,int col_deg)
{
	int u,v,x,y,cols,rows;
	
	
	cols=1<<col_deg;
	rows=1<<row_deg;
	double one_div_sqrtcolrow=1.0/sqrt((double)(cols*rows));
	double sqrt_two_colrow=sqrt(2.0/(cols*rows));
	double  two_div_sqrtcolrow=2.0/(sqrt((double)cols*rows));
	
	double *temp=(double *)malloc(cols*rows*sizeof(double));
	if(temp==NULL)
	{
		return;
	}
	memcpy(temp,f,cols*rows*sizeof(double));
	memset(f,0,cols*rows*sizeof(double));
	for( u=0;u<rows;u++)
		for( v=0;v<cols;v++)
		{      for( x=0;x<rows;x++)
		for( y=0;y<cols;y++)
		{
			f[u*cols+v]+=temp[x*cols+y]*cos((2*x+1)*u*PI/(2*cols))*cos((2*y+1)*v*PI/(2*rows));
		}
		
		if(u==0 && v==0)
			f[u*cols+v]=one_div_sqrtcolrow*f[u*cols+v];
		else if(v!=0 || u!=0)
			f[u*cols+v]=sqrt_two_colrow*f[u*cols+v];
		else 
			f[u*cols+v]=two_div_sqrtcolrow*f[u*cols+v];
		//f[u*cols+v]=four_div_colrow*f[u*cols+v];
		}
		delete temp;
}
void oldIDCT(double *F,int row_deg, int col_deg)
{
	int u,v,x,y,rows,cols;
	rows=1<<row_deg;
	cols=1<<col_deg;
	double one_div_sqrtcolrow=1.0/sqrt((double)cols*rows);
	double sqrt_two_colrow=sqrt(2.0/(cols*rows));
	double  two_div_sqrtcolrow=2.0/(sqrt((double)cols*rows));
	double *temp=(double *)malloc(cols*rows*sizeof(double));
	if(temp==NULL)
	{
		return;
	}
	memcpy(temp,F,cols*rows*sizeof(double));
	memset(F,0,cols*rows*sizeof(double));
	for( x=0;x<cols;x++)
		for( y=0;y<rows;y++)
			for( u=0;u<cols;u++)
				for( v=0;v<rows;v++)
				{ 
					if(u==0 && v==0)
						F[x*rows+y]+=one_div_sqrtcolrow*temp[u*rows+v]*cos((2*x+1)*u*PI/(2*cols))*cos((2*y+1)*v*PI/(2*rows));
                    else if(u==0 || v==0)
						F[x*rows+y]+=sqrt_two_colrow*temp[u*rows+v]*cos((2*x+1)*u*PI/(2*cols))*cos((2*y+1)*v*PI/(2*rows));
					else F[x*rows+y]+=two_div_sqrtcolrow*temp[u*rows+v]*cos((2*x+1)*u*PI/(2*cols))*cos((2*y+1)*v*PI/(2*rows));
				}
}
int GetTwoIndex(int num)
{
	int temp=0;
	if(num<=0) return -1;
	while(1<<temp<num)
		temp++;
	return temp;
	
	
}
UINT ThreadProcOldDct(LPVOID pParam)
{
	RUNINFO *pinfo=(RUNINFO*)pParam;
	pinfo->m_start=::GetTickCount();
	oldDCT((double *)pinfo->data,GetTwoIndex(pinfo->row),GetTwoIndex(pinfo->col));
	pinfo->m_end=::GetTickCount();
	WriteFile("普通DCT变换后的数据.txt",pinfo->row,pinfo->col,(double *)pinfo->data);
	pinfo->m_bfinished=true;
	return 1;
	
}
UINT ThreadProcfastDct(LPVOID pParam)
{
	RUNINFO *pinfo=(RUNINFO*)pParam;
	
	pinfo->m_start=::GetTickCount();
	fdct_2D((double *)pinfo->data,GetTwoIndex(pinfo->row),GetTwoIndex(pinfo->col));
	pinfo->m_end=::GetTickCount();
	WriteFile("快速DCT变换后的数据.txt",pinfo->row,pinfo->col,(double *)pinfo->data);
	pinfo->m_bfinished=true;
	return 1;
}
UINT ThreadProcOldIDct(LPVOID pParam)
{
	RUNINFO *pinfo=(RUNINFO*)pParam;
	pinfo->m_start=::GetTickCount();
	oldIDCT((double *)pinfo->data,GetTwoIndex(pinfo->row),GetTwoIndex(pinfo->col));
	pinfo->m_end=::GetTickCount();
	WriteFile("普通IDCT变换后的数据.txt",pinfo->row,pinfo->col,(double *)pinfo->data);
	pinfo->m_bfinished=true;
	return 1;
	
}
UINT ThreadProcfastIDct(LPVOID pParam)
{
	
	RUNINFO *pinfo=(RUNINFO*)pParam;
	pinfo->m_start=::GetTickCount();
	fidct_2D((double *)pinfo->data,GetTwoIndex(pinfo->row),GetTwoIndex(pinfo->col));
	pinfo->m_end=::GetTickCount();
	WriteFile("快速IDCT变换后的数据.txt",pinfo->row,pinfo->col,(double *)pinfo->data);
	pinfo->m_bfinished=true;
	return 1;
}






