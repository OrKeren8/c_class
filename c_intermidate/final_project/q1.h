#include <stdlib.h>
#include <stdio.h>
#include "common.h"

void freeChessPosArray(chessPosArray* moves);
void freeAllMoves(chessPosArray*** allMoves);
int isValidPos(int row, int col);
chessPosArray* getValidKnightMoves(int row, int col);
chessPosArray*** validKnightMoves();