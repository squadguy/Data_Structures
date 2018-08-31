#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	struct node* left;
	struct node* right;
	int value;
} node;

node* initTree(int);

int main()
{


	node *root = malloc(sizeof(node));

	root = initTree(8);	

	printf("%d\n", root->value);
	return 0;
}

node* initTree (int data)
{
	node *tmpNode = malloc(sizeof(node));

	tmpNode->left = NULL;
	tmpNode->right = NULL;
	tmpNode->value = data;

	return tmpNode;
}
