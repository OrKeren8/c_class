#include <stdio.h>
#include <string.h>

int checkNumLength(int num);
void printMultTable(int maxMult);

void main()
{
    int maxMult;
    printf("Please enter number:\n");
    scanf("%d",&maxMult);
    printMultTable(maxMult);
}

int checkNumLength(int num)
{
    char nString[1000] = "";
    sprintf(nString, "%d", num);
    return strlen(nString);
}

void printMultTable(int maxMult)
{
    int length;

    for (int row = 1; row <= maxMult; row++)
    {
        for (int col = 1; col <= maxMult; col++)
        {
            length = checkNumLength(col * maxMult);
            if (col != 1)
                length++;
            printf("%*d", length, col * row);
        }
        printf("\n");
    }
}