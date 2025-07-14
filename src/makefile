CC = gcc
CFLAGS = -Werror -Wall -std=c99
TARGET = calendar
SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)

all : $(TARGET)

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ -lm

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJECTS) $(TARGET)

.PHONY: clean all
