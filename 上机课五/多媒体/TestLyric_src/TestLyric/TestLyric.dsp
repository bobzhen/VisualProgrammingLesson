# Microsoft Developer Studio Project File - Name="TestLyric" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=TestLyric - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "TestLyric.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "TestLyric.mak" CFG="TestLyric - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "TestLyric - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "TestLyric - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "TestLyric - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_WINDOWS" /D "_DEBUG" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "./BaseClasses" /D "WIN32" /D "_WINDOWS" /D "_DEBUG" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /win32
# ADD BASE RSC /l 0x804 /i "$(IntDir)" /d "_DEBUG"
# ADD RSC /l 0x804 /i "$(IntDir)" /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:IX86 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib strmbasd.lib winmm.lib /nologo /subsystem:windows /debug /machine:IX86 /pdbtype:sept /libpath:"./BaseClasses"
# Begin Special Build Tool
SOURCE="$(InputPath)"
PreLink_Cmds=copyright.bat
# End Special Build Tool

!ELSEIF  "$(CFG)" == "TestLyric - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /Zi /D "WIN32" /D "_WINDOWS" /D "NDEBUG" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MD /W3 /GX /Zi /I "./BaseClasses" /D "WIN32" /D "_WINDOWS" /D "NDEBUG" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /c
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
# ADD BASE RSC /l 0x804 /i "$(IntDir)" /d "NDEBUG"
# ADD RSC /l 0x804 /i "$(IntDir)" /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:IX86 /pdbtype:sept /opt:ref /opt:icf
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib strmbase.lib winmm.lib /nologo /subsystem:windows /debug /machine:IX86 /nodefaultlib:"libcmt" /pdbtype:sept /libpath:"./BaseClasses" /opt:ref /opt:icf
# Begin Special Build Tool
SOURCE="$(InputPath)"
PreLink_Cmds=copyright.bat
# End Special Build Tool

!ENDIF 

# Begin Target

# Name "TestLyric - Win32 Debug"
# Name "TestLyric - Win32 Release"
# Begin Group "源"

# PROP Default_Filter "cpp;c;cxx;def;odl;idl;hpj;bat;asm;asmx"
# Begin Source File

SOURCE=.\ColourPickerXP.cpp
DEP_CPP_COLOU=\
	".\ColourPickerXP.h"\
	".\MemDC.h"\
	".\stdafx.h"\
	
# End Source File
# Begin Source File

SOURCE=.\DXGraph.cpp
DEP_CPP_DXGRA=\
	".\BaseClasses\amextra.h"\
	".\BaseClasses\amfilter.h"\
	".\BaseClasses\cache.h"\
	".\BaseClasses\combase.h"\
	".\BaseClasses\cprop.h"\
	".\BaseClasses\ctlutil.h"\
	".\BaseClasses\dllsetup.h"\
	".\BaseClasses\dsschedule.h"\
	".\BaseClasses\fourcc.h"\
	".\BaseClasses\measure.h"\
	".\BaseClasses\msgthrd.h"\
	".\BaseClasses\mtype.h"\
	".\BaseClasses\outputq.h"\
	".\BaseClasses\pstream.h"\
	".\BaseClasses\refclock.h"\
	".\BaseClasses\reftime.h"\
	".\BaseClasses\renbase.h"\
	".\BaseClasses\source.h"\
	".\BaseClasses\streams.h"\
	".\BaseClasses\strmctl.h"\
	".\BaseClasses\sysclock.h"\
	".\BaseClasses\transfrm.h"\
	".\BaseClasses\transip.h"\
	".\BaseClasses\videoctl.h"\
	".\BaseClasses\vtrans.h"\
	".\BaseClasses\winctrl.h"\
	".\BaseClasses\winutil.h"\
	".\BaseClasses\wxdebug.h"\
	".\BaseClasses\wxlist.h"\
	".\BaseClasses\wxutil.h"\
	".\DXGraph.h"\
	".\stdafx.h"\
	
# End Source File
# Begin Source File

SOURCE=.\LiveWnd.cpp
DEP_CPP_LIVEW=\
	".\BaseClasses\amextra.h"\
	".\BaseClasses\amfilter.h"\
	".\BaseClasses\cache.h"\
	".\BaseClasses\combase.h"\
	".\BaseClasses\cprop.h"\
	".\BaseClasses\ctlutil.h"\
	".\BaseClasses\dllsetup.h"\
	".\BaseClasses\dsschedule.h"\
	".\BaseClasses\fourcc.h"\
	".\BaseClasses\measure.h"\
	".\BaseClasses\msgthrd.h"\
	".\BaseClasses\mtype.h"\
	".\BaseClasses\outputq.h"\
	".\BaseClasses\pstream.h"\
	".\BaseClasses\refclock.h"\
	".\BaseClasses\reftime.h"\
	".\BaseClasses\renbase.h"\
	".\BaseClasses\source.h"\
	".\BaseClasses\streams.h"\
	".\BaseClasses\strmctl.h"\
	".\BaseClasses\sysclock.h"\
	".\BaseClasses\transfrm.h"\
	".\BaseClasses\transip.h"\
	".\BaseClasses\videoctl.h"\
	".\BaseClasses\vtrans.h"\
	".\BaseClasses\winctrl.h"\
	".\BaseClasses\winutil.h"\
	".\BaseClasses\wxdebug.h"\
	".\BaseClasses\wxlist.h"\
	".\BaseClasses\wxutil.h"\
	".\ColourPickerXP.h"\
	".\DXGraph.h"\
	".\LiveWnd.h"\
	".\stdafx.h"\
	".\TestLyric.h"\
	".\TestLyricDlg.h"\
	
# End Source File
# Begin Source File

SOURCE=.\stdafx.cpp
DEP_CPP_STDAF=\
	".\stdafx.h"\
	

!IF  "$(CFG)" == "TestLyric - Win32 Debug"

# ADD CPP /nologo /GX /Yc"stdafx.h" /GZ

!ELSEIF  "$(CFG)" == "TestLyric - Win32 Release"

# ADD CPP /nologo /GX /Yc"stdafx.h"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\TestLyric.cpp
DEP_CPP_TESTL=\
	".\BaseClasses\amextra.h"\
	".\BaseClasses\amfilter.h"\
	".\BaseClasses\cache.h"\
	".\BaseClasses\combase.h"\
	".\BaseClasses\cprop.h"\
	".\BaseClasses\ctlutil.h"\
	".\BaseClasses\dllsetup.h"\
	".\BaseClasses\dsschedule.h"\
	".\BaseClasses\fourcc.h"\
	".\BaseClasses\measure.h"\
	".\BaseClasses\msgthrd.h"\
	".\BaseClasses\mtype.h"\
	".\BaseClasses\outputq.h"\
	".\BaseClasses\pstream.h"\
	".\BaseClasses\refclock.h"\
	".\BaseClasses\reftime.h"\
	".\BaseClasses\renbase.h"\
	".\BaseClasses\source.h"\
	".\BaseClasses\streams.h"\
	".\BaseClasses\strmctl.h"\
	".\BaseClasses\sysclock.h"\
	".\BaseClasses\transfrm.h"\
	".\BaseClasses\transip.h"\
	".\BaseClasses\videoctl.h"\
	".\BaseClasses\vtrans.h"\
	".\BaseClasses\winctrl.h"\
	".\BaseClasses\winutil.h"\
	".\BaseClasses\wxdebug.h"\
	".\BaseClasses\wxlist.h"\
	".\BaseClasses\wxutil.h"\
	".\ColourPickerXP.h"\
	".\DXGraph.h"\
	".\LiveWnd.h"\
	".\stdafx.h"\
	".\TestLyric.h"\
	".\TestLyricDlg.h"\
	
# End Source File
# Begin Source File

SOURCE=.\TestLyricDlg.cpp
DEP_CPP_TESTLY=\
	".\BaseClasses\amextra.h"\
	".\BaseClasses\amfilter.h"\
	".\BaseClasses\cache.h"\
	".\BaseClasses\combase.h"\
	".\BaseClasses\cprop.h"\
	".\BaseClasses\ctlutil.h"\
	".\BaseClasses\dllsetup.h"\
	".\BaseClasses\dsschedule.h"\
	".\BaseClasses\fourcc.h"\
	".\BaseClasses\measure.h"\
	".\BaseClasses\msgthrd.h"\
	".\BaseClasses\mtype.h"\
	".\BaseClasses\outputq.h"\
	".\BaseClasses\pstream.h"\
	".\BaseClasses\refclock.h"\
	".\BaseClasses\reftime.h"\
	".\BaseClasses\renbase.h"\
	".\BaseClasses\source.h"\
	".\BaseClasses\streams.h"\
	".\BaseClasses\strmctl.h"\
	".\BaseClasses\sysclock.h"\
	".\BaseClasses\transfrm.h"\
	".\BaseClasses\transip.h"\
	".\BaseClasses\videoctl.h"\
	".\BaseClasses\vtrans.h"\
	".\BaseClasses\winctrl.h"\
	".\BaseClasses\winutil.h"\
	".\BaseClasses\wxdebug.h"\
	".\BaseClasses\wxlist.h"\
	".\BaseClasses\wxutil.h"\
	".\ColourPickerXP.h"\
	".\DXGraph.h"\
	".\LiveWnd.h"\
	".\stdafx.h"\
	".\TestLyric.h"\
	".\TestLyricDlg.h"\
	
# End Source File
# End Group
# Begin Group "头"

# PROP Default_Filter "h;hpp;hxx;hm;inl;inc;xsd"
# Begin Source File

SOURCE=.\ColourPickerXP.h
# End Source File
# Begin Source File

SOURCE=.\DXGraph.h
# End Source File
# Begin Source File

SOURCE=.\LiveWnd.h
# End Source File
# Begin Source File

SOURCE=.\MemDC.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\stdafx.h
# End Source File
# Begin Source File

SOURCE=.\TestLyric.h
# End Source File
# Begin Source File

SOURCE=.\TestLyricDlg.h
# End Source File
# End Group
# Begin Group "资源"

# PROP Default_Filter "rc;ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe;resx"
# Begin Source File

SOURCE=.\res\TestLyric.ico
# End Source File
# Begin Source File

SOURCE=.\TestLyric.rc
# End Source File
# Begin Source File

SOURCE=.\res\TestLyric.rc2
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# Begin Source File

SOURCE=.\res\TestLyric.manifest
# End Source File
# End Target
# End Project
