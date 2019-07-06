#include "Array.h"

int *createArray(int sizeA)
{
    int *array;
    array = (int *)malloc(sizeA * sizeof(int)); // reserve memory

    for (int i = 0; i < sizeA; i++)
    {
        int val = (rand() % 11);
        *(array + i) = val;
    }

    return array;
}

void printArray(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d  ", *(array + i));
    }
    printf("\n");
}

int commonValues(int *arr1, int size1, int *arr2, int size2, int *commonArray)
{

    int counter = 0;

    for (int i = 0; i < size1; i++)
    {

        int n1 = *(arr1 + i); // value of first array

        for (int j = 0; j < size2; j++)
        {
            int n2 = *(arr2 + j);

            if (n1 == n2)
            {
                int existing = 0;

                for (int z = 0; z < counter; z++)
                {
                    if (n1 == *(commonArray + z))
                    {
                        existing = 1;
                    }
                }

                if (existing == 0)
                {
                    *(commonArray + counter) = n1;
                    ++counter;
                }
            }
        }
    }
    return counter;
}

int uniqueValues(int *arr1, int size1, int *arr2, int size2, int *uniqueArray)
{

    int counter = 0;

    int *commonArray = (int *)malloc(min(size1, size2) * sizeof(int)); //create array
    int sizeC = commonValues(arr1, size1, arr2, size2, commonArray);

    for (int i = 0; i < size1; i++)
    {
        int val = *(arr1 + i);

        // Check if its inside common values
        _Bool common = 0;

        for (int j = 0; j < sizeC; j++)
        {
            int comVal = *(commonArray + j);

            if (val == comVal)
            {
                common = 1;
                break;
            }
        }

        if (common == 0)
        {
            *(uniqueArray + counter) = val;
            counter++;
        }
    }
    return counter;
}