/*
 *
 * Next up: Create a linked list struct, and refactor functions to interact with it.
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

void insert_front(node** ll, int data)
{
	int _data = data;

	node *tmp_node = malloc(sizeof(node));	
	tmp_node->value = _data;
	tmp_node->next = NULL;

	tmp_node->next = (*ll);
	(*ll) = tmp_node;

}

int main()
{

	node *ll = initialize(5);
	
	insert_end(ll, 100);
	insert_end(ll, 101);

	display_list(ll);

	insert_front(&ll,1);

	printf("%d\n", ll->value);
	
	return 0;
}
