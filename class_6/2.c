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

TREE buildTree();
void printLevel(TREE *tree, int level);
void printLevelHelper(TNODE *root, int level);
TNODE * find(TREE* tr, int item)

void main()
{
	TREE mytree;
	TNODE * res;

	mytree = buildTree();

	printf("\nprint level 1\n");
	printLevel(&mytree, 2);
    

	// printf("\n\nprint by levels\n");
	// printTreeByLevels(&mytree);

	// res = find(&mytree,10);
	// if (res == NULL)
	// 	printf ("\n10 not found\n");
	// else
	// 	printf ("\n10 found\n");

	// res =find(&mytree,9);
	// if (res == NULL)
	// 	printf ("\n9 not found\n");
	// else
	// 	printf ("\n9 found\n");

	// {
	// 	TREE cpTr;

	// 	cpTr = copyTree(&mytree);

	// 	printf("\nThe original tree\n");
	// 	printTreeDLR(&mytree);
	// 	printf("\nThe copied tree\n");
	// 	printTreeDLR(&cpTr);

	// 	freeTree(&cpTr);
	// }
	
	// freeTree(&mytree);
}


/* The function builds a specific tree in order to check the other functions */ 
TREE buildTree()
{
	TREE T;

	T.root = (TNODE *)malloc (sizeof(TNODE));
	T.root->data = 3;

	T.root->left = (TNODE *)malloc (sizeof(TNODE));
	T.root->left->data = 2;
	T.root->left->left = NULL;

	T.root->left->right = (TNODE *)malloc (sizeof(TNODE));
	T.root->left->right->data = 4;
	T.root->left->right->left = NULL;
	T.root->left->right->right = NULL;

	T.root->right = (TNODE *)malloc (sizeof(TNODE));
	T.root->right->data = 5;

	T.root->right->left = (TNODE *)malloc (sizeof(TNODE));
	T.root->right->left->data = 7;
	T.root->right->left->left = NULL;
	T.root->right->left->right = NULL;

	T.root->right->right = (TNODE *)malloc (sizeof(TNODE));
	T.root->right->right->data = 9;
	T.root->right->right->right = NULL;

	T.root->right->right->left = (TNODE *)malloc (sizeof(TNODE));
	T.root->right->right->left->data = 1;
	T.root->right->right->left->left = NULL;
	T.root->right->right->left->right = NULL;

	return T;
}

void printLevel(TREE *tree, int level){
    printLevelHelper(tree->root, level);
}
void printLevelHelper(TNODE *root, int level){
    if(root==NULL){
        return;
    }
    else if( level == 0){
        printf("%d ", root->data);
    }
    else{
        printLevelHelper(root->left, level - 1);
        printLevelHelper(root->right, level - 1);
    }
}

TNODE * find(TREE* tr, int item){
    findHelper(tr->root, item);
}
TNODE * findHelper(TNODE *root, int item){
    if(root == NULL){
        return NULL;
    }
    else if(root->data == item){
        return 
    }
}