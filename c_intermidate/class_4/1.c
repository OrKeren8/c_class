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

void main(void)
{
    LIST lst1, lst2, lst3, lst4;
    LNODE n4 = {4, NULL};
    LNODE n3 = {3, &n4};
    LNODE n2 = {2, &n3};
    LNODE n1 = {1, &n2};

    LNODE n24 = {4, NULL};
    LNODE n23 = {3, &n24};
    LNODE n22 = {2, &n23};
    LNODE n21 = {1, &n22};
    BOOL res;

    lst1.head = &n1;
    lst1.tail = &n4;

    lst2.head = &n21;
    lst2.tail = &n24;

    printList(&lst1);

    res = isEqual(&lst1, &lst2);
    if (res == TRUE)
        printf("Equal\n");
    else
        printf("Not Equal\n");

    lst3 = copyList(&lst1);

    printList(&lst3);

    // res = isEqual(&lst1, &lst3);
    // if(res == TRUE)
    // 	printf("Equal\n");
    // else
    // 	printf("Not Equal\n");

    // lst4 = listConcat(&lst1, &lst3);
    // printList(&lst4);

    // we have to free lst3!!
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

LIST copyList(LIST *lst){
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

LNODE* createNewListNode(int data, LNODE * next)
{
	LNODE * res;
	res = (LNODE*) malloc (sizeof(LNODE));
	res->data = data;
	res->next = next;
	return res;
}

BOOL isEmptyList(LIST *lst)
{
	if(lst->head == NULL)
		return TRUE;
	else
		return FALSE;
}

void insertDataToEndList(LIST *lst, int data)
{
	LNODE * newTail;
	newTail = createNewListNode(data, NULL);
	insertNodeToEndList(lst, newTail);
}
void insertNodeToEndList(LIST *lst, LNODE * tail)
{
	if (isEmptyList(lst) == TRUE){
		lst->head = lst->tail = tail;
	}
	else{
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

LIST listConcat(LIST *l1, LIST *l2){
    LIST res;

    if(isEmptyList(l1) == TRUE && isEmptyList(l2 == TRUE)){
        makeEmptyList(&res);
    }
    else if(isEmptyList(l1) == TRUE){
        res = *l2;
    }
    else if(isEmptyList(l2) == TRUE){
        res = *l1;
    }
    else{
        l1->tail->next = l2->head;
        res.head = l1->head;
        res.tail = l2->tail;
    }

    return res;
}