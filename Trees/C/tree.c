#include <stdio.h>
#include <stdlib.h>

int main()
{
	typedef struct node
	{
		struct node* left;
		struct node* right;
		int value;
	} node;


	node *root = malloc(sizeof(node));

	root->left = NULL;
	root->right = NULL;
	root->value = 8;

	node *one = malloc(sizeof(node));
	one->left = NULL;
	one->right = NULL;
	one->value = 2;

	root->left=one;
	printf("%d\n", root->value);
	printf("%d\n", root->left->value);
	

	return 0;
}

