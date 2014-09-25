/**
 * Legal stuff goes here
 */
#include "bitBuilder.h"

char* bitsToString(void *stream, unsigned long size) {
    char* string = calloc(size+1, sizeof(*string)*CHAR_BIT);
    char* cstream = (char*) stream;
    unsigned long i;
    char l;
    for(i = 0; i < size; i++)
        for(l = (CHAR_BIT-1); l >=0; l--)
            string[i*CHAR_BIT + (CHAR_BIT-1)-l] = (cstream[i]&(1<<l))? '1': '0';
    return string;
}

void setBit(void * stream, unsigned long byte, unsigned char bit, unsigned char state) {
    char * lstream = stream;
    if(bit >= CHAR_BIT)
        return;
    switch(state){
    case 0:
        lstream[byte] &= ~(1 << bit);
        break;
    case 1:
        lstream[byte] |= 1 << bit;
        break;
    }
}

void setChar(void * stream, unsigned long offset, unsigned char b) {
    char *lstream = stream;
    lstream[offset] = b;
}

void setShort(void * stream, unsigned long offset, unsigned int d) {
    char *lstream = stream;
    unsigned long i;
    for(i = 0; i < sizeof(short); i++)
        lstream[offset+(sizeof(short)-1)-i] = (d >> (CHAR_BIT*i));
}

void setInt(void * stream, unsigned long offset, unsigned int d) {
    char *lstream = stream;
    unsigned long i;
    for(i = 0; i < sizeof(int); i++)
        lstream[offset+(sizeof(int)-1)-i] = (d >> (CHAR_BIT*i));
}

void setLong(void * stream, unsigned long offset, unsigned long l) {
    char *lstream = stream;
    unsigned long i;
    for(i = 0; i < sizeof(long); i++)
        lstream[offset+(sizeof(long)-1)-i] = (l >> (CHAR_BIT*i));
}

void setStream(void * stream, unsigned long offset, unsigned long size, void * data) {
    char *lstream = stream;
    char *ldata = data;
    unsigned long i;
    for(i = 0; i < size; i++)
        lstream[offset + i] = ldata[i];
}

unsigned char getBit(void * stream, unsigned long byte, char bit) {
    char * lstream = stream;
    unsigned char ret = 0;
    ret = lstream[byte] && (1 << bit);
    return ret;
}

unsigned char getChar(void * stream, unsigned long offset) {
    char *lstream = stream;
    char c = lstream[offset];
    return c;
}

unsigned short getShort(void * stream, unsigned long offset) {
    unsigned char *lstream = stream;
    unsigned short s = 0;
    int i;
    for(i = sizeof(short)-1; i >= 0; i--)
        s |=  (lstream[offset+(sizeof(short)-1)-i] << i*CHAR_BIT);
    return s;
}

unsigned short getInt(void * stream, unsigned long offset) {
    unsigned char *lstream = stream;
    unsigned short s = 0;
    int i;
    for(i = sizeof(int)-1; i >= 0; i--)
        s |=  (lstream[offset+(sizeof(int)-1)-i] << i*CHAR_BIT);
    return s;
}

unsigned short getLong(void * stream, unsigned long offset) {
    unsigned char *lstream = stream;
    unsigned short s = 0;
    int i;
    for(i = sizeof(long)-1; i >= 0; i--)
        s |=  (lstream[offset+(sizeof(long)-1)-i] << i*CHAR_BIT);
    return s;
}

char * getStream(void *stream, unsigned long offset, unsigned long size) {
    char * lstream = stream;
    char * ret = malloc(size*sizeof(char));
    unsigned long i;
    for(i = 0; i < size; i++)
        ret[i] = lstream[offset+i];
    return ret;
}



















