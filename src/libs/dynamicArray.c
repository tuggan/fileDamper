/**
 * This is kinda like a vector in c++, i hope.
 * @TODO This can't understand if it's as long as unsingned long.
 * @TODO Add a shrink to size function!
 */

#include "dynamicArray.h"

dynArray dynA_init() {
    return dynA_init(256);
}

dynArray dynA_init(unsigned long size) {
    struct dynamicArray *a = malloc(sizeof(struct dynamicArray));
    if(a == NULL)
        return NULL;
    a->currSize = 0;
    a->arrSize = size;
    a->array = malloc(sizeof(void*)*size);
    if(a->array == NULL) {
        free(a);
        return NULL;
    }
    dynArray ret = &a;
    return ret;
}

void dynA_setFreeFunc(dynArray a, int (*freeFunc)(void*)) {
    (*a)->clearFunc = freeFunc;
}

int dynA_append(dynArray a, void* val) {
    if(dynA_reachedLimit(a) < 0)
        return -1;
    (*a)->array[(*a)->currSize] = val;
    (*a)->currSize++;
    return 0;
}

// @TODO This funtion could be a bit more dynamic
int dynA_reachedLimit(dynArray a) {
    if((*a)->currSize+10 >= (*a)->arrSize) {
        if((*a)->arrSize *2 > (*a)->arrSize)
            return dynA_extend(a, (*a)->arrSize*2);
    }
    return 0;
}

int dynA_extend(dynArray a, unsigned long newSize) {
    void* newArr = realloc((*a)->array, sizeof(void*) * newSize);
    if(newArr == NULL)
        return -1;
    (*a)->array = newArr;
    (*a)->arrSize = newSize;
    return 0;
}

unsigned long dynA_size(dynArray a) {
    return (*a)->currSize;
}

int dynA_isEmpty(dynArray a) {
    return ((*a)->currSize == 0);
}

int dynA_remove(dynArray a, unsigned long index) {
    unsigned long i = index;
    unsigned long size = (*a)->currSize-1;
    for(; i < size; i++) {
        if((*a)->clearFunc != NULL)
            if( (*a)->clearFunc((*a)->array[i]) < 0 )
                return -1;
        (*a)->array[i] = (*a)->array[i+1];
    }
    (*a)->currSize--;
    return 0;
}

int dynA_insert(dynArray a, unsigned long index, void* val) {
    if(dynA_reachedLimit(a) < 0)
        return -1;
    unsigned long i = (*a)->currSize;
    unsigned long place = index;
    for(; i > place ; i--){
        (*a)->array[i] = (*a)->array[i-1];
    }
    (*a)->array[index] = val;
    (*a)->currSize++;
    return 0;
}

void* dynA_get(dynArray a, unsigned long index) {
    if(index >= (*a)->currSize)
        return NULL;
    return (*a)->array[index];
}

int dynA_set(dynArray a, unsigned long index, void* val) {
    if(index >= (*a)->currSize)
        return -1;
    if((*a)->clearFunc != NULL)
        if((*a)->clearFunc((*a)->array[index]) < 0)
            return -1;
    (*a)->array[index] = val;
}

int dynA_clear(dynArray a) {
    if((*a) == NULL)
        return -1;
    if((*a)->clearFunc != NULL && !dynA_isEmpty(a)) {
        unsigned long i = 0;
        for(; i < (*a)->currSize; i++)
            if((*a)->clearFunc((*a)->array[i]) != 0)
                return -2;
    }
    free((*a)->array);
    free(*a);
    // @TODO check that above free worked.
    return 0;
}




















