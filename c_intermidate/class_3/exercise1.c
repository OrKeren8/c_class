#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE // for strdup() warning. Depends on VS version

#include <stdio.h>
#include <stdlib.h>

typedef struct student
{
    int grade;
    char *name;
} STUDENT;

void getInput(STUDENT ***parr, int *psize);
STUDENT *getHighest(STUDENT **arr, int size);
void sortArray(STUDENT **arr, int size);
// void printAll(??);
// void freeAll(??);

void main()
{
    STUDENT **arr, *max;
    int size;
    getInput(________, __________);
    printAll(???);

    // max = getHighest(arr, size);
    // printf("The best student is %s\n", max->name);
    // max = getHighest(NULL, size);
    // printf("The second best student is %s\n", max->name);
    // max = getHighest(NULL, size);
    // printf("The third best student is %s\n", max->name);
    // sortArray(__________, ___________);
    // printf("The students and their sorted grades are : \n");
    // printAll(???);
    // freeAll(???);
    // system("pause");
}

void getInput(STUDENT ***parr, int *psize){
    int studentArrSize=0;
    STUDENT **studentArr;

    printf("enter number of students\n");
    scanf("%d", studentArrSize);
    studentArr = (STUDENT **)calloc(studentArrSize, sizeof(STUDENT *));
    if (studentArr == NULL){
        
    }
    
}