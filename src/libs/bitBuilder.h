/**
 * Legal stuff goes here
 */

#ifndef BITBUILDER_H
#define BITBUILDER_H

#include <stdlib.h>
#include <limits.h>

char* bitsToString(void * stream, unsigned long size);

void setBit(void * stream, unsigned long byte, unsigned char bit, unsigned char state);

void setChar(void * stream, unsigned long offset, unsigned char b);

void setShort(void * stream, unsigned long offset, unsigned int d);

void setInt(void * stream, unsigned long offset, unsigned int d);

void setLong(void * stream, unsigned long offset, unsigned long l);

void setStream(void * stream, unsigned long offset, unsigned long size, void * data);

unsigned char getBit(void * stream, unsigned long byte, char bit);

unsigned char getChar(void * stream, unsigned long offset);

unsigned short getShort(void * stream, unsigned long offset);

unsigned short getInt(void * stream, unsigned long offset);

unsigned short getLong(void * stream, unsigned long offset);



#endif


















