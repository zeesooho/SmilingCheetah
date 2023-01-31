CC = gcc
TARGET = .\main.exe
OBJS = .\main.o .\printLine.o .\printLines.o

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) -o $@ $^

.c.o:
	$(CC) -c -o $@ $<

clean:
	rm -f *.o