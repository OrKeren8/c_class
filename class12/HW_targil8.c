//Or Keren
//315155531

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // in order to use the "rand" and "srand" functions
#include <time.h>	// in order to use "time" function


void introductionPrint();
int getNumOfPlayers();

void main()
{
    int numOfPlayers;

    introductionPrint();
    numOfPlayers = getNumOfPlayers();
}

void introductionPrint(){
    /*prints introduction sentence for Taki game
    
    Args: none
    return: none
    */
    char introductionStr[] = "************ Welcome to TAKI game !!! ************";
    
    printf("%s\n", introductionStr);
    printf("\n");
}

int getNumOfPlayers(){
    /*get from the user the numbers of players in the taki game
    
    Args: none
    return: int numOfPlayers: number of players
    */
    int numOfPlayers;

    printf("Please enter the number of players:\n");
    scanf("%d", &numOfPlayers);
    return numOfPlayers;
}