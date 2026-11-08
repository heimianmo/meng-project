@echo off
chcp 65001 >nul
cd /d "%~dp0"

set GIT="D:\Git\bin\git.exe"
if not exist %GIT% set GIT=git

echo ============================================
echo   Sync my code to GitHub
echo ============================================
echo.
echo [1/3] Collecting changed files...
%GIT% add .
echo [2/3] Saving one version...
%GIT% commit -m "sync %DATE:~0,10% %TIME:~0,5%"
echo [3/3] Uploading...
%GIT% push
echo.
echo --------------------------------------------
echo  Done.  github.com/heimianmo/meng-project
echo --------------------------------------------
echo.
pause
