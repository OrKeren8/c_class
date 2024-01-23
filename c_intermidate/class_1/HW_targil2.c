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
    char format[MAX_WORD_LENGTH];
    char numbers[MAX_WORD_LENGTH];
    gets(format);
    gets(numbers);
    printFormattedIntegers(format, numbers);
}


void printFormattedIntegers(char *format, char *numbers)
{
    /*prints a formatted text with serveral given formats.
    the formats are:
    %d: for decimal number
    %x: for hexadecimal number
    %o: for octal number
    %b: for binary number
    %r: for rome format number

    args:
        char *format: string of the formatted text
        char *numbers: string that contain all of the numbers that are in the formatted string to show
    
    return: null
    */
    char formatsArr[MAX_FORMATS] = "\0";  // arr of all formats in the formatted string
    char output[MAX_WORD_LENGTH][MAX_WORD_LENGTH] = {""};  // 2 dim array that contains all of the words to print in the output
    int NumbersArr[MAX_FORMATS] = {0};  
    int formatsArrLength, numbersArrLength;
    char *token;

    formatsArrLength = getAllFormatTokens(format, formatsArr, output);  //get all of the formats
    numbersArrLength = getAllNumbers(numbers, NumbersArr);  // get all of the numbers

    int i = 0, formatsIndex = 0;
    //loop through all of the formats,and check if they are formats aka contain 1 char as d, or x
    while (strlen(output[i]) > 0)
    {
        if (strlen(output[i]) == 1)
        {
            output[i][0] = '\0';
            // convert the corresponding number to the requested format
            convertToFormat(output[i], formatsArr[formatsIndex], NumbersArr[formatsIndex]);
            formatsIndex++;
        }
        if(i!=0)
            printf(" ");
        printf("%s", output[i]);  // print every word separated in the output string array
        i++;
    }
}


int getAllFormatTokens(char *format, char *formatsArr, char output[][MAX_WORD_LENGTH])
{
    /*extract all of the formats and create output string array separated by words 
    
    input args:
        char *format: string with the requested formatted text
    output args:
        char *formatsArr: array of chars, every char is a format, as d for decimal or x for hexadecimal
        char output[][MAX_WORD_LENGTH]: array of strings which filled with every word in the formatted text
            the format strings will be replaced with the converted numbers farther on
    return: int index: the amount of token found in the strings
    */
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

void convertToFormat(char output[], char format, int numToConvert)
{
    /*converts given number to requested format 

    input args:
        char format: the format to convert to 
        int numToConvert: the number to convert with given format

    output args:    
        char output[]: string contains the converted number

    return: Null
    */
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

int getAllNumbers(char *numbers, int *NumbersArr)
{
    /*extract every number in a string
    
    input args:
        char *numbers: string that contain several numbers separated with numbers
    
    output args:
        int *NumbersArr: Arr of numbers from the given string
    
    return: int index: the amount of numbers found in the string
    */
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
    /*convert an int number into binary string

    input args:
        int numberToConvert: the number to convert
    
    output args:
        char convertedStr[]: string with the binary representation of the given number
    
    return: Null
    */
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
    /*convert an int number into rome representation string

    input args:
        int num: the number to convert
    
    output args:
        char convertedStr[]: string with the rome representation of the given number
    
    return: Null
    */
    int nums[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char romeNums[][3] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    
    while (num !=0){
        for(int m=0; m<=12; m++){
           if (num >= nums[m])
            {
                strcat(convertedStr, romeNums[m]);
                num -= nums[m];
                break;
            } 
        }
    }
}