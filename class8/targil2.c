#include <stdio.h>


#define SIZE 20

void main()
{
    
}

int getABCombinations(char str[])
{
    int i = 0;
    int mul = 0, combinations = 0;

    while(str[i] != '/0')
    {
        if (str[i] == 'a')
        {
            mul ++;
        }
        else if (str[i] == 'b')
        {
            combinations += mul;
        }
        i++;
    }
    return combinations;
}