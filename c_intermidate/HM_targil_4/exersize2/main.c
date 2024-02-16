#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


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
void freeTree(Tree tr);
void printTreeInorder(Tree tr);


void main()
{
    int size, i;
    int arr[SIZE];
    Tree tr;

    printf("Please enter the number of items: ");
    scanf("%d", &size);
    for (i = 0; i < size; i++)
        scanf("%d", &arr[i]);
    tr = BuildTreeFromArray(arr, size);
    printf("The tree in inorder (LDR) format:\n");
    printTreeInorder(tr); //Print the tree in-order (LDR)
    freeTree(tr);
}


TreeNode* BuildTreeFromArrayHelper(int* arr, int  size) {
    /*helper for build tree function
    this is a recursive function which creates a tree from
    a list of variables

    Args:
        arr: array of values to build the tree from
        size: the length of the array
    return: a pointer to the top level tree node that created from arr
    */
    TreeNode* curr;

    if (size <= 0 || arr[size / 2] == -1) {
        return NULL;
    }
    else {
        curr = (TreeNode*)calloc(1, sizeof(TreeNode));
        if (curr == NULL) {
            printf("allocation error");
            exit(0);
        }
        curr->left = BuildTreeFromArrayHelper(arr, size / 2);
        curr->right = BuildTreeFromArrayHelper(&arr[(size / 2) + 1], size / 2);
        curr->data = arr[size / 2];
        return curr;
    }
}
Tree BuildTreeFromArray(int* arr, int  size) {
    /*build a tree from an array of values

    Args:
        arr: array of values to build the tree from
        size: the length of the array
    return: a tree
    */
    Tree res;

    res.root = BuildTreeFromArrayHelper(arr, size);
    return res;
}


void freeTreeHelper(TreeNode* root) {
    /*free a full tree

    a recursive function that free a tree
    Args:
        root: a tree root
    Return: null
    */
    if (root == NULL)
        return;
    else {
        freeTreeHelper(root->right);
        freeTreeHelper(root->left);
        free(root);
    }
}
void freeTree(Tree tr) {
    /*free a tree from memory

    Args:
        tr: a tree to free
    Return: null
    */
    freeTreeHelper(tr.root);
}

void printTreeInorderHelper(TreeNode* root) {
    if (root == NULL)
        return;
    else {
        printTreeInorderHelper(root->left);
        printf("%d ", root->data);
        printTreeInorderHelper(root->right);
    }
}
void printTreeInorder(Tree tr) {
    printTreeInorderHelper(tr.root);
}