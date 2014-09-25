/**
 * Legal stuff here i guess
 *
 * @TODO Build in some kind of error checking here
 */
#include "packager.h"

void * buildTCP_answer(int bool) {
    void * pkg = calloc(1, sizeof(int));
    if(bool) {
        setInt(pkg, 0, 10);
    } else {
        setInt(pkg, 0, 0);
    }
    return pkg;
}

void * buildTCP_mode(char mode) {
    void * pkg = calloc(2, sizeof(int));
    setInt(pkg, 0, 30);
    unsigned int iMode;
    switch(mode) {
    case 's':
        iMode = 0;
        break;
    case 'r':
        iMode = 10;
        break;
    }
    setInt(pkg, sizeof(int), iMode);
    return pkg;
}

void * buildTCP_checksum(unsigned long index, unsigned long checksum) {
    unsigned long size = sizeof(int);
    size += sizeof(long)*2;
    void * pkg = calloc(1, size);
    unsigned long offset = 0;
    setInt(pkg, offset, 20);
    offset += sizeof(int);
    setLong(pkg, offset, index);
    offset += sizeof(long);
    setLong(pkg, offset, checksum);
    return pkg;
}

void * buildUDP_filepart(unsigned long sizeOfPart, dynArray arr) {
    unsigned long size;
    size = sizeof(int);
    size += sizeof(long);
    size += sizeOfPart + dynA_size(arr);
    void * pkg = calloc(1, size);
    unsigned long offset = 0;
    setInt(pkg, offset, 20);
    offset += sizeof(int);
    setLong(pkg, offset,  sizeOfPart * dynA_size(arr));
    offset += sizeof(long);
    unsigned long i;
    for(i = 0; i < dynA_size(arr); i++){
        setStream(pkg, offset, sizeOfPart, dynA_get(arr, i));
        offset += sizeOfPart;
    }
    return pkg;
}

unsigned int getTCP_type(void * pkg) {
    unsigned int ret = getInt(pkg, 0);
    return ret;
}

unsigned int getTCP_mode(void * pkg) {
    unsigned int ret = getInt(pkg, sizeof(int));
    return ret;
}

struct tcpChecksum getTCP_checksum(void * pkg) {
    struct tcpChecksum tcs;
    unsigned long offset = sizeof(int);
    tcs.index = getLong(pkg, offset);
    offset+= sizeof(long);
    tcs.checksum = getLong(pkg, offset);
    return tcs;
}



















