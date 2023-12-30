#include <stdio.h>

/*
the function gets array and check k parameters in it that has the biggest sum.
in l it returns the index of the first number in this sub array

example for array that returns 17 with k=3 is [15, 1, 1, 1, 1]

O(n*k)
*/

int fun(int data[], int size, int k, int* l)
{
    int i, sum, max, maxIndex;

    
    *l = 0;
    sum=0;
    for(i=0; i<k; i++){
        sum += data[i];
    }
    max = sum;
    maxIndex=0;

    for(i=0; i<(size-k); i++){
        sum -= data[i];
        sum += data[i+k];
        if (sum>max){
            max = sum;
            maxIndex = i+1;
        }
    }
    *l = maxIndex;
    return max;
}

void main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 5, 4, 3, 3, 4,2, 2,1};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    int index;
    int res;

    res = fun(arr, size, k, &index);
    printf("%d %d\n", res, index);
}