/**
 * Here will be license later
 */
#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <stdio.h>
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

#endif


















