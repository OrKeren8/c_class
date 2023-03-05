#include <stdio.h>

#define ARR_SIZE 5

void changeArray(int arr[], int size);

void main()
{
    int arr[ARR_SIZE] = {0};
    changeArray(arr, ARR_SIZE);

}

void changeArray(int arr[], int size)
{
   for (int i = 0 ; i < size; i++)
   {
        printf("%d ", arr[i]);
   } 
}