g++.exe -w -Wall -m32 -g -I..\Mingw\include -c main.cpp
g++.exe -L..\MinGW\lib -o Graphics.exe main.o -m32 -lgdi32