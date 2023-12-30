//Or Keren
//315155531

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // in order to use the "rand" and "srand" functions
#include <time.h>	// in order to use "time" function

void main()
{
	// In order to generate random numbers, we use the srand function only once,
	// and then use the rand function for each random number we want to generate.

	int num;

	srand(time(NULL));
	// rand() function call returns a random positive integer
	// in the range from 0 to 32,767.

	// For example, if we want a random number between 0 to 9:
	num = rand() % 10;
	printf("First number: %d\n", num);
    num = rand() % 10;
	printf("First number: %d\n", num);
	
	// If we want a random number between 0 to 20:
	num = rand() % 21;
	printf("Second number: %d\n", num);

	// If we want a random number between 15 to 20:
	// rand() % 6 returns a random number between 0 to 5,
	// then we add 15 to get a number between 15 to 20.
	num = 15 + rand() % 6;
	printf("Third number: %d\n", num);
}