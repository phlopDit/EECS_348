CC=gcc
CFLAGS= -c -Wall
OBJECTS = main.o isEven.o isOdd.o

program: $(OBJECTS)
	$(CC) $(OBJECTS) -o program

main.o: main.c isEven.h isOdd.h
	$(CC) $(CFLAGS) main.c

isEven.o: isEven.c isEven.h
	$(CC) $(CFLAGS) isEven.c

isOdd.o: isOdd.c isOdd.h
	$(CC) $(CFLAGS) isOdd.c

clean: 
	rm -rf *.o 