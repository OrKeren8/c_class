#include <stdio.h>


void drawRuler (int k);
void printLineOfSymbols(char symbol, int len);

void main(){
    drawRuler(7);
}

void drawRuler (int k)
{
    if(k==1){
        printLineOfSymbols('-', k);
        return;
    }

    drawRuler(k-1);
    printLineOfSymbols('-', k);
    drawRuler(k-1);
}

void printLineOfSymbols(char symbol, int len)
{
    for (int i=0; i<len; i++){
        printf("%c", symbol);
    }
    printf("\n");
}