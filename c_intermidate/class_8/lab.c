#include "lab.h"

char ** getInput(int size)
{
	char **arr;
	int i;

	arr = (char **)malloc(size * sizeof(char*));

	printf("Please enter %d characters: ", size);
	for (i = 0; i < size; i++)
	{
		arr[i] = (char *)malloc(sizeof(char));
		scanf("%c", arr[i]);
	}
	return arr;
}

// replace asterisk characters with space characters
void replaceAsterisks(char **arr, int size)
{
	int i;
	for (i = 0; i < size; i++)
		if (*arr[i] == '*')
			*arr[i] = ' ';
}

void swapPointersinArr(char **arr, int size, int type)
{
	bool found;
	int i;
	int dig1Index = NOT_FOUND, dig2Index;

	// swap the pointers to first 2 digits/uppercase in array
	found = false;
	for (i = 0; i < size && !found; i++)
	{
		switch (type)
		{
		case DIG_TYPE:
			if (ISDIGIT(*arr[i]))
				if (dig1Index != NOT_FOUND)
				{
					dig2Index = i;
					found = true;
				}
				else
					dig1Index = i;
			break;
		case UPPER_LETTER_TYPE:
			if (ISUPPER(*arr[i]))
				if (dig1Index != NOT_FOUND)
				{
					dig2Index = i;
					found = true;
				}
				else
					dig1Index = i;
			break;
		}
	}

	// if 2 occurrences were found swap the pointers in array
	if (found)
		SWAP(char*, arr[dig1Index], arr[dig2Index])
}

int sumDigits(char **arr, int size)
{
	int i, sum = 0;
	for (i = 0; i < size; i++)
		if (ISDIGIT(*arr[i]))
			sum += (*arr[i] - '0');
	
	return sum;
}

void doubleChars(char **arr, int size)
{
	int i;

	//change characters to strings
	for (i = 0; i < size; i++)
	{
		arr[i] = (char *)realloc(arr[i], 3 * sizeof(char));
		arr[i][1] = arr[i][0];
		arr[i][2] = '\0';
	}
}


void freeArr(char **arr, int size)
{
	int i;

	for (i = 0; i < size; i++)
		free(arr[i]);

	free(arr);
}