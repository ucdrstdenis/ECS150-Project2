CC      = gcc
CFLAGS 	= -m64 -Wall -Werror
HEADERS = common.h process.h
SOURCES = libuthread.c common.c process.c
OBJECTS = $(SOURCES:.c=.o)
TARGET  = sshell
 
default: all

all: $(SOURCES) $(TARGET)

clean:
	rm -f $(OBJECTS)
	rm -f $(TARGET)
	rm -rf sshell_test_dir

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

