#include <stdlib.h>
#include <stdio.h>
#include "common.h"

void display(chessPosList* lst);
void deleteNodeFromList(chessPosList* lst, chessPosCell* nodeToDelete);
void freeNode(chessPosCell* nodeToDelete);
void disposeDuplicatePositions(chessPosList* lst);
void drawChessBoard(int chessMatrix[][CHESS_SIZE]);