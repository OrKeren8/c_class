#ifndef LAB_H
#define LAB_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ch.h"
#include "swap.h"

#define NOT_FOUND -1
#define DIG_TYPE	0
#define UPPER_LETTER_TYPE 1

char ** getInput(int size);
void replaceAsterisks(char **arr, int size);
int sumDigits(char **arr, int size);
void doubleChars(char **arr, int size);
void swapPointersinArr(char **arr, int size, int type);
void freeArr(char **arr, int size);


#endif