call %~dp0env.cmd

:: delete database file
call ex1.del.cmd

:: create database file
call ex1.new.cmd

:: create table USER
call ex1.CREATE.cmd

:: populate table USER with 5 persons
call ex1.INSERT.cmd

:: display table USER
call ex1.SELECT.cmd

:: insert 6th record
call ex1.INSERT.Charlie.Chaplin.cmd

:: display table USER
call ex1.SELECT.cmd

:: delete 6th record
call ex1.DELETE.Charlie.Chaplin.cmd

:: display table USER
call ex1.SELECT.cmd
