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

typedef struct LinkedList {

	node *head;	

} linkedlist;

linkedlist * initialize(int data)
{
	int _data = data;
	node *headNode = NULL;
	linkedlist *ll = NULL;

	headNode = malloc(sizeof(node));
	headNode->value = _data;
	headNode->next = NULL;

	ll = malloc(sizeof(node));
	ll->head = headNode;

	return ll;
}

void display_list(linkedlist* ll)
{
	node *current = ll->head;
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

	linkedlist *ll = initialize(15);
	
	node* tmp = malloc(sizeof(node));	
	tmp->value=20;
	tmp->next=NULL;	

	node* tmp2 = malloc(sizeof(node));	
	tmp2->value=25;
	tmp->next=NULL;	

	ll->head->next = tmp;
	ll->head->next->next = tmp2;

	display_list(ll);

	return 0;
}
