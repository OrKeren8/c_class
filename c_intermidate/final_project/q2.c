#include <stdlib.h>
#include <stdio.h>
#include "common.h"
#include "q2.h"

void display(chessPosList* lst)
{
    disposeDuplicatePositions(lst);
}

void disposeDuplicatePositions(chessPosList* lst)
{
    /*dispose every duplicate cell position, only the fisrt one left
    in the list

    Args:
        chessPosList *lst: list of chess board positions
    Return: NULL
    */
    int chessBord[8][8] = { 0 };
    int row, col;
    chessPosCell *currCell = lst->head, *nextCell;

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
    //free(nodeToDelete);
}
