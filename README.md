# bf
A simple brainf*ck interpreter writen in C

# Wrapping
Wrapping is a feature that some brainf*ck interpreters have, however i have chosen to omit it, the user will probably never user more than 20 cells anyway

# Int size
unlike some versions of bf, i have chosen to allow any standard int to be in a cell rather than just 0-255

# Installation
To build and install the program the user can use the 

`make` and `make install` commands

# Usage
To run a brainf*ck file, the user just needs to say

`bf file.bf` *.bf extention is optional*

# Removal
The user can use 

`make uninstall` To remove the program from /usr/local/bin

and 

`make clean` To remove an exisitng binary from the build directory

# Why?
This project mostly consists of me learning more about programing languages as a whole, however for the most part its just for fun

This is obviously over developed considering it's a joke language, but I'm also using this as an opertunity to learn git better
