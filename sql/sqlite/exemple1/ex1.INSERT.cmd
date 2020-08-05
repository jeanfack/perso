call %~dp0env.cmd

%SQLITE_EXE% ex1.db ".read USER.INSERT.sql"
