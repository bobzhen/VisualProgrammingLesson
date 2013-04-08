// RGB2YUVView.cpp : implementation of the CRGB2YUVView class
// 作者：李英江
// 日期：2007-08-05
// 功能：实现RBG与YUV相互转换
// 版权：你可以任意使用我的源码^_^，
// 我的网站：http://www.cgsir.com

#include "stdafx.h"
#include "RGB2YUV.h"

#include "RGB2YUVDoc.h"
#include "RGB2YUVView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRGB2YUVView

IMPLEMENT_DYNCREATE(CRGB2YUVView, CView)

BEGIN_MESSAGE_MAP(CRGB2YUVView, CView)
	//{{AFX_MSG_MAP(CRGB2YUVView)
	ON_COMMAND(ID_READ_BMP, OnReadBmp)
	ON_COMMAND(ID_CONVERT_PAL, OnConvertPAL)
	ON_COMMAND(ID_READ_PAL, OnReadPAL)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRGB2YUVView construction/destruction

CRGB2YUVView::CRGB2YUVView()
{
	// TODO: add construction code here

}

CRGB2YUVView::~CRGB2YUVView()
{
}

BOOL CRGB2YUVView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CRGB2YUVView drawing

void CRGB2YUVView::OnDraw(CDC* pDC)
{
	CRGB2YUVDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CRGB2YUVView diagnostics

#ifdef _DEBUG
void CRGB2YUVView::AssertValid() const
{
	CView::AssertValid();
}

void CRGB2YUVView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRGB2YUVDoc* CRGB2YUVView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRGB2YUVDoc)));
	return (CRGB2YUVDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRGB2YUVView message handlers

// 隔行显示BMP
void CRGB2YUVView::OnReadBmp() 
{
	// TODO: Add your command handler code here
	CDC *pDC = GetDC();
	
	CRect rect;
	CBrush brush(RGB(128,128,128));
	GetClientRect(&rect);
	pDC->FillRect(&rect, &brush);

	BITMAPFILEHEADER bmfh;
	BITMAPINFOHEADER bmih;

    char strFileName[MAX_PATH]="720bmp.bmp";
	CFile* f;
	f = new CFile();
	f->Open(strFileName, CFile::modeRead);
	f->SeekToBegin();
	f->Read(&bmfh, sizeof(bmfh));
	f->Read(&bmih, sizeof(bmih));
  
    // 分配图片像素内存
    RGBTRIPLE *rgb;
	rgb = new RGBTRIPLE[bmih.biWidth*bmih.biHeight];

	f->SeekToBegin();
	f->Seek(54,CFile::begin); // BMP 54个字节之后的是像素数据
	f->Read(rgb, bmih.biWidth * bmih.biHeight * 3);	 // 这里只读24位RGB(r,g,b)图像
	
	// 显示上场 (奇数行组成的奇数场)
	for (int i = 0; i<bmih.biHeight; i++) {
		for (int j = 0; j<bmih.biWidth; j++) {
			if(!(i%2))
				pDC->SetPixel(j, bmih.biHeight-i, RGB(rgb[i*bmih.biWidth+j].rgbtRed,rgb[i*bmih.biWidth+j].rgbtGreen,rgb[i*bmih.biWidth+j].rgbtBlue));
			for (int k=0; k<1000; k++) ;  //延时
		}
	}

    Sleep(500);

    // 显示下场 (偶数行组成的偶数场)
	for (int i_ = 0; i_<bmih.biHeight; i_++) {
		for (int j_ = 0; j_<bmih.biWidth; j_++) {
			if(i_%2)
				pDC->SetPixel(j_, bmih.biHeight-i_, RGB(rgb[i_*bmih.biWidth+j_].rgbtRed,rgb[i_*bmih.biWidth+j_].rgbtGreen,rgb[i_*bmih.biWidth+j_].rgbtBlue));
			for (int k=0; k<1000; k++) ;  //延时
		}
	}

	// 显示24位BMP信息
	LONG dwWidth = bmih.biWidth;
	LONG dwHeight = bmih.biHeight;
	WORD wBitCount = bmih.biBitCount;
	char buffer[80];
	sprintf(buffer,"图像宽为：%ld 高为：%ld 像数位数：%d", dwWidth, dwHeight, wBitCount);
	MessageBox(buffer, "每个像素的位数", MB_OK | MB_ICONINFORMATION);
	
	f->Close();
	delete f;
	delete rgb;
}

// RGB转换为YUV
void CRGB2YUVView::RGB2YUV(byte *pRGB, byte *pYUV)
{
	byte r,g,b;
	r = *pRGB; pRGB++;
	g = *pRGB; pRGB++;
	b = *pRGB; 
	
	*pYUV = static_cast<byte>(0.257*r + 0.504*g + 0.098*b + 16);    pYUV++;   // y
	*pYUV = static_cast<byte>(-0.148*r - 0.291*g + 0.439*b + 128);  pYUV++;   // u
	*pYUV = static_cast<byte>(0.439*r - 0.368*g - 0.071*b + 128);             // v
}

// 转换RGB
void CRGB2YUVView::OnConvertPAL() 
{
	CDC *pDC = GetDC();
	CRect rect;
	CBrush brush(RGB(128,128,128));
	GetClientRect(&rect);
	pDC->FillRect(&rect, &brush);

	// PAL 720x576 : 中国的电视标准为PAL制	
	int CurrentXRes = 720;
	int CurrentYRes = 576;
	int size        = CurrentXRes * CurrentYRes;
    
	// 分配内存
	byte *Video_Field0 = (byte*)malloc(CurrentXRes*CurrentYRes);  
	byte *Video_Field1 = (byte*)malloc(CurrentXRes*CurrentYRes);
	
	// 保存内存指针
	byte *Video_Field0_ = Video_Field0;
	byte *Video_Field1_ = Video_Field1;

	byte yuv_y0, yuv_u0, yuv_v0, yuv_v1;  // {y0, u0, v0, v1};
	byte bufRGB[3];  // 临时保存{R,G,B}
	byte bufYUV[3];  // 临时保存{Y,U,V}

	// 初始化数组空间
    ZeroMemory(bufRGB, sizeof(byte)*3);
	ZeroMemory(bufYUV, sizeof(byte)*3);

	// 初始化内存
	ZeroMemory(Video_Field0, CurrentXRes*CurrentYRes);
	ZeroMemory(Video_Field1, CurrentXRes*CurrentYRes);
	
	// BMP 位图操作
	BITMAPFILEHEADER bmfh;
	BITMAPINFOHEADER bmih;

    char strFileName[MAX_PATH]="720bmp.bmp";
	CFile* f;
	f = new CFile();
	f->Open(strFileName, CFile::modeRead);
	f->SeekToBegin();
	f->Read(&bmfh, sizeof(bmfh));
	f->Read(&bmih, sizeof(bmih));
 
    // 分配图片像素内存
    RGBTRIPLE *rgb;
	rgb = new RGBTRIPLE[bmih.biWidth*bmih.biHeight];

	f->SeekToBegin();
	f->Seek(54,CFile::begin);  // BMP 54个字节之后的是位像素数据
	f->Read(rgb, bmih.biWidth * bmih.biHeight * 3);	 // 这里只读24位RGB(r,g,b)图像
	
	// 上场  (1,3,5,7...行)
	for (int i = bmih.biHeight-1; i>=0; i--) {
		for (int j = 0; j<bmih.biWidth; j++) {
			if(!(i%2)==0) 
			{
				bufRGB[0] = rgb[i*bmih.biWidth+j].rgbtRed;   //	R
				bufRGB[1] = rgb[i*bmih.biWidth+j].rgbtGreen; // G
				bufRGB[2] = rgb[i*bmih.biWidth+j].rgbtBlue;  // B

				// RGB转换为YUV
				RGB2YUV(bufRGB,bufYUV);
				yuv_y0 = bufYUV[0];   // y
				yuv_u0 = bufYUV[1];   // u
				yuv_v0 = bufYUV[2];   // v
				
				for (int k=0; k<1000; k++) ;  //延时
				// 视图中显示
				pDC->SetPixel(j, (bmih.biHeight-1)-i, RGB(bufRGB[0], bufRGB[1], bufRGB[2]));
				
				// UYVY标准  [U0 Y0 V0 Y1] [U1 Y2 V1 Y3] [U2 Y4 V2 Y5] 每像素点两个字节，[内]为四个字节 
				if ((j%2)==0) 
				{
					*Video_Field0 = yuv_u0;  
					Video_Field0++;
					yuv_v1 = yuv_v0;   // v保存起来供下一字节使用
				} 
				else
				{
					*Video_Field0 = yuv_v1;  
					Video_Field0++;
				}
				*Video_Field0 = yuv_y0;      
				Video_Field0++;
			}// end if i%2
		}
	}

    // 下场 (2,4,6,8...行)
	for (int i_ = bmih.biHeight-1; i_>=0; i_--) {
		for (int j_ = 0; j_<bmih.biWidth; j_++) {
			if((i_%2)==0) 
			{
				bufRGB[0] = rgb[i_*bmih.biWidth+j_].rgbtRed;   //	R
				bufRGB[1] = rgb[i_*bmih.biWidth+j_].rgbtGreen; // G
				bufRGB[2] = rgb[i_*bmih.biWidth+j_].rgbtBlue;  // B

				// RGB转换为YUV
				RGB2YUV(bufRGB,bufYUV);
				yuv_y0 = bufYUV[0];   // y
				yuv_u0 = bufYUV[1];   // u
				yuv_v0 = bufYUV[2];   // v

				for (int k=0; k<1000; k++) ;  //延时
				// 视图中显示
				pDC->SetPixel(j_, (bmih.biHeight-1)-i_, RGB(bufRGB[0], bufRGB[1], bufRGB[2]));

				// UYVY标准  [U0 Y0 V0 Y1] [U1 Y2 V1 Y3] [U2 Y4 V2 Y5] 每像素点两个字节，[内]为四个字节 
				if ((j_%2)==0) 
				{
					*Video_Field1 = yuv_u0;  
					Video_Field1++;
					yuv_v1 = yuv_v0;   // v保存起来供下一字节使用
				} 
				else
				{
					*Video_Field1 = yuv_v1;  
					Video_Field1++;
				}
				*Video_Field1 = yuv_y0;      
				Video_Field1++;
			}
		}
	}

    // 关闭BMP位图文件
	f->Close();
	WriteYUV(Video_Field0_, Video_Field1_, size);
	
	// 释放内存
	free( Video_Field0_ ); 
	free( Video_Field1_ );
	delete f;
	delete rgb;
}

// 写入到*.pal文件
BOOL CRGB2YUVView::WriteYUV(byte *Video_Field0, byte *Video_Field1, int size)
{
	char strFileName[MAX_PATH]="720bmp.pal";
	CFile* f;
	f = new CFile();
	f->Open(strFileName, CFile::modeCreate |CFile::modeWrite);
	f->SeekToBegin();
	f->Write(Video_Field0, size);
	f->Write(Video_Field1, size);
	f->Close();
	
	char buffer[80];
	sprintf(buffer,"PAL图像保存为文件：%s ", strFileName);
	MessageBox(buffer, "提示信息", MB_OK | MB_ICONINFORMATION);

	return TRUE;
}

void CRGB2YUVView::YUV2RGB(byte *pRGB, byte *pYUV)
{
	byte y, u, v;
	y = *pYUV; pYUV++;
	u = *pYUV; pYUV++;
	v = *pYUV; 

	*pRGB = static_cast<byte>(1.0*y + 8 + 1.402*(v-128));    pRGB++;                 // r
	*pRGB = static_cast<byte>(1.0*y - 0.34413*(u-128) - 0.71414*(v-128));  pRGB++;   // g
	*pRGB = static_cast<byte>(1.0*y + 1.772*(u-128) + 0);                            // b
}

// 读取PAL文件转换为RGB并显示
void CRGB2YUVView::OnReadPAL() 
{
	// TODO: Add your command handler code here
	CDC *pDC = GetDC();
	CRect rect;
	CBrush brush(RGB(128,128,128));
	GetClientRect(&rect);
	pDC->FillRect(&rect, &brush);

	// PAL 720x576 : 中国的电视标准为PAL制	
	int CurrentXRes = 720;
	int CurrentYRes = 576;
	int size        = CurrentXRes * CurrentYRes;
    
	// 分配内存
	byte *Video_Field0 = (byte*)malloc(CurrentXRes*CurrentYRes);  
	byte *Video_Field1 = (byte*)malloc(CurrentXRes*CurrentYRes);

	// 保存内存指针
	byte *Video_Field0_ = Video_Field0;
	byte *Video_Field1_ = Video_Field1;

	// 初始化内存
	ZeroMemory(Video_Field0, CurrentXRes*CurrentYRes);
	ZeroMemory(Video_Field1, CurrentXRes*CurrentYRes);

	byte yuv_y0, yuv_u0, yuv_v0; // yuv_v1;  // {y0, u0, v0, v1};
	byte r, g, b;
	byte bufRGB[3];  // 临时保存{R,G,B}
	byte bufYUV[3];  // 临时保存{Y,U,V}
	
	// 初始化数组空间
	memset(bufRGB,0, sizeof(byte)*3); 
	memset(bufYUV,0, sizeof(byte)*3); 
    
    char strFileName[MAX_PATH]="720bmp.pal";
 
    // 分配图片像素内存
    RGBTRIPLE *rgb;
	rgb = new RGBTRIPLE[CurrentXRes*CurrentYRes];

	memset(rgb,0, sizeof(RGBTRIPLE)*CurrentXRes*CurrentYRes); // 初始化内存空间

	CFile* f;
	f = new CFile();
	f->Open(strFileName, CFile::modeRead);
	f->SeekToBegin();
	f->Read(Video_Field0, CurrentXRes*CurrentYRes);
	f->Read(Video_Field1, CurrentXRes*CurrentYRes);

	// 上场  (1,3,5,7...行)
	for ( int i = CurrentYRes-1; i>=0; i--) {
		for ( int j = 0; j<CurrentXRes; j++) {
			if(!(i%2)==0) 
			{
				// UYVY标准  [U0 Y0 V0 Y1] [U1 Y2 V1 Y3] [U2 Y4 V2 Y5] 每像素点两个字节，[内]为四个字节 
				if ((j%2)==0) 
				{
					yuv_u0 = *Video_Field0;  
					Video_Field0++;
				} 
				else
				{
					yuv_v0 = *Video_Field0;  
					Video_Field0++;
				}
				yuv_y0 = *Video_Field0;      
				Video_Field0++;

				bufYUV[0] = yuv_y0;  //	Y
				bufYUV[1] = yuv_u0;  // U
				bufYUV[2] = yuv_v0;  // V

				// RGB转换为YUV
				YUV2RGB(bufRGB,bufYUV);
				r = bufRGB[0];   // y
				g = bufRGB[1];   // u
				b = bufRGB[2];   // v
				if (r>255) r=255; if (r<0) r=0;
				if (g>255) g=255; if (g<0) g=0;
				if (b>255) b=255; if (b<0) b=0;

				for (int k=0; k<1000; k++) ;  //延时
				// 视图中显示
				pDC->SetPixel(j, CurrentYRes-1-i, RGB(r, g, b));

			}// end if i%2
		}
	}

    // 下场 (2,4,6,8...行)
	for ( int i_ = CurrentYRes-1; i_>=0; i_--) {
		for ( int j_ = 0; j_<CurrentXRes; j_++) {
			if((i_%2)==0) 
			{
				// UYVY标准  [U0 Y0 V0 Y1] [U1 Y2 V1 Y3] [U2 Y4 V2 Y5] 每像素点两个字节，[内]为四个字节 
				if ((j_%2)==0) 
				{
					yuv_u0 = *Video_Field1;  
					Video_Field1++;
				} 
				else
				{
					yuv_v0 = *Video_Field1;  
					Video_Field1++;
				}
				yuv_y0 = *Video_Field1;      
				Video_Field1++;

				bufYUV[0] = yuv_y0;  //	Y
				bufYUV[1] = yuv_u0;  // U
				bufYUV[2] = yuv_v0;  // V

				// RGB转换为YUV
				YUV2RGB(bufRGB,bufYUV);
				r = bufRGB[0];   // y
				g = bufRGB[1];   // u
				b = bufRGB[2];   // v
				if (r>255) r=255; if (r<0) r=0;
				if (g>255) g=255; if (g<0) g=0;
				if (b>255) b=255; if (b<0) b=0;

				for (int k=0; k<1000; k++) ;  //延时
				// 视图中显示
				pDC->SetPixel(j_, CurrentYRes-1-i_, RGB(r, g, b));
			}
		}
	}
	
	// 提示完成
	char buffer[80];
	sprintf(buffer,"完成读取PAL文件：%s ", strFileName);
	MessageBox(buffer, "提示信息", MB_OK | MB_ICONINFORMATION);

    // 关闭PAL电视场文件
	f->Close();
	// WriteYUV(Video_Field0_, Video_Field1_, size);
	
	// 释放内存
	free( Video_Field0_ ); 
	free( Video_Field1_ );
	delete f;
	delete rgb;
}
