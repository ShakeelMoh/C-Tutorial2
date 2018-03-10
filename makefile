#My own makefile for fibonacci project

#Declare variables
CC=g++
LIBS=-lm

#First create ".exe" called fibonacci
volimage: volimage1.o volimageDriver.o
	$(CC) volimage1.o volimageDriver.o -o volimage $(LIBS)

#Need to make Fib.o file though
volimage1.o: volimage1.cpp volimage1.h
	$(CC) -c volimage1.cpp

#And the driver file
volimageDriver.o: volimageDriver.cpp
	$(CC) -c volimageDriver.cpp

#Other rules

#Clean .o and exe
clean:
	@rm -f *.o
	@rm -f volimage

#To run program
run:
	./volimage



