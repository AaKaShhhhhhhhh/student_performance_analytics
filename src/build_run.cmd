@echo off
setlocal

REM Adjust this if your MariaDB Connector/C is installed elsewhere
set "MARIADB=C:\Program Files\MariaDB\MariaDB Connector C 64-bit"

cd /d "%~dp0"

REM If the MinGW import lib is missing, generate it from the DLL (one-time)
if not exist "libmariadb.dll.a" (
  echo Generating libmariadb.dll.a from %%MARIADB%%\lib\libmariadb.dll ...
  gendef "%MARIADB%\lib\libmariadb.dll" || exit /b 1
  dlltool -d libmariadb.def -l libmariadb.dll.a -D libmariadb.dll || exit /b 1
)

REM Clean and build
del /q main.exe *.o 2>nul
g++ main.cpp db_connector.cpp student.cpp -I"%MARIADB%\include" -L. -lmariadb -o main.exe || exit /b 1

echo.
main.exe
