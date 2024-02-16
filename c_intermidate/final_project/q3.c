#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define BOARD_SIZE 8

typedef struct _treeNodeList
{
    struct _treeNodeListCell* head;
    struct _treeNodeListCell* tail;
} treeNodeList;

typedef char chessPos[2];
// not mandatory
typedef struct _chessPosArray
{
    unsigned int size;
    chessPos* positions;
} chessPosArray;
// until here

typedef struct _treeNode
{
    chessPos position;
    treeNodeList next_possible_positions; // מיקומים רשימת
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

// Function to check if a position is valid on the chessboard
int isValidPos(int row, int col)
{
    return (row >= 0 && row < 8 && col >= 0 && col < 8);
}
// Function to generate all valid knight moves for a given position
chessPosArray* getValidKnightMoves(int row, int col)
{
    chessPosArray* moves = (chessPosArray*)malloc(sizeof(chessPosArray));
    moves->size = 0;
    moves->positions = NULL;

    int rowOffsets[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
    int colOffsets[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

    for (int i = 0; i < 8; i++)
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
    chessPosArray*** allMoves = (chessPosArray***)malloc(8 * sizeof(chessPosArray**));

    for (int row = 0; row < 8; row++)
    {
        allMoves[row] = (chessPosArray**)malloc(8 * sizeof(chessPosArray*));
        for (int col = 0; col < 8; col++)
        {
            allMoves[row][col] = getValidKnightMoves(row, col);
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
    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            freeChessPosArray(allMoves[row][col]);
        }
        free(allMoves[row]);
    }
    free(allMoves);
}

void findAllPossibleKnightPathsHelper(treeNode* node, chessPosArray*** allMoves, bool visited[BOARD_SIZE][BOARD_SIZE])
{
    if (node == NULL)
    {
        return;
    }
    int row = node->position[0] - 'A';
    int col = node->position[1] - '1';
    visited[row][col] = true;
    for (int i = 0; i < allMoves[node->position[0] - 'A'][node->position[1] - '1']->size; i++)
    {
        treeNode* newNode = (treeNode*)malloc(sizeof(treeNode));
        int newRow = allMoves[row][col]->positions[i][0] - 'A';
        int newCol = allMoves[row][col]->positions[i][1] - '1';
        if (visited[newRow][newCol])
        {
            continue;
        }
        newNode->next_possible_positions.head = NULL;
        newNode->next_possible_positions.tail = NULL;
        treeNodeListCell* newCell = (treeNodeListCell*)malloc(sizeof(treeNodeListCell));
        newCell->node = newNode;
        newCell->next = NULL;
        if (node->next_possible_positions.head == NULL)
        {
            node->next_possible_positions.head = newCell;
            node->next_possible_positions.tail = newCell;
        }
        else
        {
            node->next_possible_positions.tail->next = newCell;
            node->next_possible_positions.tail = newCell;
        }
        findAllPossibleKnightPathsHelper(newNode, allMoves, visited);
    }
}

// Function build tree for all posible noves for knight withouth repeating using matrix from getValidKnightMoves
pathTree findAllPossibleKnightPaths(chessPos* startingPosition)
{
    pathTree tree;
    tree.root = (treeNode*)malloc(sizeof(treeNode));
    tree.root->position[0] = startingPosition[0];
    tree.root->position[1] = startingPosition[1];
    tree.root->next_possible_positions.head = NULL;
    tree.root->next_possible_positions.tail = NULL;

    chessPosArray*** allMoves = validKnightMoves();
    bool visited[BOARD_SIZE][BOARD_SIZE] = { false };
    findAllPossibleKnightPathsHelper(tree.root, allMoves, visited);
    return tree;
}

// main
int main()
{
    chessPos startingPosition = { 'A', '1' };
    pathTree tree = findAllPossibleKnightPaths(&startingPosition);
    return 0;
}