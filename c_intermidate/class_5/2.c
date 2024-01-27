#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct dlnode{
	int data;
	struct dlnode * next;
	struct dlnode * prev;
} DLNODE;

typedef struct dlist{
	DLNODE * head;
	DLNODE * tail;
}DLIST;

typedef int BOOL;
#define FALSE 0
#define TRUE 1

LNODE * getMaxIter(LIST * lst);
LNODE * getMaxRec1(LIST * lst);
LNODE * getMaxRec2(LIST * lst);
LNODE * getMaxRec2Helper(LNODE * head);
void printMax(LNODE * max);
BOOL isEmptyList(LIST *lst);
void printDlistBackwards(DLIST * lst);
void deleteNodeFromDlist(DLIST * lst, DLNODE * node);


void main(void)
{
    DLIST lst2;
    DLNODE dn4 = {14,NULL};
    DLNODE dn3 = {13,&dn4};
    DLNODE dn2 = {12,&dn3};
    DLNODE dn1 = {11,&dn2,NULL};
    dn4.prev = &dn3;
    dn3.prev = &dn2;
    dn2.prev = &dn1;

    lst2.head = &dn1;
    lst2.tail = &dn4;

    printf("Before:\n");
    printDlistBackwards(&lst2);

    deleteNodeFromDlist(&lst2, &dl2);

    printf("After:\n");
    printDlistBackwards(&lst2);

}

LNODE * getMaxIter(LIST * lst)
{
	if(isEmptyList(lst) == TRUE)
		return NULL;
	else
	{
		LNODE * max = lst->head;
		LNODE * curr = lst->head->next;

		while(curr != NULL)
		{
			if(curr->data > max->data)
				max = curr;

			curr = curr->next;
		}

		return max;
	}
}
LNODE * getMaxRec1(LIST * lst)
{
	LIST sList;
	LNODE * res;

	if(isEmptyList(lst) == TRUE)
		return NULL;
	else
	{
		sList.head = lst->head->next;
		sList.tail = lst->tail;

		res = getMaxRec1(&sList);
		if(res == NULL)
			return lst->head;
		else
			return lst->head->data > res->data ? lst->head : res;
	}
}
LNODE * getMaxRec2(LIST * lst)
{
	return getMaxRec2Helper(lst->head);
}

LNODE * getMaxRec2Helper(LNODE * head)
{
	LNODE * res;

	if(head == NULL)
		return NULL;
	else
	{
		res = getMaxRec2Helper(head->next);
		if(res == NULL)
			return head;
		else
			return head->data > res->data ? head : res;
	}

}

void printMax(LNODE * max)
{
	if(max == NULL)
		printf("Empty List\n");
	else
		printf("The max is %d\n", max->data);
}

BOOL isEmptyList(LIST *lst)
{
	if(lst->head == NULL)
		return TRUE;
	else
		return FALSE;
}

void printDlistBackwards(DLIST * lst)
{
	DLNODE * curr = lst->tail;

	while(curr != NULL)
	{
		printf("%d ",curr->data);
		curr = curr->prev;
	}
	printf("\n");
}
void deleteNodeFromDlist(DLIST * lst, DLNODE * node)
{
	if(lst->head == lst->tail) // == node)h
		lst->head = lst->tail = NULL;
	else if(lst->head == node) // or node->prev == NULL
	{
		lst->head = lst->head->next;
		lst->head->prev = NULL;
	}
	else if(lst->tail == node) // or node->next == NULL
	{
		lst->tail = lst->tail->prev;
		lst->tail->next = NULL;
	}
	else
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	
	//if the list is dynamic (allocated with malloc) we have to free the node
	//free(node);
}