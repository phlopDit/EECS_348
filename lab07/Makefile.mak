main: main.o Matrix.o
	g++ -std=c++11 main.o Matrix.o -o main

main.o: main.cpp Matrix.h
	g++ -std=c++11 -c main.cpp

Matrix.o: Matrix.cpp Matrix.h
	g++ -std=c++11 -c Matrix.cpp

clean:
	rm -f *.o main