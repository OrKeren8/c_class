//Or Keren
//315155531

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // in order to use the "rand" and "srand" functions
#include <time.h>	// in order to use "time" function
#include <stdbool.h>
#include <string.h>


#define ALLOCATION_ERROR "[ERROR] : Memory allocation failed!"
#define NUM_OF_CARDS 4
#define PLAYER_NAME_LEN 21

//cards text:
#define CARDS_LEN 14
#define COLORS_LEN 4

#define CARD_PRINT_SYMBOL '*'
#define CARD_PRINT_LEN 9
#define CARD_PRINT_HIGHT 6   

typedef struct playerInfo{
    char name[PLAYER_NAME_LEN];
}PLAYER_INFO;

typedef struct card{
    int index;
    int color;
}CARD;

typedef struct player{
    PLAYER_INFO playerInfo;
    CARD *cardsArr;
    int numOfCards;
}PLAYER;

void introductionPrint();
int getNumOfPlayers();
CARD* createCardsArr(int numOfCards);
PLAYER* createPlayersArr(int numOfPlayers);
void freePlayersArr(PLAYER* playersArr, int numOfPlayers);
void getPlayersNames(PLAYER* playersArr, int numOfPlayers);
void initializeCardsArr(PLAYER* playersArr, int numOfPlayers, int numOfCards);
void getRandomCard(CARD* card);
void game(PLAYER* playersArr, int numOfPlayers);
void getRandomCard(CARD* card);
void printLineOfSymbols(char symbol, int len);
int getRandomCardIndex();
int getRandomColor();
void showCurrentPlayerHand(PLAYER* player);

const char cardsSymbols[][10] = {"1","2", "3", "4", "5", "6", "7", "8", "9", "+", "STOP", "<->", "TAKI", "COLOR"};
const char cardsColors[] = {'R', 'G', 'B', 'Y'};

void main()
{
    int numOfPlayers;

	srand(time(NULL));
    introductionPrint();
    numOfPlayers = getNumOfPlayers();
    PLAYER* playersArr = createPlayersArr(numOfPlayers);
    getPlayersNames(playersArr, numOfPlayers);
    initializeCardsArr(playersArr, numOfPlayers, NUM_OF_CARDS);
    game(playersArr, numOfPlayers);

    freePlayersArr(playersArr, numOfPlayers);
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

PLAYER* createPlayersArr(int numOfPlayers){
    
    PLAYER *playersArr = (PLAYER *) malloc(numOfPlayers * sizeof(PLAYER));
    
    if(playersArr == NULL){
        printf("%s\n", ALLOCATION_ERROR);
        exit(1);
    }
    for (int i=0; i<numOfPlayers; i++){
        playersArr[i].cardsArr = createCardsArr(NUM_OF_CARDS); 
        playersArr[i].numOfCards = NUM_OF_CARDS;
    }
    return playersArr;
}

CARD* createCardsArr(int numOfCards){
    /*this function creates an arr of cards
    
    Args:
        int numOfCards: num of cards in the arr
    return: CARD *cardsArr: pointer to card struct arr 
    */
    CARD *cardsArr = (CARD *) malloc(numOfCards * sizeof(CARD));

    if(cardsArr == NULL){
        printf("%s\n", ALLOCATION_ERROR);
        exit(1);
    }
    return cardsArr;
}

void freePlayersArr(PLAYER* playersArr, int numOfPlayers){
    /*this function free the memory allocated in the heap for players array
    
    Args:
        PLAYER* playersArr: pointer to players arr
        int numOfPlayers: num of player structs in playersArr
    return: none
    */
    for (int i=0; i<numOfPlayers; i++){
        free(playersArr[i].cardsArr);
    }
    free(playersArr);
}

void getPlayersNames(PLAYER* playersArr, int numOfPlayers){
    /*this function gets the  names of each player in the taki game
    and place it in playersArr

    Args:
        PLAYER* playersArr: array of PLAYER structs
        int numOfPlayers: number of players in the array
    return: None
    */
    for (int i=0; i<numOfPlayers; i++){
        printf("Please enter the first name of player #%d: \n", i);
        scanf("%s", &playersArr[i].playerInfo.name);
    }
}

void getRandomCard(CARD* card){
    //get random card structure
    card->index = getRandomCardIndex();
    card->color = getRandomColor();
}

int getRandomCardIndex(){
    //get random card index - 1 to 10 or spacial card
    return rand() % CARDS_LEN;
}

int getRandomColor(){
    //get random color index
    return rand() % COLORS_LEN;
}

void initializeCardsArr(PLAYER* playersArr, int numOfPlayers, int numOfCards){
    /*initialize cards array with random cards for each player
    */
    for (int i=0; i<numOfPlayers; i++){
        for(int m=0; m<numOfCards; m++){
            getRandomCard(&playersArr[i].cardsArr[m]);
        }
    }
}

void printLineOfSymbols(char symbol, int len){
    //prints line of symbol with a given len
    for(int i=0; i<len; i++){
        printf("%c", symbol);
    }
}

void printCard(CARD* card){
    //print a card layout
    printLineOfSymbols(CARD_PRINT_SYMBOL, CARD_PRINT_LEN);
    printf("\n");
    for (int i=0; i<CARD_PRINT_HIGHT-2; i++){
        printf("%c", CARD_PRINT_SYMBOL);
        if(i==(((CARD_PRINT_HIGHT-2)/2)-1)){
            printLineOfSymbols(' ', (CARD_PRINT_LEN-2-strlen(cardsSymbols[card->index]))/2); 
            printf("%s", cardsSymbols[card->index]);
            printLineOfSymbols(' ', ((CARD_PRINT_LEN-2-strlen(cardsSymbols[card->index]))/2));
        }
        else if(i==((CARD_PRINT_HIGHT-2)/2)){
            printLineOfSymbols(' ', ((CARD_PRINT_LEN-2-1)/2));
            printf("%c", cardsColors[card->color]);
            printLineOfSymbols(' ', ((CARD_PRINT_LEN-2-1)/2));
        } 
        else{
            printLineOfSymbols(' ', (CARD_PRINT_LEN-2));
        }
        printf("%c", CARD_PRINT_SYMBOL);
        printf("\n");
    }
    printLineOfSymbols(CARD_PRINT_SYMBOL, CARD_PRINT_LEN);
    printf("\n");
}

void showCurrentPlayerHand(PLAYER* player){
    //print the player name and the cards he has
    printf("%s's turn:\n\n", player->playerInfo.name);
    for (int i=0; i<player->numOfCards; i++){
        printf("Card #%d\n", (i+1));
        printCard(&player->cardsArr[i]);
    }
    printf("\n");
}

void playSingleTurn(PLAYER* player){
    int userChoice;
    
    showCurrentPlayerHand(player);
    printf("Please enter 0 if you want to take a card from the deck\n or 1-%d if you want to put one of your cards in the middle:\n", player->numOfCards);
    scanf("%d", &userChoice);
    while(userChoice>player->numOfCards){
        printf("Invalid input!\n");
        printf("Please enter 0 if you want to take a card from the deck\n or 1-%d if you want to put one of your cards in the middle:\n", player->numOfCards);
        scanf("%d", &userChoice);
    }
    // switch(player->cardsArr[userChoice-1])

}

void game(PLAYER* playersArr, int numOfPlayers){
    /*game workthrough, handle every aspect in the game
    */
    CARD topCard;
    bool keepPlaying=true;
    int currentTurn = 0;

    //first card contain only numbers
    topCard.index = rand() % 10;
    topCard.color = getRandomColor();

    //start the game
    printCard(&topCard);

    while(keepPlaying){
        playSingleTurn(&playersArr[currentTurn%numOfPlayers]);
        keepPlaying = false;
    }
}

