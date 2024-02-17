#ifndef Q1_H
#define Q1_H


#include "common.h"


void freeChessPosArray(chessPosArray* moves);
void freeAllMoves(chessPosArray*** allMoves);
int isValidPos(int row, int col);
chessPosArray* getValidKnightMoves(int row, int col);
chessPosArray*** validKnightMoves();


#endif