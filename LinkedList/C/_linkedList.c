/*
 *
 * Next up: Write insert_front();
 *
 */

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

void insert_end(node* ll, int data)
{
	node *current = ll;
	int _data = data;
	while(current->next !=NULL)
		current = current->next;
	current->next = malloc(sizeof(node));
	current->next->value = _data;
	current->next->next = NULL;
	
}

int main()
{

	node *ll = initialize(5);
	
	insert_end(ll, 100);
	insert_end(ll, 101);

	display_list(ll);
	
	return 0;
}
