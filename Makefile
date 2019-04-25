main.o:main.cpp Table.h TableManager.h
	g++ -c main.cpp

main:main.o
	g++ -o main main.o