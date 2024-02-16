#ifndef __FILES_H
#define __FILES_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef int BOOL;
#define FALSE 0
#define TRUE 1

void createTextFile(char* fileName);
void printTextFileToScreen(char* fileName);
long int fileSize(FILE* fp);
void copyTextFile(char* destFileName, char* srcFileName);
BOOL compareByContent(char* a, char* b);
void doubleSpaceTextFile(char* fileName);


#endif
