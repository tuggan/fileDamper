/**
 * Here functions for checking if files are correct will be!
 */
#include "fileHandler.h"

dynArray fileCRCTable(char *fileName) {
    if(fileName == NULL)
        return NULL;

    dynArray a = dynA_init();

    dynA_setFreeFunc(a, free);

    if(a == NULL)
        printf("Could not allocate array...");


    const unsigned long buffSize = CHUNKSIZE;

    unsigned char *buf = malloc(buffSize);

    int fd;
    int bytesRead;
    unsigned long chunk = 0;

    int flags = O_RDONLY;

    fd = open(fileName, flags);

    if(fd == -1)
        return NULL;

    while((bytesRead = pread(fd, buf, buffSize, chunk*buffSize))) {
        chunk++;
        tableNode tn = malloc(sizeof(tableNode));

        tn->crc = crc32(0, buf, bytesRead);
        tn->chunk = chunk;
        tn->bytesLong = bytesRead;

        dynA_append(a, tn);
    }

    free(buf);

    close(fd);

    return a;
}

dynArray validateFile(char* fileName, dynArray crcTable) {
    if(fileName == NULL)
        return NULL;

    dynArray a = dynA_init();

    dynA_setFreeFunc(a, free);

    if(a == NULL)
        printf("Could not allocate array...");


    const unsigned long buffSize = CHUNKSIZE;

    unsigned char *buf = malloc(buffSize);

    int fd;
    int bytesRead;
    unsigned long chunk = 0;

    int flags = O_RDONLY;

    fd = open(fileName, flags);

    if(fd == -1)
        return NULL;

    while((bytesRead = pread(fd, buf, buffSize, chunk*buffSize))) {
        tableNode tn = dynA_get(crcTable, chunk);
        chunk++;

        uLong crc = crc32(0, buf, bytesRead);
        unsigned long lChunk = chunk;
        int bytesLong = bytesRead;

        if(crc != tn->crc || lChunk != tn->chunk || bytesLong != tn->bytesLong)
            dynA_append(a, tn);
    }

    free(buf);

    close(fd);

    if(!dynA_isEmpty(a))
        return a;

    dynA_clear(a);
    return NULL;
}



















