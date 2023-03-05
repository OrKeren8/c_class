#include <stdio.h>

void main()
{
    int input, digit, reversInput = 0;
    printf("please insert a three digit number: ");
    scanf("%d", &input);
    for (int i = 0; i < 3; i++)
    {
        digit = input % 10;
        reversInput = (reversInput * 10) + digit;
        printf("%d\n", digit);
        input /= 10;
    }
    printf("%d", reversInput);
}