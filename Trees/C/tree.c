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
int main()
{


	node *root = malloc(sizeof(node));
	root = createNode(8);	
	insertLeft(root, 4);
	insertRight(root, 9);

	printf("%d\n", root->value);
	printf("%d\n", root->left->value);
	printf("%d\n", root->right->value);

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
	tmpNode = createNode(4);

	root->left = tmpNode;
}

void insertRight (node* root, int data)
{
	node* tmpNode = malloc(sizeof(node));
	tmpNode = createNode(10);

	root->right = tmpNode;
}
