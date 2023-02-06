#include <stdio.h>
#include <string.h>


void printOctalToBin(char octalNum[]);

void main(){
    char octalNum[] = "721";
    octalToBin(octalNum);
}


char* octalToBin(char octalNum[]){
    int len = strlen(octalNum);
    char* bin = (char*)malloc
}


void printOctalToBin(char octalNum[]){
    int currentNum;
    for (int i=strlen(octalNum)-1; i>=0; i--){
        currentNum = (int)(octalNum[i] - '0');
        while(currentNum>0){
            printf("%x", currentNum%2);
            currentNum /= 2;
        }
    }
}

