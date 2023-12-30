#include <stdio.h>

#define SIZE 101

void eraseCharFromStr(char str[], char ch);

void main()
{
    char str[SIZE];
    int res;
    char eraseChar;

}

void eraseCharFromStr(char str[], char ch)
{
    int i=0, j=0;
    while(str[i] != 0)
    {
        if (str[j] == ch)
        {
            str[i] == str[j];
            i++;
        }
        j++;
    }
    str[i] = '/0';
}