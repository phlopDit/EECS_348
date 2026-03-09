CC=gcc
CFLAGS= -c -Wall -Wextra -Werror -Wpedantic -g -std=c11
OBJECTS = lab04.o 

program: $(OBJECTS)
	$(CC) $(OBJECTS) -o program

lab04.o: lab04.c 
	$(CC) $(CFLAGS) lab04.c

clean: 
	rm -rf *.o 