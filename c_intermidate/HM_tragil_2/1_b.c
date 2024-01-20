#include <stdio.h>
#include <stdlib.h>

#define SIZE 100
#define DESCEND 1

void pointerSort(int *arr, unsigned int size, int ascend_flag, int ***pointers);
void pointerMergeSort(int **pPointersArr, unsigned int size);
void memoryError();
void mergeTwoArr(int **pPointersArr1, unsigned int size1, int **pPointersArr2, unsigned int size2, int **resArr);
void copyArr(int **pPointersArr, int **tmpArr, unsigned int size);
void printPointers(int **pointers, unsigned int size);
void flipArr(int **pPointersArr, unsigned int size);

void main()
{
    unsigned int size, i;
    int arr[SIZE];
    int **pointers;
    int ascend_flag;

    scanf("%u", &size);

    for (i = 0; i < size; i++)
        scanf("%d", &arr[i]);
    scanf("%d", &ascend_flag);
    pointerSort(arr, size, ascend_flag, &pointers);
    printPointers(pointers, size);
    free(pointers);
}

void pointerSort(int *arr, unsigned int size, int ascend_flag, int ***pointers)
{
    int **pPointersArr;

    // create pointers arr
    pPointersArr = (int **)malloc(size * sizeof(int *));
    if (pPointersArr == NULL)
        memoryError();

    // fill pointer arr with pointers to the int arr places
    for (unsigned int i = 0; i < size; i++)
    {
        pPointersArr[i] = &arr[i];
    }

    // sort pointers arr with merge sort
    pointerMergeSort(pPointersArr, size);

    // flip array if necessary
    if (ascend_flag != DESCEND)
    {
        flipArr(pPointersArr, size);
    }

    *pointers = pPointersArr;
}

void memoryError()
{
    printf("Memory allocation arror!");
    exit(1); // exit the program
}

void pointerMergeSort(int **pPointersArr, unsigned int size)
{
    int **tmpArr = NULL;
    if (size <= 1)
        return;

    // call to merge sort with the two halfs of the pointer arr
    pointerMergeSort(pPointersArr, size / 2);
    pointerMergeSort(pPointersArr + size / 2, size - size / 2);

    tmpArr = (int **)malloc(size * sizeof(int *));
    if (tmpArr)
    {
        mergeTwoArr(pPointersArr, size / 2, pPointersArr + size / 2, size - size / 2, tmpArr);
        copyArr(pPointersArr, tmpArr, size);
        free(tmpArr);
    }
    else
    {
        memoryError();
    }
}

void mergeTwoArr(int **pPointersArr1, unsigned int size1, int **pPointersArr2, unsigned int size2, int **resArr)
{
    int index1, index2, resIndex;
    index1 = index2 = resIndex = 0;

    while ((index1 < size1) && (index2 < size2))
    {
        if (*pPointersArr1[index1] < *pPointersArr2[index2])
        {
            resArr[resIndex] = pPointersArr1[index1];
            index1++;
        }
        else
        {
            resArr[resIndex] = pPointersArr2[index2];
            index2++;
        }
        resIndex++;
    }

    // if one array is shorter than the other
    while (index1 < size1)
    {
        resArr[resIndex] = pPointersArr1[index1];
        index1++;
        resIndex++;
    }

    while (index2 < size2)
    {
        resArr[resIndex] = pPointersArr2[index2];
        index2++;
        resIndex++;
    }
}

void copyArr(int **pPointersArr, int **tmpArr, unsigned int size)
{
    for (unsigned int i = 0; i < size; i++)
    {
        pPointersArr[i] = tmpArr[i];
    }
}

void printPointers(int **pointers, unsigned int size)
{
    for (unsigned int i = 0; i < size; i++)
    {
        printf("%d ", *pointers[i]);
    }
    // printf("\n");
}

void flipArr(int **pPointersArr, unsigned int size)
{
    int *temp;
    for (unsigned int i = 0; i < size / 2; i++)
    {
        temp = pPointersArr[size - 1 - i];
        pPointersArr[size - 1 - i] = pPointersArr[i];
        pPointersArr[i] = temp;
    }
}