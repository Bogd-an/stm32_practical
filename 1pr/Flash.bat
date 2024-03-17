@echo off

@REM Визначення шляху до програми ST-LINK_CLI.exe
set STLINK_CLI_PATH="C:\Program Files (x86)\STMicroelectronics\STM32 ST-LINK Utility\ST-LINK Utility\ST-LINK_CLI.exe"

@REM Визначення шляху до теки проекту
set PROJECT_PATH=%~dp0

@REM Визначення назви проекту
cd /d %~dp0
for %%A in ("%CD%") do set "PROJECT_NAME=%%~nxA"

@echo on

@REM Виконати програмування та перевірку
%STLINK_CLI_PATH% -P %PROJECT_PATH%Build+Flash\%PROJECT_NAME%.bin 0x08000000 -V -Rst

@REM Кінець скрипта

