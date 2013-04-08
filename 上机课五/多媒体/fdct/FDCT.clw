; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CFDCTDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "FDCT.h"

ClassCount=3
Class1=CFDCTApp
Class2=CFDCTDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_FDCT_DIALOG

[CLS:CFDCTApp]
Type=0
HeaderFile=FDCT.h
ImplementationFile=FDCT.cpp
Filter=N

[CLS:CFDCTDlg]
Type=0
HeaderFile=FDCTDlg.h
ImplementationFile=FDCTDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_IDCT

[CLS:CAboutDlg]
Type=0
HeaderFile=FDCTDlg.h
ImplementationFile=FDCTDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_FDCT_DIALOG]
Type=1
Class=CFDCTDlg
ControlCount=9
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_RADIO1,button,1342308361
Control4=IDC_RADIO2,button,1342177289
Control5=IDC_READ,button,1342242816
Control6=IDC_DCT,button,1342242816
Control7=IDC_IDCT,button,1342242816
Control8=IDC_STATUS,edit,1342244996
Control9=IDC_STATIC,static,1342308352

