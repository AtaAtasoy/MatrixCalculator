#Makefile for MatrixCalculator
#Compiles the given code, creates an executable file named matrixCalculator and runs it.

CC	= g++
CFLAGS = -std=c++11 -O0
NAME = matrixCalculator

all:
	$(CC)	$(CFLAGS)	*.cpp	-o	$(NAME)
	./matrixCalculator
