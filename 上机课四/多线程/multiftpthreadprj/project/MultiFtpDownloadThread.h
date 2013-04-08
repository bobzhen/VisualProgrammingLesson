//---------------------------------------------------------------------------

#ifndef MultiFtpDownloadThreadH
#define MultiFtpDownloadThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#ifndef Winsock2H
#include <Winsock2.h>
#endif
#ifndef MultiThreadDataClassH
#include "MultiThreadDataClass.h"
#endif
#include "DataClass.h"
//---------------------------------------------------------------------------
typedef __fastcall (__closure *TOnComplete)(TObject *Sender);
typedef __fastcall (__closure *TOnTextOut)(TObject *Sender ,String infor);
typedef __fastcall (__closure *TOnException)(TObject *Sender ,String error);
typedef __fastcall (__closure *TOnProgress)(TObject *Sender ,DWORD pos);
class MultiFtpDownloadThread : public TThread
{            
private:
   bool FIsFileRead;
protected:
        void __fastcall Execute();
public:
        __fastcall MultiFtpDownloadThread(bool CreateSuspended );
        __fastcall ~MultiFtpDownloadThread();
        TComponent *parent;
        TComponent *Owner;
        SOCKET  commandClient;
        SOCKET dataClient;
        String  localFileLoad;
        String  FileName;
        TOnComplete FOnComplete;
        TOnTextOut FOnTextOut;
        TOnException FOnException;
        TOnProgress FOnProgress;
        int ID;
        int    perFileLen;
        void __fastcall DoOnComplete();
        void __fastcall DoOnTextOut(String text);
        void __fastcall DoOnException(String error);
        void __fastcall DoOnProgress(DWORD pos);
        bool __fastcall DownLoad(DWORD pos ,DWORD len);
        bool __fastcall CreateDataCon();
        bool __fastcall SetFilePos(DWORD pos);
__property bool IsFileRead={read=FIsFileRead,write=FIsFileRead};
__property TOnComplete OnComplete={read = FOnComplete , write =FOnComplete};
__property TOnTextOut OnTextOut={read = FOnTextOut,write= FOnTextOut};
__property TOnException OnException = {read = FOnException ,write = FOnException};
__property TOnProgress OnProgress= {read = FOnProgress ,write = FOnProgress};
};
//---------------------------------------------------------------------------
#endif
