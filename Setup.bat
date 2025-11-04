@echo off
setlocal

set "URL=https://download.savannah.gnu.org/releases/tinycc/tcc-0.9.27-win64-bin.zip"
set "ZIP=tcc.zip"
set "DEST=%~dp0"

echo Downloading TCC Compiler from %URL%...
powershell -Command "Invoke-WebRequest -Uri '%URL%' -OutFile '%DEST%%ZIP%'"

echo Extracting %ZIP% in %DEST%...
powershell -Command "Expand-Archive -Path '%DEST%%ZIP%' -DestinationPath '%DEST%' -Force"

echo Deleting ZIP file...
del "%DEST%%ZIP%"

echo TCC is "installed" :) 
pause
