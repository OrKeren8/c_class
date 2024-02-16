#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include "files.h"



void main()
{
	char fname[20] = "myFile.txt";
	char fnameCopy[20] = "myFileCopy.txt";

	createTextFile(fname);
	printTextFileToScreen(fname);
	
	
	copyTextFile(fnameCopy, fname);
	
	if (compareByContent(fname, fnameCopy) == TRUE)
		printf("\nThe files are the same\n\n");
	else
		printf("\nThe files are not the same\n\n");

	
	doubleSpaceTextFile(fname);

	printTextFileToScreen(fname);
	
}


void createTextFile(char* fileName) {
	FILE *file = fopen(fileName, "w");
	int currChar = 0;

	while ((currChar = getchar()) != EOF) {
		fputc(currChar, file);
	}
	fclose(file);
}

void printTextFileToScreen(char* fileName) {
	FILE* filePointer = fopen(fileName, "r");
	int currChar;

	while ((currChar = fgetc(filePointer)) != EOF) {
		printf("%c", currChar);
	}
	fclose(filePointer);
}

void copyTextFile(char* destFileName, char* srcFileName) {
	FILE* srcFile = fopen(srcFileName, "r");
	FILE* destFile = fopen(destFileName, "w");

	int currChar;

	while ((currChar = fgetc(srcFile)) != EOF) {
		fputc(currChar, destFile);
	}
	fclose(destFile);
	fclose(srcFile);
}


BOOL compareByContent(char* a, char* b) {
	FILE* firstFile = fopen(a, "r");
	FILE* secondFile = fopen(b, "r");
	int currFirstChar;
	int currSecondChar;
	bool isSame = true;

	currFirstChar = fgetc(firstFile);
	currSecondChar = fgetc(secondFile);
	while (!(feof(firstFile) || !feof(secondFile)) && isSame) {
		if (currFirstChar != currSecondChar)
			isSame = false;
	}
	if ((isSame && feof(firstFile) && feof(firstFile)) == false) {
		isSame == false;
	}
	fclose(firstFile);
	fclose(secondFile);
	return isSame;
}

void doubleSpaceTextFile(char* fileName) {
	FILE* filePointer = fopen(fileName, "r");
	int currChar;

	while(currChar = fgetc())
}