# Microsoft Developer Studio Project File - Name="SampleApp" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=SampleApp - Win32 DebugEntry
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "SampleApp.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "SampleApp.mak" CFG="SampleApp - Win32 DebugEntry"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "SampleApp - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "SampleApp - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "SampleApp - Win32 DebugEntry" (based on "Win32 (x86) Application")
!MESSAGE "SampleApp - Win32 ReleaseEntry" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "SampleApp - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /G3 /MD /Za /W3 /WX /O1 /Ob2 /D "NDEBUG" /FD /c
# SUBTRACT CPP /YX
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /pdb:none /machine:I386
# SUBTRACT LINK32 /nodefaultlib

!ELSEIF  "$(CFG)" == "SampleApp - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /G3 /MDd /Za /W3 /WX /Gm /Zi /Od /Gf /FAcs /FR /FD /GZ /c
# SUBTRACT CPP /u /YX
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:no /map /debug /debugtype:both /machine:I386 /force /pdbtype:sept
# SUBTRACT LINK32 /nodefaultlib

!ELSEIF  "$(CFG)" == "SampleApp - Win32 DebugEntry"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "SampleApp___Win32_DebugEntry"
# PROP BASE Intermediate_Dir "SampleApp___Win32_DebugEntry"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "DebugEntry"
# PROP Intermediate_Dir "DebugEntry"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /G3 /MDd /Za /W3 /WX /Gm /Zi /Od /Gf /FAcs /FR /FD /GZ /c
# SUBTRACT BASE CPP /u /YX
# ADD CPP /nologo /G3 /MDd /Za /W3 /WX /Gm /Zi /Od /Gf /D "MK_ENTRY" /FAcs /FR /FD /GZ /c
# SUBTRACT CPP /u /YX
# ADD BASE MTL /nologo /mktyplib203 /win32
# ADD MTL /nologo /mktyplib203 /win32
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 msvcrt.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /entry:"entry_point" /subsystem:windows /incremental:no /map /debug /debugtype:both /machine:I386 /nodefaultlib /force /pdbtype:sept
# ADD LINK32 msvcrtd.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /entry:"entry_point" /subsystem:windows /incremental:no /map /debug /debugtype:both /machine:I386 /nodefaultlib /force /pdbtype:sept

!ELSEIF  "$(CFG)" == "SampleApp - Win32 ReleaseEntry"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "SampleApp___Win32_ReleaseEntry"
# PROP BASE Intermediate_Dir "SampleApp___Win32_ReleaseEntry"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseEntry"
# PROP Intermediate_Dir "ReleaseEntry"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /G3 /MD /Za /W3 /O1 /Ob2 /D "NDEBUG" /FD /c
# SUBTRACT BASE CPP /YX
# ADD CPP /nologo /G3 /MD /Za /W3 /WX /O1 /Ob2 /D "NDEBUG" /D "MK_ENTRY" /FD /c
# SUBTRACT CPP /YX
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 msvcrt.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /entry:"entry_point" /subsystem:windows /pdb:none /machine:I386 /nodefaultlib
# ADD LINK32 msvcrt.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /entry:"entry_point" /subsystem:windows /pdb:none /machine:I386 /nodefaultlib

!ENDIF 

# Begin Target

# Name "SampleApp - Win32 Release"
# Name "SampleApp - Win32 Debug"
# Name "SampleApp - Win32 DebugEntry"
# Name "SampleApp - Win32 ReleaseEntry"
# Begin Group "src"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\src\main.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\main.hpp
# End Source File
# Begin Source File

SOURCE=..\..\src\mk_application.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\mk_application.hpp
# End Source File
# Begin Source File

SOURCE=..\..\src\mk_assert.hpp
# End Source File
# Begin Source File

SOURCE=..\..\src\mk_check_ret.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\mk_check_ret.hpp
# End Source File
# Begin Source File

SOURCE=..\..\src\mk_critical_section.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\mk_critical_section.hpp
# End Source File
# Begin Source File

SOURCE=..\..\src\mk_cstdlib.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\mk_cstdlib.hpp
# End Source File
# Begin Source File

SOURCE=..\..\src\mk_delayed_constructor.hpp
# End Source File
# Begin Source File

SOURCE=..\..\src\mk_delayed_constructor.inl
# End Source File
# Begin Source File

SOURCE=..\..\src\mk_entry_point.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\mk_lock.hpp
# End Source File
# Begin Source File

SOURCE=..\..\src\mk_lock.inl
# End Source File
# Begin Source File

SOURCE=..\..\src\mk_macros.hpp
# End Source File
# Begin Source File

SOURCE=..\..\src\mk_main.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\mk_main.hpp
# End Source File
# Begin Source File

SOURCE=..\..\src\mk_main_window.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\mk_main_window.hpp
# End Source File
# Begin Source File

SOURCE=..\..\src\mk_move.hpp
# End Source File
# Begin Source File

SOURCE=..\..\src\mk_move.inl
# End Source File
# Begin Source File

SOURCE=..\..\src\mk_task_queue.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\mk_task_queue.hpp
# End Source File
# Begin Source File

SOURCE=..\..\src\mk_types.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\mk_types.hpp
# End Source File
# Begin Source File

SOURCE=..\..\src\mk_utility.hpp
# End Source File
# Begin Source File

SOURCE=..\..\src\mk_utility.inl
# End Source File
# Begin Source File

SOURCE=..\..\src\mk_vector.hpp
# End Source File
# Begin Source File

SOURCE=..\..\src\mk_vector.inl
# End Source File
# Begin Source File

SOURCE=..\..\src\mk_win_kernel.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\mk_win_kernel.hpp
# End Source File
# Begin Source File

SOURCE=..\..\src\mk_win_user.cpp
# End Source File
# Begin Source File

SOURCE=..\..\src\mk_win_user.hpp
# End Source File
# Begin Source File

SOURCE=..\..\src\mk_window_class_registrator.hpp
# End Source File
# Begin Source File

SOURCE=..\..\src\mk_window_class_registrator.inl
# End Source File
# Begin Source File

SOURCE=..\..\src\mk_windows.hpp
# End Source File
# End Group
# End Target
# End Project
