#ifndef COMMON_H
#define COMMON_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


#define BOARD_SIZE 8


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


typedef struct _treeNodeList
{
    struct _treeNodeListCell* head;
    struct _treeNodeListCell* tail;
} treeNodeList;


typedef struct _treeNode
{
    chessPos position;
    treeNodeList next_possible_positions;
} treeNode;


typedef struct _treeNodeListCell
{
    treeNode* node;
    struct _treeNodeListCell* next;
} treeNodeListCell;


typedef struct _pathTree
{
    treeNode* root;
} pathTree;


#endif