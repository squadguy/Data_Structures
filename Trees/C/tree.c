#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	struct node* left;
	struct node* right;
	int value;
} node;

node* createNode(int);
void insertLeft(node*, int);
void insertRight(node*, int);
void addNode (node* root, int data);
int main()
{


	node *root = malloc(sizeof(node));
	root = createNode(8);	
	/*
	insertLeft(root, 4);
	insertRight(root, 9);
	insertLeft(root->left, 2);
	*/

	addNode(root,10);
	addNode(root,7);
	addNode(root,5);
	addNode(root,12);


	printf("%d\n", root->value);
	printf("%d\n", root->right->value);
	printf("%d\n", root->left->value);
	printf("%d\n", root->left->left->value);
	printf("%d\n", root->right->right->value);

//	printf("%d\n", root->right->value);
//	printf("%d\n", root->left->left->value);

	return 0;
}

node* createNode (int data)
{
	node *tmpNode = malloc(sizeof(node));

	tmpNode->left = NULL;
	tmpNode->right = NULL;
	tmpNode->value = data;

	return tmpNode;
}

void insertLeft (node* root, int data)
{
	node* tmpNode = malloc(sizeof(node));
	tmpNode = createNode(data);

	tmpNode->left = NULL;
	tmpNode->right = NULL;

	root->left = tmpNode;
}

void insertRight (node* root, int data)
{
	node* tmpNode = malloc(sizeof(node));
	tmpNode = createNode(data);

	tmpNode->left = NULL;
	tmpNode ->right = NULL;
	root->right = tmpNode;
}

void addNode (node* root, int data)
{
	node* currentNode = root;
	int bs = 0;
	int* ptrBS = &bs;
	if (currentNode == NULL){
		root = malloc(sizeof(node));
		root->left = NULL;
		root->right = NULL;
		root->value = data;
	} else {
	while (*ptrBS == 0)
		if(currentNode->value >= data)
		{
			if(currentNode->left == NULL)
			{
				insertLeft(currentNode, data);
				*ptrBS=1;
			} else{
			       	currentNode = currentNode->left;
			}
		} else {
			if(currentNode->right == NULL)
			{
				insertRight(currentNode, data);
				*ptrBS=1;
			}else{
				currentNode = currentNode->right;
			}
		}
	}
	
}
