CC      = gcc
CFLAGS 	= -Werror
AR      = ar
AFLAGS  = rc
HEADERS = queue.h context.h semaphore.h preempt.h uthread.h
SOURCES = queue.c context.c semaphore.c preempt.c uthread.c
OBJECTS = $(SOURCES:.c=.o)
TARGET  = libuthread.a
 
default: all

all: $(SOURCES) $(TARGET)

clean:
	rm -f $(OBJECTS)
	#rm -f $(TARGET)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(TARGET): $(OBJECTS)
	$(AR) $(AFLAGS) $(TARGET) $(OBJECTS)
	ranlib $(TARGET)


