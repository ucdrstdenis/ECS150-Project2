CC      = gcc
CFLAGS 	= -m64 -Wall -Wno-deprecated
AR      = ar
AFLAGS  = rc
HEADERS = queue.h context.h uthread.h  semaphore.h preempt.h
SOURCES = queue.c context.c uthread.c  semaphore.c preempt.c
OBJECTS = $(SOURCES:.c=.o)
TARGET  = libuthread.a
 
default: all

all: $(SOURCES) $(TARGET)

clean:
	rm -f $(OBJECTS)
	rm -f $(TARGET)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(TARGET): $(OBJECTS)
	$(AR) $(AFLAGS) $(TARGET) $(OBJECTS)
	ranlib $(TARGET)


