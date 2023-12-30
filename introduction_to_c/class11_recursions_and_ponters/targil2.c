#include <stdio.h>
#include <math.h>


void sumAndDiff(int* arr, int size, int num, int* pCountDiff, int* PCoutSum);

void main()
{
    int CountDiff, CoutSum;
    int arr[9] = {1,5,0,3,6,4,1,2,4};
    sumAndDiff(arr, 9, 3, &CountDiff, &CoutSum);
    printf("%d %d", CountDiff, CoutSum);
}

void sumAndDiff(int* arr, int size, int num, int* pCountDiff, int* PCoutSum)
{
    if (size < 2){
        *pCountDiff = 0;
        *PCoutSum = 0;
        return;
    }

    sumAndDiff(arr, size-1, num, pCountDiff, PCoutSum);
    
    if ((arr[size-1] + arr[size-2]) == num){
        (*PCoutSum) ++; 
    }
    if (abs((arr[size-1] - arr[size-2])) == num){
        (*pCountDiff) ++; 
    }
}
