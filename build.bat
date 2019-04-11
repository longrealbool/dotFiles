@echo off


SET VC_PATH=C:\Program Files (x86)\Microsoft Visual Studio\2017\Community
REM I don't know why it doesn't work, assume problem with "%LIB%" - syntax
REM IF NOT DEFINED "%LIB%" (IF EXIST "%VC_PATH%" (call "%VC_PATH%\VC\Auxiliary\Build\vcvarsall.bat" x64))

REM work in my case, never been tested. PROVIDED AS IS, WITH ABSOLUTELY NO WARRANTY EXPRESSED
REM OR IMPLIED.  ANY USE IS AT YOUR OWN RISK.

if "%LIB%"=="" (call chcp 437) 
if "%LIB%"=="" (IF EXIST "%VC_PATH%" (call "%VC_PATH%\VC\Auxiliary\Build\vcvarsall.bat" x64))

set CommonCompilerFlags=-MTd -nologo -Gm- -GR- -EHa- -Od -Oi -WX -W2 -wd4201 -wd4100 -wd4189 -wd4505 -D_INTERNAL=1 -D_SLOW=1 -D_WIN32=1 -FC -Z7 -source-charset:utf-8
set CommonLinkerFlags= -incremental:no -opt:ref user32.lib gdi32.lib winmm.lib

IF NOT EXIST ..\..\build mkdir ..\..\build
pushd ..\build

REM 64-bit build /O2 /Oi /fp:fast

cl %CommonCompilerFlags% ..\source\win32_msgBuilder.cpp -Fmwin32_msgBuilder.map /link %CommonLinkerFlags%


REM cl %CommonCompilerFlags% ..\source\example2.c -Fmwin32_msgBuilder.map /link %CommonLinkerFlags%
popd
