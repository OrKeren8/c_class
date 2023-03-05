#include <stdio.h>

int strToInt(char num[]);
void sumString(char str1[], char str2[], char sumStr[]);
void intToString(int num, char number[]);
int numLength(int num);

void main()
{
    char num[] = "1023";
    char sumStr[100] = "";
    sumString(num, num, sumStr);
    printf("number: %s", sumStr);
}

int strToInt(char num[])
{
    int i = 0, number = 0;
    while(num[i] != '\0')
    {
        number = number*10 + (num[i] - '0');
        i++;
    }
    return number;
}

void intToString(int num, char number[])
{
    int digit, length;

    length = numLength(num);
    while(length > 0)
    {
        digit = num % 10;
        number[length--] = digit + (int)'0';
        num /= 10;
        // length --;
    }
    number[length] = '\0';
}

int numLength(int num)
{
    int counter = 0;
    while(num)
    {
        num /= 10;
        counter++;
    }
    return counter;
}

void sumString(char str1[], char str2[], char sumStr[])
{
    int n1, n2, sum;

    n1 = strToInt(str1);
    n2 = strToInt(str2);
    sum = n1 + n2;
    intToString(sum, sumStr);
}