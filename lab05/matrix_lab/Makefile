CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g
OBJECTS = main.o matrix_lab.o
TARGET = matrix_lab


$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

main.o: main.c matrix_lab.h
	$(CC) $(CFLAGS) -c main.c -o main.o

matrix_lab.o: matrix_lab.c matrix_lab.h
	$(CC) $(CFLAGS) -c matrix_lab.c -o matrix_lab.o

clean:
	rm -f $(OBJECTS) $(TARGET)