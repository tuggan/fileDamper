/**
 * Legal shit here
 */

#ifndef PACKAGER_H
#define PACKAGER_H

#include <stdlib.h>

#include "../libs/bitBuilder.h"
#include "../libs/dynamicArray.h"

struct tcpChecksum {
    unsigned long index;
    unsigned long checksum;
};

void * buildTCP_answer(int bool);

void * buildTCP_mode(char mode);

void * buildTCP_checksum(unsigned long index, unsigned long checksum);

void * buildUDP_filepart(unsigned long sizeOfPart, dynArray arr);

unsigned int getTCP_type(void * pkg);

unsigned int getTCP_mode(void * pkg);

struct tcpChecksum getTCP_checksum(void * pkg);

#endif













