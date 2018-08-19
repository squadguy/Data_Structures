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

void display_list(node* ll)
{
	node *current = ll;
	while(current != NULL)
	{
		printf("%d\n", current->value);
		current = current->next; 	
	}
}

int main()
{

	node *ll = initialize(5);

	ll->next = malloc(sizeof(node));
	ll->next->value = 10;
	ll->next->next = NULL;
	ll->next->next = malloc(sizeof(node));
	ll->next->next->value = 15;
	ll->next->next->next = NULL;	

	display_list(ll);

	return 0;
}
