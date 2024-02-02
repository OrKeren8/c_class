void makeEmptyList(List *lst)
{
    lst->head = NULL;
    lst->tail = NULL;
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
	tNodeToEndList(list, newTail);
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

ListNode* createNewListNode(int* data, ListNode *next)
{
    /*creates new list node

    Args:
        int* data: data of the node
        ListNode *next: the next node in the list
    Return: ListNode*: pointer to dynamic memory list node, with the requested data
    */
	ListNode *res;
	res = (ListNode*)malloc(sizeof(ListNode));
	res->dataPtr = data;
	res->next = next;
	return res;
}

bool isEmptyList(List *list)
{
	if(list->head == NULL)
		return true;
	else
		return false;
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

bool insertNodeToPlaceInList(List* lst, ListNode *node, int i)
{
	/*insert a node to specific place in a list

	Args:
		List* lst: list to add a node to
		ListNode *node: the node to add
		int i: new node index
	Return: if the insertion succeed or not 
	*/
	ListNode *after;
	after = getListNode(lst, i - 1);
	if(after == NULL && i > 0) // Illegal location
		return false;
	else if (i == 0) // Start of list
		insertNodeToStartList(lst, node);
	else if (after->next == NULL) // End of list
		insertNodeToEndList(lst, node);
	else // “Middle”
	{
		node->next = after->next;
		after->next = node;
	}
	return true;
}


ListNode *getListNode(List *list, int i){
	/*returns a specific node within a list

	Args:
		List *list: list to get the node from
		int i: the index of the node
	return: ListNode *: a pointer to the requested node
	*/
	ListNode *curr;

	curr = list->head;
	while(curr != NULL && i>0){
		curr = curr->next;
		i--;
	}
	return curr;
}

void insertNodeToStartList(List* lst, ListNode *head)
{
	/*insert a node to the start of a list

	Args:
		List* lst: the list to add a node to 
		ListNode *head: the head of the list
	Return: NULL
	*/
	if (isEmptyList(lst) == true)
	{
		head->next = NULL;
		lst->head = lst->tail = head;
	}
	else
	{
		head->next = lst->head;
		lst->head = head;
	}
}