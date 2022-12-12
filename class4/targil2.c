#include <stdio.h>


int increaseDigitByOne(int number);

void main()
{
    int inputNumber;
    scanf("%d", &inputNumber);
    printf("The number where every digit is the same plus 1 is %d\n", increaseDigitByOne(inputNumber));
}

int increaseDigitByOne(int number)
{
    /*
    the function get a number and increase the digits of it by one

    Args:
        int number: natural number
    
    return: number with digits bigger by 1
    */
   int res = 0;
   int mult = 1;
   while (number)
   {
        res += (((number%10) + 1) % 10) * mult;   
        number /= 10;
        mult = mult * 10;
   }
   return res;
}