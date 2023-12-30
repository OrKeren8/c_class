#include <stdio.h>

int numOfDig(int n, int dig);
int mostFrequentDigit(int n);

void main()
{
    int num = 766676675, dig = 4;
    int result = numOfDig(num, dig);
    printf("The result is %d\n", result);
    
    result = mostFrequentDigit(num);
    printf("The result is %d\n", result);
}

int numOfDig(int n, int dig)
{
    /*
    calculate the number of certain digit inside a given number    

    args:
        int n: natural number
        int dig: the digit to find inside the number
    
    return: num of times the digit appear in the number
    */
    int counter = 0;
    while(n)
    {
        if (n % 10 == dig)
        {
            counter++;
        }
        n /= 10; 
    }
    return counter;
}

int mostFrequentDigit(int n)
{
    /*
    find the most frequent digit in a natural number

    args:
        int n: natural number
    
    return: most frequent digit
    */
   int currentDigit = 0, currentDigitCounter = 0;
   int maxDigit = 0, maxDigitCounter = 0;

   while(n)
   {
        currentDigit = n % 10;
        currentDigitCounter = numOfDig(n, currentDigit);
        if (currentDigitCounter > maxDigitCounter)
        {
            maxDigitCounter = currentDigitCounter;
            maxDigit = currentDigit;
        }
        n /= 10;
   }
   return maxDigit;
}