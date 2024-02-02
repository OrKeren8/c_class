#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct ListNode{
	int* dataPtr;
	struct ListNode* next;
}ListNode;

typedef struct List
{
	ListNode* head;
	ListNode* tail;
}List;


List merge(List lst1, List lst2);
List getList();
void insertNodeToEndList(List *list, ListNode * tail);
void makeEmptyList(List *list);
void insertDataToEndList(List *list, int num);
ListNode* createNewListNode(int data, ListNode *next);
bool isEmptyList(List *list);
void printList(List *list);
void checkAllocation(int memory);


void main()
{
    List lst1, lst2, mergedList;

    lst1 = getList();
    lst2 = getList();
    mergedList = merge(lst1,lst2);
    printf("Merged list:\n");
    printList(&mergedList);
    freeList(&lst1);
    freeList(&lst2);
    freeList(&mergedList);
}

void freeList(List *list){
    /*free an entire list

    Args: 
        List *list: the list to free
    Return: NULL
    */
    while(list->head != NULL){
        deleteNodeFromList(list, list->head);
    } 
}

void deleteNodeFromList(List *lst, ListNode *nodeToDelete){
    /*delete a node from a list
    
    Args:
        List *lst: the list to delete the node from
        ListNode *nodeToDelete: pointer to the node to delete
    return: none
    */
    ListNode *curr = lst->head;  

    //if the list has only one node
    if(lst->head == lst->tail){
        lst->head = lst->tail = NULL;
    }
    //if the node is the first one
    else if(lst->head == nodeToDelete){
        lst->head = nodeToDelete->next;
    }
    else{
        while(curr->next != nodeToDelete){
            curr = curr->next;
        }
        //if the node is in the end of the list
        if(lst->tail == nodeToDelete)
            curr->next = lst->tail = NULL;
        //if the node is the middle of the list
        else
            curr->next = nodeToDelete->next;
    }
    freeNode(nodeToDelete);
}

void freeNode(ListNode *nodeToDelete){
    /*free a dynamic memory node
    
    Args:
        ListNode *nodeToDelete: the node to free up
    Return: NULL
    */
    free(nodeToDelete->dataPtr);
    free(nodeToDelete);
}


List getList()
{
    List res;
    int size, num, i;
    makeEmptyList(&res);
    printf("Please enter the number of items to be entered:\n");
    scanf("%d", &size);
    printf("Please enter the numbers:\n");
    for(i = 0; i < size; i++)
    {
        scanf("%d", &num);
        insertDataToEndList(&res, num);
    }
    return res;
}

void insertNodeToEndList(List *list, ListNode *tail)
{
	if (isEmptyList(list) == true){
		list->head = list->tail = tail;
	}
	else{
		list->tail->next = tail;
		list->tail = tail;
	}		
	tail->next = NULL;
}

bool isEmptyList(List *list)
{
	if(list->head == NULL)
		return true;
	else
		return false;
}

List merge(List lst1, List lst2){
    ListNode *head1 = lst1.head;
    ListNode *head2 = lst2.head;
    List mergedList;
    int newData;

    makeEmptyList(&mergedList);
    while(head1 != NULL && head2 != NULL){
        if(*head1->dataPtr > *head2->dataPtr){
            newData = *head1->dataPtr;
            head1 = head1->next;
        }
        else{
            newData = *head2->dataPtr;
            head2 = head2->next;
        }
        insertDataToEndList(&mergedList, newData);
    }
    while(head1 != NULL){
        insertDataToEndList(&mergedList, *head1->dataPtr);
        head1 = head1->next;
    }
    while(head2 != NULL){
        insertDataToEndList(&mergedList, *head2->dataPtr);
        head2 = head2->next;
    }
    return mergedList;
}

void makeEmptyList(List *list)
{
    list->head = NULL;
    list->tail = NULL;
}

void insertDataToEndList(List *list, int num)
{
    /*create new list node with a specific data and append it to a list

    Args:
        List *list: the list to append
        int num: the data for the new node
    Return: NULL
    */
	ListNode *newTail;
	newTail = createNewListNode(num, NULL);
	insertNodeToEndList(list, newTail);
}

ListNode* createNewListNode(int data, ListNode *next)
{
    /*creates new list node

    Args:
        int data: data of the node
        ListNode *next: the next node in the list
    Return: ListNode*: pointer to dynamic memory list node, with the requested data
    */
	ListNode *res;
    int *dataPtr;

	res = (ListNode*)calloc(1, sizeof(ListNode));
    checkAllocation((int)res);
    dataPtr = (int*)calloc(1, sizeof(int));
    checkAllocation((int)dataPtr);
    *dataPtr = data;
	res->dataPtr = dataPtr;
	res->next = next;
	return res;
}

void checkAllocation(int memory){
    /*check if an allocation worked

    Args:
        int memory: an integer casting of the data pointer. 
            only null=0 is important
    Return: NULL
    */
    if(memory == 0){
        printf("memory allocation error");
        exit(0);
    }
}

void printList(List *list){
    /*prints the data within a list

    Args:
        List *list: the list to print
    Returns: NULL
    */
    ListNode *currNode;

    currNode = list->head;
    while(currNode!=NULL){
        printf("%d ", *currNode->dataPtr);
        currNode = currNode->next;    
    }
    printf("\n");
}