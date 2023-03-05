#include <stdio.h>
#include <stdbool.h>


bool isSum(int num1, int num2);

void main()
{
    bool sum;
    sum = isSum(123, 6);
    if (sum){
        printf("Is sum!\n");
    }
    else{
        printf("Is not sum!\n");
    }
}

bool isSum(int num1, int num2){
    if (num1<10){
        if (num1 == num2){
            return true;
        }
        else{
            return false;
        }
    }
    return isSum(num1/10, num2-(num1%10));
}

