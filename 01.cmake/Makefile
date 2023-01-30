CC = gcc
TARGET = cmake.exe
OBJS = .\output\main.o

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) -o $@ $^

main.o:
	$(CC) -c main.c -o .\output\main.o