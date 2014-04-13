#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <zlib.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    const unsigned long buffSize = 1000;
    
    unsigned char *buf = malloc(buffSize);

    if(argc == 1)
        return 1;
    
    int fd;
    int bytesRead;
    unsigned long chunk = 0;

    int flags = O_RDONLY;

    fd = open(argv[1], flags);

    if(fd == -1)
        return -1;

    do {
        bytesRead = pread(fd, buf, buffSize, chunk*buffSize);
        chunk++;
        uLong crc = crc32(0, buf, bytesRead);
        printf("Chunk: %lu Size: %d CRC: %lu\n", chunk, bytesRead, crc);
    } while(bytesRead > 0);
    
    
    close(fd);
    
    return 0;
}























