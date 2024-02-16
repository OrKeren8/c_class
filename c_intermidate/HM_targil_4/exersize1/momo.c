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


Tree BuildTreeFromArray(int* arr, int size);
TreeNode* CreateTNode();
BOOL checkOperand(char ch);
BOOL CheckDigit(char ch);
BOOL CheckExpression(char *expression);


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
BOOL buildExpressionTreeHelper(char *str, TreeNode *currNode, int *leftExpressionLen){
    BOOL isValid = TRUE;
    int leftExpressionLen = 0;
    if(str[1] == '('){
        if(currNode->left == NULL){
            currNode->left = CreateTNode();
            isValid = buildExpressionTreeHelper(str+1, currNode->left, &leftExpressionLen);
        }
        else{
            currNode->right = CreateTNode();
            isValid = buildExpressionTreeHelper(str+1, currNode->right, &leftExpressionLen);
        }
    }
    else if(CheckDigit(str[1])){
        currNode->data = str[1];
    }
    else if(CheckExpression(str[1])){
        if(currNode->left == NULL){
            currNode->left = CreateTNode();
            currNode->left->data = str[1];
        }
        else{
            currNode->right = CreateTNode();
            isValid = buildExpressionTreeHelper(str+1, currNode->right, &leftExpressionLen);
            currNode->right->data = str[1];
        }
    }
}
BOOL buildExpressionTree(char* str, Tree* tr) {
    BOOL isValidExpression = TRUE;
    int stringLen = strlen(str);

    isValidExpression = CheckExpression(str);
    tr->root = CreateTNode();
    isValidExpression = isValidExpression && buildExpressionTreeHelper(str, tr->root, stringLen, tr->root ,tr->root);
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
    return temp;
}

BOOL CheckOperand(char ch) {
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


/**
 * @brief Checks if a character is a digit.
 *
 * This function takes a character as input and returns a boolean value indicating
 * whether the character is a digit or not.
 *
 * @param ch The character to be checked.
 * @return Returns TRUE if the character is a digit (0-9), otherwise returns FALSE.
 */
BOOL CheckDigit(char ch){
    BOOL isDigit = FALSE;

    if(ch<'9' && ch>'0')
        isDigit = TRUE;
    return isDigit;
}


/**
 * @brief Checks if parentheses in an expression are balanced.
 *
 * This function checks if the parentheses in the given expression are balanced.
 * An expression is considered valid if it has matching opening and closing parentheses.
 *
 * @param expression Pointer to the string containing the expression to be checked.
 *                   The expression should be a null-terminated string.
 * @return Returns true if the parentheses are balanced, otherwise returns false.
 */
BOOL CheckExpression(char *expression){
    BOOL isValid = TRUE;
    int parenthesisCount = 0, expLen = strlen(expression);

    for (int i=0; i<expLen && isValid; i++){
        if(expression[i] == '(')
            parenthesisCount ++;
        else if(expression[i] == ')'){
            parenthesisCount --;
            if(parenthesisCount < 0)
                isValid = FALSE;
        }
    }
    return isValid;
}