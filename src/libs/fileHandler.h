/**
 * Here will be license later
 */
#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#define CHUNKSIZE 65535

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <zlib.h>

#include "dynamicArray.h"

struct crcHeader {
    unsigned long chunk;
    int bytesLong;
    uLong crc;
};

typedef struct crcHeader *tableNode;

dynArray fileCRCTable(char *fileName);

dynArray validateFile(char* fileName, dynArray crcTable);

#endif


















