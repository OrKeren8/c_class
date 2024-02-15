#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef int BOOL;
#define FALSE 0
#define TRUE 1
#define SIZE 100

typedef struct treeNode
{
    unsigned int data;
    struct treeNode* left;
    struct treeNode* right;
}TreeNode;

typedef struct tree
{
    TreeNode* root;
}Tree;


Tree BuildTreeFromArray(int* arr, int  size);
TreeNode* CreateTNode();
BOOL check_operand(char ch);


void main()
{
    char str[SIZE];
    Tree tr;
    double res;
    BOOL expressionOK;

    printf("Please enter the expression: ");
    gets(str);
    expressionOK = buildExpressionTree(str, &tr);

    // if(expressionOK == TRUE)
    // {
    //     res = calcExpression(tr);
    //     printf("%s = %.2f", str, res);
    // }
    // else{
    //     printf("The input expression is not valid\n");
    //     freeTree(tr);
    // }
}

BOOL buildExpressionTreeHelper(char* str, int len, TreeNode* root) {
    /*builds a tree with mathematic expression in it
    this is a recursive function that breaks down the expression operand by operand

    Args:
        str: a string of the expression
        len: the length of the expression
        root: a pointer to a tree node, the answer answer will be returned there
    return: a boolean represent wether the expression is valid or not
    */
    BOOL res1=FALSE, res2=FALSE;
    if (len == 0)
        return TRUE;
    else if (len==1) {
        root->data = str[0] - '0';
        return TRUE;
    }
    else {
        root->right = CreateTNode();
        root->left = CreateTNode();
        res1 = buildExpressionTreeHelper(&str[1], (len / 2)-1, root->left);
        res2 = buildExpressionTreeHelper(&str[(len / 2) + 1], (len / 2) - 1, root->right);
        if (!res1 || !res2)
            return FALSE;
        else {
            if (check_operand(str[1])) {
                root->data = str[1];
                return TRUE;
            }
            else
                return FALSE;
        }
    }
}
BOOL buildExpressionTree(char* str, Tree* tr) {
    /*builds a tree with mathematic expression in it

    Args:
        str: a string of the expression
        tr: a pointer to a tree, the expression tree will be returned there
    return: a boolean represent wether the expression is valid or not
    */
    BOOL isValidExpression = TRUE;
    tr->root = CreateTNode();
    isValidExpression = buildExpressionTreeHelper(str, (int)strlen(str), tr->root);
    return isValidExpression;
}

TreeNode* CreateTNode() {
    /*create new tree node

    return: a pointer to dynamic tree node
    */
    TreeNode* temp = (TreeNode*)calloc(1, sizeof(TreeNode));
    if (temp == NULL) {
        printf("memory allocation error");
        exit(1);
    }
}

BOOL check_operand(char ch) {
    /*check if a char is a representation of mathematic operand
    */
    char valid_operands[] = { '+', '*', '-', '/' };
    BOOL is_valid = FALSE;

    for (int i = 0; i < 4 & !is_valid; i++) {
        if (ch == valid_operands[i]) {
            is_valid == TRUE;
        }
    }
    return is_valid;
}