
# CString

a standalone library i made for use in my transpiler im making, its pretty simple to its a String, it contains its length and has some utility methods, but it does have something special, you can append to the string and it will grow to accomedate it if it needs too

## Usage

use it however you want just dont steal my code blindly, give some creddit

## Compiling

i included a build scipt (batch) in the repo, while other platforms can compile in theory im not sure, so if you want to compile it i use gcc from w64devkit (really awesome) for most projects and the commands are just compiling the files to objects, then using `ar -rvs OBJECTS.o` where OBJECTS.o is the object file(s) from the previous command

How i would compile (without script)

first clone the project and cd into it
```
git clone PLACE_HOLDER

cd CString
```

then compile with `-c`
```
gcc -c ./src/CString.c -o CString.o
```
this outputs the object file

finally we create the static library with
```
ar -rvs ./CString.o
```
