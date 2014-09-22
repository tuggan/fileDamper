SHELL=/bin/sh
MAKE=make

CC=clang
WARNINGS := -Wall -Wextra -pedantic -Wshadow -Wpointer-arith -Wcast-align \
            -Wwrite-strings -Wmissing-prototypes -Wmissing-declarations \
            -Wredundant-decls -Wnested-externs -Winline -Wno-long-long \
            -Wuninitialized -Wconversion -Wstrict-prototypes
CFLAGS = -g -std=gnu99
LFLAGS = -lz

BINDIR=bin/

SUBDIRS=src

TARGET = fileDamper
OBJS = $(TARGET).o server.o

NETWORK=network/

all : $(TARGET)
$(TARGET) : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $@

$(TARGET).o : $(TARGET).c $(TARGET).h

server.o : $(NETWORK)server.c $(NETWORK)server.h

clean :
	rm -f $(TARGET) *.o 


