#include "common.h"
#include "q1.h"


treeNodeListCell* createListCell() {
    //Creates a new tree node list cell.

    treeNodeListCell* res = (treeNodeListCell*)calloc(1, sizeof(treeNodeListCell));
    res->node = (treeNode*)calloc(1, sizeof(treeNode));
    return res;
}


void appendCellToList(treeNodeList* lst, treeNodeListCell* tempCell){
    //Appends a tree node list cell to the end of a tree node list.

    if (lst->head == NULL)
    {
        lst->head = tempCell;
        lst->tail = tempCell;
    }
    else
    {
        lst->tail->next = tempCell;
        lst->tail = tempCell;
    }
}


void findAllPossibleKnightPathsHelper(treeNode* node, chessPosArray*** allMoves, bool visited[BOARD_SIZE][BOARD_SIZE], chessPos* startingPosition)
{
    //Recursively finds all possible paths for a knight on a chessboard starting from a given position.
   
    treeNodeListCell* tempCell;
    if (node == NULL)
        return;

    node->position[0] = (*startingPosition)[0];
    node->position[1] = (*startingPosition)[1];
    int row = node->position[0] - 'A';
    int col = node->position[1] - '1';
    visited[row][col] = true;

    for (int i = 0; i < allMoves[node->position[0] - 'A'][node->position[1] - '1']->size; i++)
    {
        int newRow = allMoves[row][col]->positions[i][0] - 'A';
        int newCol = allMoves[row][col]->positions[i][1] - '1';
        if (visited[newRow][newCol])
            continue;
        tempCell = createListCell();
        appendCellToList(&(node->next_possible_positions), tempCell);
        findAllPossibleKnightPathsHelper(tempCell->node, allMoves, visited, allMoves[row][col]->positions[i]);
    }
    visited[row][col] = false;
}


// Function build tree for all posible noves for knight withouth repeating using matrix from getValidKnightMoves
pathTree findAllPossibleKnightPaths(chessPos* startingPosition)
{
    pathTree tree;
    tree.root = (treeNode*)calloc(1, sizeof(treeNode));

    chessPosArray*** allMoves = validKnightMoves();
    bool visited[BOARD_SIZE][BOARD_SIZE] = { false };
    findAllPossibleKnightPathsHelper(tree.root, allMoves, visited, startingPosition);
    return tree;
}
