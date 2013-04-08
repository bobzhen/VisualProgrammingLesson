; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CAudio2Dlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "audio2.h"

ClassCount=3
Class1=CAudio2App
Class2=CAudio2Dlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_AUDIO2_DIALOG

[CLS:CAudio2App]
Type=0
HeaderFile=audio2.h
ImplementationFile=audio2.cpp
Filter=N

[CLS:CAudio2Dlg]
Type=0
HeaderFile=audio2Dlg.h
ImplementationFile=audio2Dlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CAudio2Dlg

[CLS:CAboutDlg]
Type=0
HeaderFile=audio2Dlg.h
ImplementationFile=audio2Dlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_AUDIO2_DIALOG]
Type=1
Class=CAudio2Dlg
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDC_REC_START,button,1342242816
Control3=IDC_REC_STOP,button,1342242816
Control4=IDC_PLAY_START,button,1342242816

