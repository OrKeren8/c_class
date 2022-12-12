#include <stdio.h>
#include <stdbool.h>


#define SIZE 7

int findChange(int arr[], int n);

void main()
{
    int arr[SIZE] = {2, 4, 8 ,7, 5, 4, 3};
    int index = findChange(arr, SIZE);
    printf("%d %d", arr[index], arr[index + 1]);
}

int findChange(int arr[], int n);
{
    int i=1;
    while((arr[i] % 2) == 0)
    {
        i++;
    }
    return i - 1;
}