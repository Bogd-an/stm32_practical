@echo off

set MAKE_PATH="C:\USERS\PC\APPDATA\ROAMING\CODE\USER\GLOBALSTORAGE\BMD.STM32-FOR-VSCODE\@XPACK-DEV-TOOLS\WINDOWS-BUILD-TOOLS\4.4.1-2.1\.CONTENT\BIN\MAKE.EXE"

@echo on

%MAKE_PATH% -j16 -f STM32Make.make 