#ifndef COMMON_H
#define COMMON_H


#define chessSize 8;

typedef char chessPos[2];

typedef struct _chessPosArray
{
    unsigned int size;
    chessPos* positions;
} chessPosArray;


typedef struct _chessPosCell {
    chessPos position;
    struct _chessPosCell* next;
} chessPosCell;

typedef struct _chessPosList {
    chessPosCell* head;
    chessPosCell* tail;
} chessPosList;


#endif