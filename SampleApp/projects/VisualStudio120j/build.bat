@echo off
if "%1"=="" goto lab_empty
if "%1"=="x86" goto lab_x86
if "%1"=="x64" goto lab_x64
goto :eof


:lab_empty
cmd.exe /c "%~f0" x86
cmd.exe /c "%~f0" x64
goto :eof


:lab_x86
cd "%~dp0"
mkdir x86 2> nul
cd x86
del SampleApp.exe 2> nul
call "c:\Program Files\Programy\Microsoft Visual Studio 12.0\VC\vcvarsall.bat" x86
cl.exe ..\SampleApp.cpp /nologo /DNDEBUG /GL /Gw /MT /O2 /Os /W4 /link /subsystem:windows /LTCG user32.lib
goto :eof


:lab_x64
cd "%~dp0"
mkdir x64 2> nul
cd x64
del SampleApp.exe 2> nul
call "c:\Program Files\Programy\Microsoft Visual Studio 12.0\VC\vcvarsall.bat" x86_amd64
cl.exe ..\SampleApp.cpp /nologo /DNDEBUG /GL /Gw /MT /O2 /Os /W4 /link /subsystem:windows /LTCG user32.lib
goto :eof
