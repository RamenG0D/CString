@echo off

set COMPILER=%~1
set LIB_NAME=%~2

echo Compiling %LIB_NAME%

%COMPILER% -c ./src/%LIB_NAME%.c -O2 -I./includes -o ./%LIB_NAME%.o

ar -rvs ./lib%LIB_NAME%.a ./%LIB_NAME%.o

rm ./%LIB_NAME%.o