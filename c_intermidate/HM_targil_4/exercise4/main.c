#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


#define SIZE 100


typedef struct treeNode {
	int data;
	struct treeNode* left;
	struct treeNode* right;
} TreeNode;

typedef struct tree {
	TreeNode* root;
} Tree;

typedef struct listNode {
    TreeNode* tn;
    struct listNode next;
}ListNode;

typedef struct list
{
    ListNode* head;
    ListNode* tail;
}List;

void printByLevels(Tree tr);
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
    tr = BuildTreeFromArray(arr, size);//the function from question 1
    printByLevels(tr);
    freeTree(tr);
}


ListNode* createNewListNode(int* data, ListNode* next)
{
    //create new list node
    ListNode* res;
    res = (ListNode*)calloc(1, sizeof(ListNode));
    if (res == NULL) {
        printf("allocation error");
        exit(1);
    }
    return res;
}

bool isEmptyList(List* list)
{
    if (list->head == NULL)
        return true;
    else
        return false;
}

void insertNodeToEndList(List* list, ListNode* tail)
{
    if (isEmptyList(list) == true) {
        list->head = list->tail = tail;
    }
    else {
        list->tail->next = tail;
        list->tail = tail;
    }
    tail->next = NULL;
}


void insertDataToEndList(List* list, int num)
{
    //insert a node to the end of a list
    ListNode* newTail;
    newTail = createNewListNode(num, NULL);
    insertNodeToEndList(list, newTail);
}

void deleteNodeFromList(List* lst, ListNode* nodeToDelete) {
    //delete a node from a list
    ListNode* curr = lst->head;

    //if the list has only one node
    if (lst->head == lst->tail) {
        lst->head = lst->tail = NULL;
    }
    //if the node is the first one
    else if (lst->head == nodeToDelete) {
        lst->head = nodeToDelete->next;
    }
    else {
        while (curr->next != nodeToDelete) {
            curr = curr->next;
        }
        //if the node is in the end of the list
        if (lst->tail == nodeToDelete)
            curr->next = lst->tail = NULL;
        //if the node is the middle of the list
        else
            curr->next = nodeToDelete->next;
    }
    freeNode(nodeToDelete);
}


void printByLevelsHelper(List lst) {
    TreeNode* curr = lst.head->tn;

    if(lst.head == NULL)
        return;
    else {
        if (curr->left != NULL) {
            insertDataToEndList(&lst, curr->left);
        }
        if(curr->right != NULL){
            insertDataToEndList(&lst, curr->right);
        }
        printf("%d", curr->data);
        deleteNodeFromList(&lst, lst.head);
        printByLevelsHelper(lst);
        return;
    }
}
void printByLevels(TreeNode *tr) {
    //List lst;
    //lst.head = lst.tail = NULL;

    printByLevelsHelper(TreeNode * tr);

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