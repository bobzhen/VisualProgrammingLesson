//---------------------------------------------------------------------------


#pragma hdrstop

#include "MultiThreadDealScoket.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
__fastcall  MultiThreadDealSocket::MultiThreadDealSocket()
{

}
SOCKET __fastcall MultiThreadDealSocket::GetConnect(String host ,int port)
{
    SOCKET client;
    WORD version;
    SOCKADDR_IN sockStruct;
    version = MAKEWORD(2,2);
    WSADATA wsaData;
    int err = WSAStartup(version, &wsaData );
    if ( err != 0 ) {
        return NULL;
      }
    client = socket(PF_INET,SOCK_STREAM,0);
    DWORD dwip;
    if((dwip=inet_addr(host.c_str()))==INADDR_NONE) //如果是ip地址
    {
	struct hostent *hp = NULL;
	if ((hp = gethostbyname(host.c_str())) != NULL)
	{
		memcpy(&(sockStruct.sin_addr), hp->h_addr, hp->h_length);
		sockStruct.sin_family = hp->h_addrtype;
		//sockStruct.sin_family = AF_INET;
	       //	TRACE("sockaddr.sin_addr = %s\n", inet_ntoa(sockStruct.sin_addr));
	}
	else
	{
		//TRACE("gethostbyname() failed: %d\n",
		WSAGetLastError();
		return NULL ;
	}
    }
    else
    {
		sockStruct.sin_family=AF_INET; //使用TCP/IP协议
		sockStruct.sin_addr.S_un.S_addr = dwip;
    }
   sockStruct.sin_port = htons(port);
   if(connect(client,(LPSOCKADDR)&sockStruct,sizeof(sockStruct)) == SOCKET_ERROR)
    {
       return NULL ;
    }
    return client;
}
String __fastcall MultiThreadDealSocket::GetHost(String pasvStr)
{
    int index = pasvStr.Pos("(");
    String str = pasvStr.SubString(index+1,pasvStr.Length() - index);
    String temp;
    for(int i =0 ; i < 4 ;i ++)
    {
           index = str.Pos(",");
            temp += str.SubString(1,index-1)+".";
      str = str.SubString(index+1,str.Length() -index);
    }
    temp = temp.SubString(1,temp.Length()-1) ;
    return temp;
}
int __fastcall MultiThreadDealSocket::GetPort(String pasvStr)
{
   int index = pasvStr.Pos("(");
    String str = pasvStr.SubString(index+1,pasvStr.Length() - index);
    String temp;
    for(int i =0 ; i < 4 ;i ++)
    {
           index = str.Pos(",");
           str = str.SubString(index+1,str.Length() -index);
    }
    index = str.Pos(",");
    temp  = str.SubString(1,index-1);
    str = str.SubString(index+1,str.Length()-index);
    index  = str.Pos(")");
    str = str.SubString(1,index-1);
    int ge,shi;
    shi = StrToInt(temp);  ge = StrToInt(str);
    return shi*256 + ge;
}
