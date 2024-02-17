#ifndef Q2_H
#define Q2_H


#include "common.h"


void display(chessPosList* lst);
void deleteNodeFromList(chessPosList* lst, chessPosCell* nodeToDelete);
void freeNode(chessPosCell* nodeToDelete);
void disposeDuplicatePositions(chessPosList* lst);
void drawChessBoard(int chessMatrix[][BOARD_SIZE]);


#endif