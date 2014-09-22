/**
 * Things will be here later...
 */

#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <stdlib.h>

struct dynamicArray {
    void **array;
    unsigned long currSize;
    unsigned long arrSize;
    int (*clearFunc)(void*);
};

typedef struct dynamicArray **dynArray;

dynArray dynA_init();

dynArray dynA_init(unsigned long size);

void dynA_setFreeFunc(dynArray a, int (*freeFunc)(void*));

int dynA_append(dynArray a, void* val);

int dynA_reachedLimit(dynArray a);

int dynA_extend(dynArray a, unsigned long newSize);

unsigned long dynA_size(dynArray a);

int dynA_isEmpty(dynArray a);

int dynA_remove(dynArray a, unsigned long index);

int dynA_insert(dynArray a, unsigned long index, void* val);

void* dynA_get(dynArray a, unsigned long index);

int dynA_set(dynArray a, unsigned long index, void* val);

int dynA_clear(dynArray a);

#endif




















