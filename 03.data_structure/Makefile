CC = gcc
TARGET = .\main.exe
OBJS = .\main.o .\util\error.o .\SinglyLinkedList\SinglyLinkedList.o .\Stack\Stack.o .\Queue\Queue.o

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) -o $@ $^

.c.o:
	$(CC) -c -o $@ $<

clean:
	rm -rf **/*.o