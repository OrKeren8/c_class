#include <stdio.h>

void main()
{
    char c1, c2, c3;
    float avg;
    printf("please insert three characters: ");
    scanf("%c%c%c", &c1, &c2, &c3);
    avg = (float)(c1 + c2 + c3) / 3;
    printf("%f", avg);
}