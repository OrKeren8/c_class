#include "common.h"


int CheckAllocation(const void* ptr) {
    if (ptr == NULL) {
        printf("allocation error");
        exit(1);
    }
}

// Function to check if a position is valid on the chessboard
int isValidPos(int row, int col)
{
    return (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE);
}

// Function to generate all valid knight moves for a given position
chessPosArray* getValidKnightMoves(int row, int col)
{
    chessPosArray* moves = (chessPosArray*)calloc(1, sizeof(chessPosArray));
    moves->size = 0;
    moves->positions = NULL;

    int rowOffsets[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
    int colOffsets[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        int newRow = row + rowOffsets[i];
        int newCol = col + colOffsets[i];

        if (isValidPos(newRow, newCol))
        {
            chessPos newPos = { newRow + 'A', newCol + '1' };

            moves->positions = (chessPos*)realloc(moves->positions, (moves->size + 1) * sizeof(chessPos));
            moves->positions[moves->size][0] = newPos[0];
            moves->positions[moves->size][1] = newPos[1];
            moves->size++;
        }
    }

    return moves;
}


// Function to generate all valid knight moves for all positions on the chessboard
chessPosArray*** validKnightMoves()
{
    chessPosArray*** allMoves = (chessPosArray***)calloc(BOARD_SIZE ,sizeof(chessPosArray**));
    CheckAllocation(allMoves);

    for (int row = 0; row < BOARD_SIZE; row++)
    {
        allMoves[row] = (chessPosArray**)calloc(BOARD_SIZE, sizeof(chessPosArray*));
        CheckAllocation(allMoves[row]);
        for (int col = 0; col < BOARD_SIZE; col++)
        {
            allMoves[row][col] = getValidKnightMoves(row, col);
            CheckAllocation(allMoves[row][col]);
        }
    }
    return allMoves;
}

// Function to free memory allocated for chessPosArray
void freeChessPosArray(chessPosArray* moves)
{
    free(moves->positions);
    free(moves);
}

// Function to free memory allocated for the entire chessPosArray matrix
void freeAllMoves(chessPosArray*** allMoves)
{
    for (int row = 0; row < BOARD_SIZE; row++)
    {
        for (int col = 0; col < BOARD_SIZE; col++)
        {
            freeChessPosArray(allMoves[row][col]);
        }
        free(allMoves[row]);
    }
    free(allMoves);
}
