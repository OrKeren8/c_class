#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_FORMATS 20

void printFormattedIntegers(char *format, char *numbers);
int getAllFormatTokens(char *format, char *formatsArr, char output[][MAX_WORD_LENGTH]);
int getAllNumbers(char *numbers, int *NumbersArr);

void main()
{
    char format[] = "Dec: %d Hex: %x Roman: %r";
    char numbers[] = " 123  10 9";
    printFormattedIntegers(format, numbers);
}

void printFormattedIntegers(char *format, char *numbers)
{
    char formatsArr[MAX_FORMATS] = "\0";
    char output[MAX_WORD_LENGTH][MAX_WORD_LENGTH] = {{"\0"}, {"\0"}, {"\0"}};
    int NumbersArr[MAX_FORMATS] = {0};
    int formatsArrLength, numbersArrLength;
    char *token;

    formatsArrLength = getAllFormatTokens(format, formatsArr, output);
    numbersArrLength = getAllNumbers(numbers, NumbersArr);

    int i = 0;
    while (output[i])
    {
        if (strlen(output[i]) == 1)
        {
            output[i][0] = '\0';
        }
        i++;
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