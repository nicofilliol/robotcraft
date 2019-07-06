#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Array.h"

int main()
{
    srand(time(0)); //randomize numbers
    // Create array
    printf("Input size of first array: ");
    int size1;
    scanf("%d", &size1);

    printf("Input size of second array: ");
    int size2;
    scanf("%d", &size2);

    int *arr1 = createArray(size1);
    int *arr2 = createArray(size2);

    printArray(arr1, size1);
    printArray(arr2, size2);

    int *commonArray = (int *)malloc(min(size1, size2) * sizeof(int)); //create array
    int sizeC = commonValues(arr1, size1, arr2, size2, commonArray);

    printf("Common values: ");
    printArray(commonArray, sizeC);

    int *uniqueArray = (int *)malloc(size1 * sizeof(int)); //create array
    int sizeU = uniqueValues(arr1, size1, arr2, size2, uniqueArray);

    printf("Unique values of first array: ");
    printArray(uniqueArray, sizeU);

    return 0;
}