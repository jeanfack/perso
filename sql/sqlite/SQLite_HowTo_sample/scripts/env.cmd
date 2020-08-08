pushd

set CURRENT_DRIVE=%~d0
set CURRENT_DIR=%~dp0
set CURRENT_DIR=%CURRENT_DIR:~0,-1%

set MICROSOFT_OFFICE_DIR=%CURRENT_DIR%\microsoft_office
set OPEN_OFFICE_DIR=%CURRENT_DIR%\open_office
set SQL_DIR=%CURRENT_DIR%\sql
set SQLITE_META_DIR=%CURRENT_DIR%\sqlite\meta
set SQLITE_DB_DIR=%CURRENT_DIR%\sqlite\db
set SQLITE_EXE=%CURRENT_DIR%\..\sqlite-tools-win32-x86-3320300\sqlite3.exe

%CURRENT_DRIVE%
cd %CURRENT_DIR%

pop
