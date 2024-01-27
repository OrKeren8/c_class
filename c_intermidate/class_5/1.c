#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct lnode
{
    int data;
    struct lnode *next;
} LNODE;

typedef struct list
{
    LNODE *head;
    LNODE *tail;
} LIST;

typedef int BOOL;
#define FALSE 0
#define TRUE 1

void printList(LIST *lst);
BOOL isEqual(LIST *lst1, LIST *lst2);
LIST copyList(LIST *lst);
LIST listConcat(LIST *l1, LIST *l2);
void makeEmptyList(LIST *lst);
BOOL isEmptyList(LIST *lst);
void insertDataToEndList(LIST *lst, int data);
LNODE *createNewListNode(int data, LNODE *next);
void insertNodeToEndList(LIST *lst, LNODE *tail);
LNODE *getMaxIter(LIST *lst);
void printMax(LNODE *node);
LNODE *getMaxRec1(LIST *lst);

void main(void)
{
    LIST lst1;
    LNODE n4 = {4, NULL};
    LNODE n3 = {13, &n4};
    LNODE n2 = {2, &n3};
    LNODE n1 = {1, &n2};
    LNODE *max;

    lst1.head = &n1;
    lst1.tail = &n4;

    max = getMaxIter(&lst1);
    printMax(max);

    max = getMaxRec1(&lst1);
    printMax(max);

    // max = getMaxRec2(&lst1);
    // printMax(max);
}

LNODE *getMaxRec1(LIST *list)
{
    LIST slist;
    LNODE *maxNode;

    if (isEmptyList(list) == NULL)
        return NULL;
    else
    {        
        slist.head = list->head->next;
        slist.tail = list->tail;

        maxNode = getMaxRec1(&slist);
        if ((maxNode != NULL) && (maxNode->data > list->head->data))
        {
            return maxNode;
        }
        else
        {
            return list->head;
        }
    }
}

void printMax(LNODE *node)
{
    printf("%d\n", node->data);
}

LNODE *getMaxIter(LIST *lst)
{
    LNODE *currNode, *maxNode;
    currNode = maxNode = lst->head;

    while (currNode != NULL)
    {
        if (currNode->data > maxNode->data)
        {
            maxNode = currNode;
        }
        currNode = currNode->next;
    }
    return maxNode;
}

void printList(LIST *lst)
{
    LNODE *curr;

    curr = lst->head;
    while (curr != NULL)
    {
        printf("%d", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

BOOL isEqual(LIST *lst1, LIST *lst2)
{
    LNODE *currNodeLst1, *currNodeLst2;
    BOOL isEqual = TRUE;

    currNodeLst1 = lst1->head;
    currNodeLst2 = lst2->head;

    while (currNodeLst1 && currNodeLst2 && isEqual)
    {
        if (currNodeLst1->data != currNodeLst2->data)
        {
            isEqual = FALSE;
        }
        else
        {
            currNodeLst1 = currNodeLst1->next;
            currNodeLst2 = currNodeLst2->next;
        }
    }
    if ((currNodeLst1 || currNodeLst2) && isEqual)
    {
        isEqual = FALSE;
    }
    return isEqual;
}

LIST copyList(LIST *lst)
{
    LIST res;
    LNODE *curr = lst->head;

    makeEmptyList(&res);
    while (curr != NULL)
    {
        insertDataToEndList(&res, curr->data);
        curr = curr->next;
    }
    return res;
}

LNODE *createNewListNode(int data, LNODE *next)
{
    LNODE *res;
    res = (LNODE *)malloc(sizeof(LNODE));
    res->data = data;
    res->next = next;
    return res;
}

BOOL isEmptyList(LIST *lst)
{
    if (lst->head == NULL)
        return TRUE;
    else
        return FALSE;
}

void insertDataToEndList(LIST *lst, int data)
{
    LNODE *newTail;
    newTail = createNewListNode(data, NULL);
    insertNodeToEndList(lst, newTail);
}
void insertNodeToEndList(LIST *lst, LNODE *tail)
{
    if (isEmptyList(lst) == TRUE)
    {
        lst->head = lst->tail = tail;
    }
    else
    {
        lst->tail->next = tail;
        lst->tail = tail;
    }
    tail->next = NULL;
}

void makeEmptyList(LIST *lst)
{
    lst->head = NULL;
    lst->tail = NULL;
}

LIST listConcat(LIST *l1, LIST *l2)
{
    LIST res;

    if (isEmptyList(l1) == TRUE && isEmptyList(l2 == TRUE))
    {
        makeEmptyList(&res);
    }
    else if (isEmptyList(l1) == TRUE)
    {
        res = *l2;
    }
    else if (isEmptyList(l2) == TRUE)
    {
        res = *l1;
    }
    else
    {
        l1->tail->next = l2->head;
        res.head = l1->head;
        res.tail = l2->tail;
    }

    return res;
}