#include <stdio.h>
#include <stdlib.h>

typedef struct Node {

	int val;
	struct Node* left;
	struct Node* right;

} Node;

typedef struct Tree {

	Node* root;

} Tree;

Tree* initTree();
Node* createNode(int);
void addKey(Tree*, int);

int main()
{
	Tree *tree = initTree();

	addKey(tree, 3);
	addKey(tree, 4);

	printf("%d\n",tree->root->val);
	printf("%d\n",tree->root->right->val);

	return 0;
}

Node* createNode(int data)
{
	Node* node = malloc(sizeof(*node));

	node->left = NULL;
	node->right = NULL;
	node->val = data;

	return node;
}

void addKey(Tree* tree, int data)
{
	Node* current = tree->root;
	int sent = 0;

	if (current == NULL)
	{
		tree->root = createNode(data);
	} else {
		while(sent == 0)
		{
			if (current->val >= data)
			{
				if (current->left == NULL)
				{
					current->left = createNode(data);
					sent = 1;
				}
				else
				{
					current = current->left;
				}
			}
			else
			{
				if (current->right == NULL)
				{
					current->right = createNode(data);
					sent = 1;
				}
				else
				{
					current = current->right;
				}
			}
		}
	}
}


Tree* initTree()
{
	Tree *tree = malloc(sizeof(*tree));
	tree->root = NULL;

	return tree;
}
