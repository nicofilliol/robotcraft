#ifndef ARRAY_H /* Include guard */
#define ARRAY_H

#include <stdio.h>
#include <stdlib.h>

#define max(x, y) ((x) >= (y)) ? (x) : (y)
#define min(x, y) ((x) <= (y)) ? (x) : (y)

int *createArray(int sizeA);
void insertValue(int *a, int value, int *sizeA);
void copyArray(int *originArray, int originSize, int *targetArray, int targetSize);
void printArray(int *array, int size);
int commonValues(int *arr1, int size1, int *arr2, int size2, int *commonArray);
int uniqueValues(int *arr1, int size1, int *arr2, int size2, int *uniqueArray);

#endif
