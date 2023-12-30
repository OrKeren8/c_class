#include <stdio.h>

void main()
{
    float num;
    int sum = 0;
    printf("insert a number in this template 00.00: ");
    scanf("%f", &num);
    num = num * 100;
    
    for(int i = 0; i < 4; i ++)
    {
        sum += (int)num % 10;
        num = (int)num / 10;
    }
 
    printf("%d", sum);
}