#include <stdio.h>

#define SYMBOL '#' 

typedef struct rect_data{
    int width, height;
    char a, b, c, d;
}RECT_DATA;

RECT_DATA readData();
void printRectangle(RECT_DATA rectangle);
char charToPrint(int x, int y, RECT_DATA rectangle);

void main()
{
    RECT_DATA rectangle;
    rectangle = readData();
    printRectangle(rectangle);
    // rectangle = updateFrame(rectangle);
    // printRectangle(rectangle);
}

RECT_DATA readData()
{
    RECT_DATA rectangle;
    printf("please enter width and hight: ");
    scanf(" %d %d", &rectangle.width, &rectangle.height);
    printf("please enter quarters initials: ");
    scanf(" %c %c %c %c", &rectangle.a, &rectangle.b, &rectangle.c, &rectangle.d);
    return rectangle;
}

void printRectangle(RECT_DATA rectangle)
{
    for (int i = 0; i <  (rectangle.height + 2); i++)
        printf("%c", SYMBOL);
    printf("\n");
    for (int y = 0; y <  rectangle.height; y++)
    {
        printf("%c", SYMBOL);
        for (int x=0; x < rectangle.width; x++)
        {
            printf("%c", charToPrint(x, y, rectangle));
        }
        printf("#\n");
    }
    for (int i = 0; i <  (rectangle.height + 2); i++)
        printf("%c", SYMBOL);
}

char charToPrint(int x, int y, RECT_DATA rectangle)
{
    char currentChar;
    if (y < (rectangle.height / 2))
    {
        if (x < (rectangle.width / 2))
            currentChar = rectangle.a;
        else    
            currentChar = rectangle.b;

    }
    else
    {
        if (x < (rectangle.width / 2))
            currentChar = rectangle.d;
        else    
            currentChar = rectangle.c;
    }
}