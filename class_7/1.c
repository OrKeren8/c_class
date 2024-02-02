#include <stdio.h>
#include <stdlib.h>

typedef struct tnode{
	int data;
	struct tnode *left;
	struct tnode *right;
}TNODE;

typedef struct tree{
	TNODE *root;
}TREE;

typedef int BOOL;
#define FALSE 0
#define TRUE 1

TREE buildTree();
int * evenValues(TREE tr, int *resSize);
BOOL hasPathSum(TREE tr, int sum);
int HowMany (TREE tr);
void freeTree(TREE * tr);
void freeTreeHelper(TNODE * root);
int checkEvenAmount(TNODE *root);
int evenValuesHelper(TNODE *root, int res[]);
BOOL hasPathSumHelper(TNODE *root, int sum);

void main()
{
	TREE mytree;
	int res, *even, i;

	mytree = buildTree();

	even = evenValues(mytree, &res);
	for (i = 0; i < res; i++)
		printf("%d ", even[i]);
	printf("\n");
	free(even);

	res = hasPathSum(mytree, 15);
	if (res == TRUE)
		printf ("\nHas path which sum up to 15\n");
	else
		printf ("\nNo path which sum up to 15 was found\n");
	
	res = hasPathSum(mytree, 23);
	if (res == TRUE)
		printf ("\nHas path which sum up to 23\n");
	else
		printf ("\nNo path which sum up to 23 was found\n");

	res = HowMany(mytree);
	printf ("\nThe tree has %d positive subtrees\n", res);

	freeTree(&mytree);
}


/* The function builds a specific tree in order to check the other functions
					4
		2						5
			-4			6				-9
									1
*/

TREE buildTree()
{
	TREE T;

	T.root = (TNODE *)malloc (sizeof(TNODE));
	T.root->data = 4;

	T.root->left = (TNODE *)malloc (sizeof(TNODE));
	T.root->left->data = 2;
	T.root->left->left = NULL;

	T.root->left->right = (TNODE *)malloc (sizeof(TNODE));
	T.root->left->right->data = -4;
	T.root->left->right->left = NULL;
	T.root->left->right->right = NULL;

	T.root->right = (TNODE *)malloc (sizeof(TNODE));
	T.root->right->data = 5;

	T.root->right->left = (TNODE *)malloc (sizeof(TNODE));
	T.root->right->left->data = 6;
	T.root->right->left->left = NULL;
	T.root->right->left->right = NULL;

	T.root->right->right = (TNODE *)malloc (sizeof(TNODE));
	T.root->right->right->data = -9;
	T.root->right->right->right = NULL;

	T.root->right->right->left = (TNODE *)malloc (sizeof(TNODE));
	T.root->right->right->left->data = 1;
	T.root->right->right->left->left = NULL;
	T.root->right->right->left->right = NULL;

	return T;

}

int * evenValues(TREE tr, int *resSize)
{
    int numOfEven=0, *res;
    
    numOfEven = checkEvenAmount(tr.root);
    *resSize = numOfEven;
    res = (int *)calloc(numOfEven, sizeof(int));
    evenValuesHelper(tr.root, res);
    return res;
}

int evenValuesHelper(TNODE *root, int res[]){
    int n1=0, n2=0;

    if (root == NULL){
        return 0;
    }
    n1 = evenValuesHelper(root->left, res);
    if((root->data)%2 == 0){
        res[n1] = root->data;
        n2 = evenValuesHelper(root->right, res+n1+1);
        return n1+n2+1;
    }
    else{
        n2 = evenValuesHelper(root->right, res+n1);
        return n2+n1;
    }
}

int checkEvenAmount(TNODE *root){
    int isEven=0;

    if(root == NULL)
        return 0;
    if(((root->data)+1)%2)
        isEven = 1;
    return (checkEvenAmount(root->left) + checkEvenAmount(root->right) + isEven);
}

BOOL hasPathSum(TREE tr, int sum)
{  
    return hasPathSumHelper(tr.root, sum);
}

BOOL hasPathSumHelper(TNODE *root, int sum){

    if (root == NULL)
        return FALSE;
    else if(sum == root->data)
        return TRUE;
    else if(hasPathSumHelper(root->left, sum-root->data) || hasPathSumHelper(root->right, sum-root->data))
        return TRUE;
    else
        return FALSE;
}


int HowMany (TREE tr)
{

}

int howManyHelper(TNODE *root, int *n1, int *n2, )



/* free all memory of a tree */
void freeTree(TREE * tr)
{
	freeTreeHelper(tr->root);
	tr->root = NULL;
}

void freeTreeHelper(TNODE * root)
{
	if (root == NULL)
		return;
	else
	{
		freeTreeHelper(root->left);
		freeTreeHelper(root->right);
		free (root);
	}
}