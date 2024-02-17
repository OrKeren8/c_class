#include <stdlib.h>
#include <stdio.h>
#include "common.h"
#include "q1.h"
#include "q2.h"
#include "q3.h"


int main()
{
    chessPosArray*** allMoves = validKnightMoves();

    // Example: Print all valid moves for the knight at position (2, 3)
    printf("Valid moves for the knight at position (C,4) AKA (3,4):\n");
    for (int i = 0; i < allMoves[2][3]->size; i++)
    {
        printf("%c%c\n", allMoves[2][3]->positions[i][0], allMoves[2][3]->positions[i][1]);
    }

    // Free allocated memory
    freeAllMoves(allMoves);
    

    ////////for exercise 2/////////
    // here a list of positions with duplicates:
    chessPosCell c6 = { {'E', '1'}, NULL };
    chessPosCell c5 = { {'A', '4'}, &c6 };
    chessPosCell c4 = { {'H', '5'}, &c5 };
    chessPosCell c3 = { {'D', '8'}, &c4 };
    chessPosCell c2 = { {'H', '5'}, &c3 };
    chessPosCell c1 = { {'A', '4'}, &c2 };
    chessPosList cellList = { &c1, &c6 };

    display(&cellList);

    
    chessPos startingPosition;
    startingPosition[0] = 'A';
    startingPosition[1] = '1';
    pathTree tree = findAllPossibleKnightPaths(&startingPosition);

    return 0;
}