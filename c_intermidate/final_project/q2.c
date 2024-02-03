#include <stdlib.h>
#include <stdio.h>
#include "common.h"
#include "q2.h"


void display(chessPosList* lst)
{
    /*display list of pone positions
    
    Args:
        chessPosList* lst: list of pone movements;
    Return: NULL
    */
    chessPosCell* curr = lst->head;
    int chessBoard[CHESS_SIZE][CHESS_SIZE] = {0}, counter=1;
    
    disposeDuplicatePositions(lst);
    while (curr != NULL) {
        chessBoard[curr->position[0] - 'A'][curr->position[1] - '1'] = counter;
        counter++;
        curr = curr->next;
    }
    drawChessBoard(chessBoard);
}

void disposeDuplicatePositions(chessPosList* lst)
{
    /*dispose every duplicate cell position, only the fisrt one left
    in the list

    Args:
        chessPosList *lst: list of chess board positions
    Return: NULL
    */
    int chessBord[CHESS_SIZE][CHESS_SIZE] = { 0 };
    int row, col;
    chessPosCell *currCell = lst->head, *nextCell;

    printf("Chess Bord: \n");
    while (currCell != NULL)
    {
        nextCell = currCell->next;
        row = currCell->position[0] - 'A';
        col = currCell->position[1] - '1';
        if (chessBord[row][col] == 0)
            chessBord[row][col] = 1;
        else
            deleteNodeFromList(lst, currCell);
       currCell = nextCell;
    }
}

void deleteNodeFromList(chessPosList* lst, chessPosCell* nodeToDelete)
{
    /*delete a node from a list

    Args:
        chessPosList *lst: the list to delete the node from
        chessPosCell *nodeToDelete: pointer to the node to delete
    return: none
    */
    chessPosCell* curr = lst->head;

    // if the list has only one node
    if (lst->head == lst->tail)
        lst->head = lst->tail = NULL;
    // if the node is the first one
    else if (lst->head == nodeToDelete)
        lst->head = nodeToDelete->next;
    else
    {
        while (curr->next != nodeToDelete)
            curr = curr->next;
        // if the node is in the end of the list
        if (lst->tail == nodeToDelete)
            curr->next = lst->tail = NULL;
        // if the node is the middle of the list
        else
            curr->next = nodeToDelete->next;
    }
    freeNode(nodeToDelete);
}

void freeNode(chessPosCell* nodeToDelete)
{
    /*free a dynamic memory node

    Args:
        ListNode *nodeToDelete: the node to free up
    Return: NULL
    */

    //for now there is only static list in main so do nothing
}

void drawChessBoard(int chessMatrix[][CHESS_SIZE]) {
    /*draw a chess board with data of chess positions in it

    Args:
        int chessMatrix[CHESS_SIZE][]: matrix with all of the positions of a specific pone move
    Return: NULL
    */
    for (int i = 0; i < CHESS_SIZE; i++) {
        for (int j = 0; j < CHESS_SIZE; j++)
            printf("#####");
        printf("#\n#");
        for (int j = 0; j < CHESS_SIZE; j++) {
            if (chessMatrix[i][j] != 0)
                printf(" %2d #", chessMatrix[i][j]);
            else
                printf("    #");
        }
        printf("\n");
    }
    for (int j = 0; j < CHESS_SIZE; j++)
        printf("#####");
    printf("#\n");
}