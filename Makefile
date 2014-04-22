CC=clang
WARNINGS := -Wall -Wextra -pedantic -Wshadow -Wpointer-arith -Wcast-align \
            -Wwrite-strings -Wmissing-prototypes -Wmissing-declarations \
            -Wredundant-decls -Wnested-externs -Winline -Wno-long-long \
            -Wuninitialized -Wconversion -Wstrict-prototypes
CFLAGS = -g -c
LFLAGS = -lz

TARGET = fileDamper
OBJS = $(TARGET).o server.o

NETWORK=network/

all : $(TARGET)
$(TARGET) : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $@

$(TARGET).o : $(TARGET).c $(TARGET).h
	$(CC) $(CFLAGS) $(TARGET).c -o $@

server.o : $(NETWORK)server.c $(NETWORK)server.h
	$(CC) $(CFLAGS) $(NETWORK)server.c -o $@

clean :
	rm -f $(TARGET) *.o 


