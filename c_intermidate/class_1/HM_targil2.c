#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 100
#define MAX_FORMATS 20

void printFormattedIntegers(char *format, char *numbers);
int getAllFormatTokens(char *format, char *formatsArr, char output[][MAX_WORD_LENGTH]);
int getAllNumbers(char *numbers, int *NumbersArr);
void convertToFormat(char output[], char format, int numToConvert);
void convertIntToBinaryStr(int numberToConvert, char convertedStr[]);
void convertIntToRomanStr(int num, char convertedStr[]);

void main()
{
    char format[100];
    char numbers[100];
    gets(format);
    gets(numbers);
    printFormattedIntegers(format, numbers);
}

void printFormattedIntegers(char *format, char *numbers)
{
    char formatsArr[MAX_FORMATS] = "\0";
    char output[MAX_WORD_LENGTH][MAX_WORD_LENGTH] = {""};
    int NumbersArr[MAX_FORMATS] = {0};
    int formatsArrLength, numbersArrLength;
    char *token;

    formatsArrLength = getAllFormatTokens(format, formatsArr, output);
    numbersArrLength = getAllNumbers(numbers, NumbersArr);

    int i = 0, formatsIndex = 0;
    while (output[i] && i < MAX_WORD_LENGTH)
    {
        if (strlen(output[i]) == 1)
        {
            output[i][0] = '\0';
            convertToFormat(output[i], formatsArr[formatsIndex], NumbersArr[formatsIndex]);
            formatsIndex++;
        }
        printf("%s ", output[i]);
        i++;
    }
}

void convertToFormat(char output[], char format, int numToConvert)
{
    char convertedStr[MAX_WORD_LENGTH] = "";
    switch (format)
    {
    case 'd':
        sprintf(output, "%d", numToConvert);
        break;
    case 'x':
        sprintf(output, "%x", numToConvert);
        break;
    case 'o':
        sprintf(output, "%o", numToConvert);
        break;
    case 'b':
    {
        convertIntToBinaryStr(numToConvert, convertedStr);
        sprintf(output, "%s", convertedStr);
        break;
    }
    case 'r':
    {
        convertIntToRomanStr(numToConvert, convertedStr);
        sprintf(output, "%s", convertedStr);
        break;
    }
    }
}
int getAllFormatTokens(char *format, char *formatsArr, char output[][MAX_WORD_LENGTH])
{
    char separators[] = "\% ";
    char *token;
    int index = 0, i = 0;

    token = strtok(format, separators);
    while (token != NULL)
    {
        strcat(output[i], token);
        if (strlen(token) == 1)
        {
            formatsArr[index] = token[0];
            if (formatsArr[index] == 'b')
                token[0] = 'd';
            if (formatsArr[index] == 'r')
                token[0] = 's';
            index++;
        }
        token = strtok(NULL, separators);
        i++;
    }
    return index;
}

int getAllNumbers(char *numbers, int *NumbersArr)
{
    char separators[] = " ";
    char *token;
    int index = 0;

    token = strtok(numbers, separators);
    while (token != NULL)
    {
        NumbersArr[index] = atoi(token);
        index++;
        token = strtok(NULL, separators);
    }
    return index;
}

void convertIntToBinaryStr(int numberToConvert, char convertedStr[])
{
    int binaryNum = 0, add = 0, i = 1;
    while (numberToConvert != 0)
    {
        add = numberToConvert % 2;
        numberToConvert /= 2;
        binaryNum += add * i;
        i *= 10;
    }
    sprintf(convertedStr, "%d", binaryNum);
}

void convertIntToRomanStr(int num, char convertedStr[])
{
    while (num != 0)
    {
        if (num >= 1000) // 1000 - m
        {
            strcat(convertedStr, "M");
            num -= 1000;
        }
        else if (num >= 900) // 900 -  cm
        {
            strcat(convertedStr, "CM");
            num -= 900;
        }
        else if (num >= 500) // 500 - d
        {
            strcat(convertedStr, "D");
            num -= 500;
        }
        else if (num >= 400) // 400 -  cd
        {
            strcat(convertedStr, "CD");
            num -= 400;
        }
        else if (num >= 100) // 100 - c
        {
            strcat(convertedStr, "C");
            num -= 100;
        }
        else if (num >= 90) // 90 - xc
        {
            strcat(convertedStr, "XC");
            num -= 90;
        }
        else if (num >= 50) // 50 - l
        {
            strcat(convertedStr, "L");
            num -= 50;
        }
        else if (num >= 40) // 40 - xl
        {
            strcat(convertedStr, "XL");
            num -= 40;
        }
        else if (num >= 10) // 10 - x
        {
            strcat(convertedStr, "X");
            num -= 10;
        }
        else if (num >= 9) // 9 - ix
        {
            strcat(convertedStr, "IX");
            num -= 9;
        }
        else if (num >= 5) // 5 - v
        {
            strcat(convertedStr, "V");
            num -= 5;
        }
        else if (num >= 4) // 4 - iv
        {
            strcat(convertedStr, "IV");
            num -= 4;
        }
        else if (num >= 1) // 1 - i
        {
            strcat(convertedStr, "I");
            num -= 1;
        }
    }
}