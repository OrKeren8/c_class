#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_MONTH 4
#define NUM_OF_MONTHS 12

bool dateInFormat(char *inDate, char *outDate);
bool checkDay(int day);
bool checkYear(int year);
bool checkIntMonth(int month);
bool checkStrMonth(char *month, int *monthNum);

char inDate[] = "";
char ouyDate[] = "";

void main()
{
    char inDate[] = "21 JAN 2016";
    char outDate[100] = "";
    dateInFormat(inDate, outDate);
    printf("%s", outDate);
}

bool dateInFormat(char *inDate, char *outDate)
{
    int day, month, year;
    char monthStr[MAX_MONTH] = "";
    bool res = false;
    if (sscanf(inDate, "%d/%d/%d", &day, &month, &year) == 3)
    {
        if (checkDay(day) && checkIntMonth(month) && checkYear(year))
        {
            sprintf(outDate, "%d-%d-%d", day, month, year);
            res = true;
        }
    }
    else if (sscanf(inDate, "%d %s %d", &day, &monthStr, &year) == 3)
    {
        if (checkDay(day) && checkStrMonth(monthStr, &month) && checkYear(year))
        {
            sprintf(outDate, "%d-%d-%d", day, month, year);
            res = true;
        }
    }
    return res;
}

bool checkDay(int day)
{
    return (day >= 1 && day <= 31);
}

bool checkYear(int year)
{
    return (year >= 1000 && year <= 3000);
}

bool checkIntMonth(int month)
{
    return (month >= 1 && month <= 12);
}

bool checkStrMonth(char *month, int *monthNum)
{
    bool response = false;
    char months[NUM_OF_MONTHS][MAX_MONTH] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN", "YUL", "AUG", "DEC", "OCT", "NOV", "DEC"};
    for (int i = 0; i < NUM_OF_MONTHS; i++)
    {
        if (strcmp(months[i], month) == 0)
        {
            *monthNum = i + 1;
            response = true;
        }
    }
    return response;
}