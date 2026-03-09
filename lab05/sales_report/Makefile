CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g
OBJECTS = main.o sales_report.o
TARGET = sales_report


$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

main.o: main.c sales_report.h
	$(CC) $(CFLAGS) -c main.c -o main.o

sales_report.o: sales_report.c sales_report.h
	$(CC) $(CFLAGS) -c sales_report.c -o sales_report.o

clean:
	rm -f $(OBJECTS) $(TARGET)


