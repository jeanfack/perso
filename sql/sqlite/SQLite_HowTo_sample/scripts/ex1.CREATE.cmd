call %~dp0env.cmd

%SQLITE_EXE% -echo -init %SQLITE_META_DIR%\ex1.CREATE.meta %SQLITE_DB_DIR%\ex1.db ".quit"
