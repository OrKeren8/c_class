#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the binary tree
typedef struct Node {
    char data; // Data of the node (operator or operand)
    struct Node* left; // Pointer to the left child
    struct Node* right; // Pointer to the right child
} Node;

// Function to create a new node
Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to build a tree from a mathematical expression
Node* buildTree(char expression[], int* index) {
    if (expression[*index] == '\0') {
        return NULL;
    }

    // Create a new node with the current character
    Node* newNode = createNode(expression[*index]);
    (*index)++;

    // If the current character is an operator, recursively build left and right subtrees
    if (expression[*index] == '(') {
        (*index)++;
        newNode->left = buildTree(expression, index);

        (*index)++; // Skip operator
        newNode->right = buildTree(expression, index);

        (*index)++; // Skip closing parenthesis
    }

    return newNode;
}

// Function to print the tree (inorder traversal)
void printTree(Node* root) {
    if (root != NULL) {
        printTree(root->left);
        printf("%c ", root->data);
        printTree(root->right);
    }
}

int main() {
    char expression[] = "(((3+7)*9)/((3+7)*9))";

    int index = 0;
    Node* root = buildTree(expression, &index);

    printf("Expression as a tree (inorder traversal): ");
    printTree(root);
    printf("\n");

    return 0;
}