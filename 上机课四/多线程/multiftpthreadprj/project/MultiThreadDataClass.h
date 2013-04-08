//---------------------------------------------------------------------------

#ifndef MultiThreadDataClassH
#define MultiThreadDataClassH
//---------------------------------------------------------------------------
#endif
typedef struct FileTail{
    bool isOk;
    String pos;
    String len;
    FileTail *next;
}m_fileTail;
typedef struct FromToImpl{
    DWORD from;
    DWORD to;
}m_fromTo;
typedef struct InfroImpl{
    String fileLoad;
    DWORD  fileSize;
    int    threadCnt;
    DWORD  alreadyDownloadCnt;
    FromToImpl *fromToImpl;
}m_inforImpl;
class MultiThreadDataClass{
 public:
    __fastcall MultiThreadDataClass();
};
