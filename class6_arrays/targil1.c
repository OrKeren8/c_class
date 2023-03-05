#include <stdio.h>
#include <stdbool.h>

#define ARR_LENGTH 5

void fillArray(int arr[], int arrLength);
bool checkOpposite(int arr1[], int arr2[], int arrLength);

void main()
{
    bool opposite;
    int arr1[ARR_LENGTH], arr2[ARR_LENGTH];
    fillArray(arr1, ARR_LENGTH);
    fillArray(arr2, ARR_LENGTH);
    opposite = checkOpposite(arr1, arr2, ARR_LENGTH);
    if (opposite)
        printf("opposite");
    else    
        printf("not opposite");
}

void fillArray(int arr[], int arrLength)
{
    printf("enter arr: ");
    for(int i=0; i<arrLength; i++)
        scanf("%d", &arr[i]);
    printf("\n");
}

bool checkOpposite(int arr1[], int arr2[], int arrLength)
{
    bool opposite = true;
    for(int i=0; i<arrLength && opposite; i++)
    {
        if(arr1[i] != arr2[arrLength-i-1])
        {
            opposite = false;
        }
    }
    return opposite;
}

