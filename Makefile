CC = gcc
CFLAGS = -Wall -pthread

TARGET = process_thread

all: $(TARGET)

$(TARGET): process_thread.c
	$(CC) $(CFLAGS) process_thread.c -o $(TARGET)

clean:
	rm -f $(TARGET)
