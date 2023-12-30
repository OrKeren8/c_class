#include <stdio.h>

#define SECS_IN_HOUR 3600
#define SECS_IN_MIN 60

void main()
{
    int hours, minutes, seconds;
    printf("Please enter time in seconds: ");
    scanf("%d", &seconds);
    hours = seconds / SECS_IN_HOUR;
    seconds %= SECS_IN_HOUR;
    minutes = seconds / SECS_IN_MIN;
    seconds %= SECS_IN_MIN;
    printf("The time is: %02d:%02d:%02d", hours, minutes, seconds);
}