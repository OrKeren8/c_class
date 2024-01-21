#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE // for strdup() warning. Depends on VS version you might need to use _strdup()
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LINE_LEN 80

typedef struct student
{
    int grade;
    char *name;
} STUDENT;

void getInput(STUDENT ***parr, int *psize);
STUDENT *getHighest(STUDENT **arr, int size);
void sortArray(STUDENT **arr, int size);
void swap(STUDENT **a, STUDENT **b);
void printAll(STUDENT **arr, int size);
void freeAll(STUDENT **parr, int size);

void main(void)
{
    STUDENT **arr, *max;
    int size;

    getInput(&arr, &size);
    printAll(arr, size);
    max = getHighest(arr, size);
    printf("The best student is %s\n", max->name);
    max = getHighest(NULL, size);
    printf("The second best student is %s\n", max->name);
    max = getHighest(NULL, size);
    printf("The third best student is %s\n", max->name);
    sortArray(arr, size);
    printf("The students and their sorted grades are : \n");
    printAll(arr, size);
    freeAll(arr, size);
    system("pause");
}

void getInput(STUDENT ***parr, int *psize)
{
    STUDENT **arr;
    int size, i;
    char tmp[MAX_LINE_LEN + 1];

    printf("Please enter the number of students to be entered: ");
    scanf("%d", &size);
    arr = (STUDENT **)malloc(size * sizeof(STUDENT *));
    for (i = 0; i < size; i++)
    {
        arr[i] = (STUDENT *)malloc(sizeof(STUDENT));
        scanf("%d%s", &(arr[i]->grade), tmp);
        arr[i]->name = strdup(tmp);
    }
    *psize = size;
    *parr = arr;
}
STUDENT *getHighest(STUDENT **arr, int size)
{
    int i;
    static STUDENT **arrSaver = NULL;
    static STUDENT *lastMax = NULL;
    STUDENT *max = NULL;
    if (arr != NULL) // The standard max finding algorithm
    {
        arrSaver = arr;
        max = arr[0];
        for (i = 1; i < size; i++)
        {
            if (arr[i]->grade > max->grade)
                max = arr[i];
        }
    }
    else
    {
        bool found = false;
        arr = arrSaver;
        // Initialize max with the first value which is lower than the previous lastMax
        for (i = 0; i < size && !found; i++)
            if (arr[i]->grade < lastMax->grade)
            {
                max = arr[i];
                found = true;
            }
        for (i = 0; i < size; i++)
        {
            if ((arr[i]->grade > max->grade) && (arr[i]->grade < lastMax->grade))
                max = arr[i];
        }
    }
    lastMax = max;
    return max;
}
void sortArray(STUDENT **arr, int size)
{
    int i, j;
    for (i = 0; i < size - 1; i++)
    {
        for (j = size - 1; j > i; j--)
        {
            if (arr[j]->grade < arr[j - 1]->grade)
                swap(&arr[j], &arr[j - 1]);
        }
    }
}

void swap(STUDENT **a, STUDENT **b)
{
    STUDENT *tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

void printAll(STUDENT **arr, int size)
{
    int i;

    for (i = 0; i < size; i++)
    {
        printf("%d: %s received %d\n", i + 1, arr[i]->name, arr[i]->grade);
    }
}

void freeAll(STUDENT **arr, int size)
{
    int i;

    for (i = 0; i < size; i++)
    {
        free(arr[i]->name);
        free(arr[i]);
    }
    free(arr);
}