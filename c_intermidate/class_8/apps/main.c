#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "lab.h"

void main()
{
	char **arr;
	int size;
	int i, sum = 0;

	// sscanf(argv[1], "%d", &size);
    size = 10;

	arr = getInput(size);

	replaceAsterisks(arr, size);

	swapPointersinArr(arr, size, DIG_TYPE);
	swapPointersinArr(arr, size, UPPER_LETTER_TYPE);

	sum = sumDigits(arr, size);

	printf("Sum of all digits in array is: %d\n", sum);

	printf("Characters pointed by array: ");

	for (i = 0; i < size; i++)
		printf("%c", *arr[i]);
	printf("\n");

	doubleChars(arr, size);

	//print array
	for (i = 0; i < size; i++)
		printf("%s\n", arr[i]);

	freeArr(arr, size);
}