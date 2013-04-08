//---------------------------------------------------------------------------

#include <vcl.h>
#ifndef MultiThreadDealScoketH
#define MultiThreadDealScoketH
//---------------------------------------------------------------------------
#endif
#ifndef Winsock2H
#include <Winsock2.h>
#endif
class MultiThreadDealSocket{
  public :
    __fastcall MultiThreadDealSocket();
  SOCKET __fastcall GetConnect(String host ,int port);
  String __fastcall GetHost(String pasvStr);
  int __fastcall GetPort(String pasvStr);
};
