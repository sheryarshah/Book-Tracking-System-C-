program: main.o 
	g++ -o program main.o 
main.o: main.cpp header.h BookRecord.h ListRecord.h
	g++ -c main.cpp 

