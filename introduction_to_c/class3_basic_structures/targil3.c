#include <stdio.h>

void main()
{
    int num, k, counter = 0, current_digit;
    printf("please enter positive decimal number, and a digit\n");
    scanf("%d %d", &num, &k);
    if (k == 0)
        printf("0");
    else
    {
        while(num)
        {
            current_digit = num % 10;
            if (current_digit % k == 0)
                counter ++;
            num /= 10;
        }
        printf("%d\n", counter);
    }
}