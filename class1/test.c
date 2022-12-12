#include <stdio.h>

void main()
{
    int i=0, m=0;
    for (i; i<3; i++)
    {
        for (m; m<i; m++)
        {
            printf("%d%", m);
        }
    }
}