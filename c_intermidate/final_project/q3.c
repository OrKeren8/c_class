#include "common.h"


void findAllPossibleKnightPathsHelper(treeNode* node, chessPosArray*** allMoves, bool visited[BOARD_SIZE][BOARD_SIZE])
{
    if (node == NULL)
    {
        return;
    }
    int row = node->position[0] - 'A';
    int col = node->position[1] - '1';
    visited[row][col] = true;
    for (int i = 0; i < allMoves[row][col]->size; i++)
    {
        int newRow = allMoves[row][col]->positions[i][0] - 'A';
        int newCol = allMoves[row][col]->positions[i][1] - '1';
        if (visited[newRow][newCol])
            continue;
        treeNode* newNode = (treeNode*)calloc(1, sizeof(treeNode));
        treeNodeListCell* newCell = (treeNodeListCell*)calloc(1, sizeof(treeNodeListCell));
        newCell->node = newNode;
        if (node->next_possible_positions.head == NULL)
            node->next_possible_positions.head = node->next_possible_positions.tail = newCell;             
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

    tree.root = (treeNode*)calloc(1, sizeof(treeNode));
    tree.root->position[0] = (*startingPosition)[0];
    tree.root->position[1] = (*startingPosition)[1];

    chessPosArray*** allMoves = validKnightMoves();
    bool visited[BOARD_SIZE][BOARD_SIZE] = { false };
    findAllPossibleKnightPathsHelper(tree.root, allMoves, visited);
    return tree;
}



