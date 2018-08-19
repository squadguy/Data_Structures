#include<stdio.h>
#include<stdlib.h>

typedef struct Node {

	int value;
	struct Node *next;

} node;

node* initialize(int data)
{
	int _data = data;	
	node *head = NULL;

	head = malloc(sizeof(node));	
	head->value = _data;
	head->next = NULL;
	
	return head;	
}

int main()
{

	node *ll = initialize(5);

	printf("%d\n", ll->value);

	ll->next = malloc(sizeof(node));

	ll->next->value = 10;
	printf("%d\n", ll->next->value);

	return 0;
}
