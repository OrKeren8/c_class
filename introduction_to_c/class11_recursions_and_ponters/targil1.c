#include <stdarg.h>


void reverseNum(int num, int* revNum, int* sumOfEven);

void main()
{
    int revNum = 0, sumOfEven = 0;
    reverseNum(29102, &revNum, &sumOfEven);
    printf("%d %d", revNum, sumOfEven);
}

void reverseNum(int num, int* revNumP, int* sumOfEvenP)
{
    int digit;
    
    if (num==0){
        return;
    }

    digit = num%10;
    num /= 10;
    if (!(digit%2)){
        *sumOfEvenP += digit;
    }
    *revNumP *= 10;
    *revNumP += digit;
    reverseNum(num, revNumP, sumOfEvenP);
}