#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct list_node
{
	char*  dataPtr;
	struct list_node*  next;
}ListNode;

typedef struct list
{
	ListNode* head;
	ListNode* tail;
}List;

typedef struct student
{
	List first;
	int grade;  
}Student;


Student unScramble (List  lst);
void makeEmptyList(List *lst);
void insertDataToEndList(List *lst, char ch);
ListNode* createNewListNode(char ch, ListNode *next);
void insertNodeToEndList(List *lst, ListNode *tail);
void printStudent(Student *stud);
bool isEmptyList(List *lst);
Student unScramble(List lst);
void makeEmptyStudent(Student *student);
void freeNode(ListNode *nodeToDelete);
void deleteNodeFromList(List *lst, ListNode *nodeToDelete);
void freeList(List *list);


void main()
{
    List lst;
    Student student;
    char ch;

    makeEmptyList(&lst);
    printf("Please enter the scrambled student:\n");
    ch = (char)getchar(); 
    while(ch != '\n')
    {
        insertDataToEndList(&lst, ch);
        ch = (char)getchar();
    }
    
    student = unScramble(lst);
    printStudent(&student);
    freeList(&student.first);
}

void freeList(List *list){
    while(list->head != NULL){
        deleteNodeFromList(list, list->head);
    } 
}

void makeEmptyList(List *lst)
{
    lst->head = NULL;
    lst->tail = NULL;
}

void insertDataToEndList(List *lst, char ch)
{
	ListNode * newTail;
	newTail = createNewListNode(ch, NULL);
	insertNodeToEndList(lst, newTail);
}

ListNode* createNewListNode(char ch, ListNode *next)
{
	ListNode *res;
    char *charPtr;
	res = (ListNode*)calloc(1, sizeof(ListNode));
    charPtr = (char*)calloc(1, sizeof(char));
	*charPtr = ch;
    res->dataPtr = charPtr;
	res->next = next;
	return res;
}

void insertNodeToEndList(List *lst, ListNode *tail)
{
	if (isEmptyList(lst) == true){
		lst->head = lst->tail = tail;
	}
	else{
		lst->tail->next = tail;
		lst->tail = tail;
	}		
	tail->next = NULL;
}

void printStudent(Student *stud){
    /*print student data
    Args:
        Student *stud: student to print
    Return: NULL
    */
    ListNode *curr;
    
    printf("First name: ");
    if(stud->first.head != NULL)
    {
        curr = stud->first.head;
        while(curr!=NULL){
            printf("%c", *(curr->dataPtr));
            curr = curr->next;
        }
        printf("\n");
    }
    printf("Grade: %d\n", stud->grade);
}

bool isEmptyList(List *lst)
{
	if(lst->head == NULL)
		return true;
	else
		return false;
}

Student unScramble(List lst){
    /*take scrambled list and separate first name and grade in it
    the function take linked list of characters which represents numbers and characters.
    and separate them, the numbers are creating the student's grade, 
    and the characters are left in the linked list which represents his first name.

    Args:
        List lst: linked list of scrambled characters
    return: Student: structure of a student
    */
    Student student;
    ListNode *curr, *next;
    int grade = 0;

    if(lst.head == NULL)
        makeEmptyStudent(&student);
    else{
        curr = lst.head;
        while(curr != NULL){
            next = curr->next;
            if(('0' <= *(curr->dataPtr)) && (*(curr->dataPtr) <= '9')){
                grade *= 10;
                grade += (*curr->dataPtr) - (int)'0';
                deleteNodeFromList(&lst, curr);
            }
            curr = next;
        }
        student.first = lst;
        student.grade = grade;
    }
    return student;
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

void makeEmptyStudent(Student *student){
    /*take a student structure and empty it
    
    Args:
        Student *student: student structure to empty
    return: null
    */
    student->grade = -1;
    student->first.head = NULL;
    student->first.tail = NULL;
}