CC = gcc
CFLAGS = -Iinclude -Werror -Wall -std=c99

TARGET = calendar
SOURCES = $(wildcard src/*.c)
OBJECTS = $(SOURCES:src/%.c=build/%.o)

all : $(TARGET)

$(TARGET) : $(OBJECTS)
	$(CC) $^ -lm -o $@

build/%.o : src/%.c
	mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJECTS) $(TARGET)

.PHONY: clean all
