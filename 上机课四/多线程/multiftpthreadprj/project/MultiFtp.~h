//---------------------------------------------------------------------------

#ifndef MultiFtpH
#define MultiFtpH
//---------------------------------------------------------------------------
#include <SysUtils.hpp>
#include <Classes.hpp>
#include "MultiFtpDownloadThred.h"
#ifndef MultiFtpDownloadThreadH
#include "MultiFtpDownloadThread.h"
#endif
#ifndef    MultiThreadDealScoketH
#include "MultiThreadDealScoket.h"
#endif
#ifndef MultiThreadDataClassH
#include "MultiThreadDataClass.h"
#endif
#include <stdio.h>
//---------------------------------------------------------------------------
typedef void __fastcall (__closure *TOnGetFileSize)(TObject *Sender ,DWORD fileSize);
typedef void __fastcall (__closure *TOnGetRate)(TObject *Sender ,DWORD cnt);
class PACKAGE TMultiFtp : public TComponent
{
private:
    TOnComplete FOnComplete;
    TOnTextOut FOnTextOut;
    TOnException FOnException;
    TOnProgress FOnProgress;
    TOnGetFileSize FOnGetFileSize;
    TOnGetRate FOnGetRate;
    int FPerGetLen;
    String FHost;
    int FPort;
    String FUserName;
    String FPass;
    String FFileName;
    int FThreadCnt;
    String FLocalLoad;
    bool lock;
protected:
public:
        __fastcall TMultiFtp(TComponent* Owner);
        __fastcall ~TMultiFtp();
        TComponent *Owner;
        bool isReadFile;
        SOCKET __fastcall ConnectFtp(String host ,int port,String userName ,String pass);
        void __fastcall DoOnComplete();
        void __fastcall DoOnTextOut(String text);
        void __fastcall DoOnException (String error);
        void __fastcall DoOnProgress(DWORD pos);
        void __fastcall DoOnGetFileSize(DWORD fileSize);
        void __fastcall DoOnGetRate(DWORD cnt);
        String __fastcall GetCode(String revStr);
        DWORD __fastcall GetFtpFileSize(SOCKET client ,String fileName);
        DWORD __fastcall GetFileSize();
        bool __fastcall  CheckIsSupportMulti(SOCKET client);
        FileTail * __fastcall GetFilePosLen();
        String __fastcall ConvertIntToStr(DWORD len);
        void __fastcall StartDownloadFile();
        bool __fastcall ChangeDirectory(SOCKET client ,String dirName);
        String __fastcall SetCurrentDir(SOCKET client ,String dirName);
        void __fastcall WriteToFile(String filePath,DWORD pos ,char *buffer , int len);
        int __fastcall GetSuccessCode();
        int __fastcall GetBusyCode();
        void __fastcall AverageDownload(int successCode, int busyCode);
        DWORD __fastcall GetFileSizeByName(String fileName);
        DWORD fileSize;
        DWORD currentFilePos;
        FILE *globalFile;
        DWORD FilePos;
        bool isUseFile;
        bool FileLocked;
        FromToImpl *fromToImpl;
        InfroImpl  inforImpl;
        int  runningThreadCnt;
        bool stop;
        void __fastcall SetStop(bool stop);
        String FilePath ;
        DWORD perFilePos; //上一时刻文件已经接受的大小
        bool __fastcall CreateNewFile(String fileName, DWORD size);
        bool __fastcall WriteInforToFile();
        void __fastcall DivisionFile();
        void  __fastcall CreateThread(int code ,SOCKET client);
        void  __fastcall  GetInfor(String fileName);
        void __fastcall CreateInforImpl(String str);
        void __fastcall CreateInforImplFromString(String inforStr);
        void __fastcall  DealTimer(MSG msg);
        void __fastcall FreeMemory();
        String hisFileStr;
__published:
__property String  Host = {read = FHost ,write= FHost};
__property int  Port = {read = FPort ,write= FPort};
__property int  PerGetLen = {read = FPerGetLen ,write= FPerGetLen};
__property String  UserName = {read = FUserName ,write= FUserName};
__property String  Pass = {read = FPass ,write= FPass};
__property String  FileName = {read = FFileName ,write= FFileName};
__property int  ThreadCnt = {read = FThreadCnt ,write= FThreadCnt};
__property String  LocalLoad = {read = FLocalLoad ,write= FLocalLoad};
__property TOnComplete OnComplete={read = FOnComplete , write =FOnComplete};
__property TOnTextOut OnTextOut={read = FOnTextOut,write= FOnTextOut};
__property TOnException OnException = {read = FOnException ,write = FOnException};
__property TOnProgress OnProgress= {read = FOnProgress ,write = FOnProgress};
__property TOnGetFileSize OnGetFileSize={read=FOnGetFileSize,write=FOnGetFileSize};
__property TOnGetRate OnGetRate={read=FOnGetRate,write=FOnGetRate};
};
//---------------------------------------------------------------------------
#endif
 