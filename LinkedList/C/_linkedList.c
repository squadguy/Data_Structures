/*
 *
 * To Do: insert_At() | pop() | pop_back() | remove_at() | fork for doubly linked list.
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
	int length;

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
	ll->length = 1;

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

void insert_end(linkedlist* ll, int data)
{
	node *current = ll->head;
	int _data = data;
	while(current->next !=NULL)
		current = current->next;
	current->next = malloc(sizeof(node));
	current->next->value = _data;
	current->next->next = NULL;
	
	ll->length++;	
}

void insert_front(linkedlist* ll, int data)
{
	int _data = data;

	node *tmp_node = malloc(sizeof(node));	
	tmp_node->value = _data;
	tmp_node->next = NULL;

	tmp_node->next = ll->head;

	ll->head = tmp_node;
	ll->length++;

}

void insert_at(linkedlist* ll, int index, int data)
{
	int _index = index;
	int _data = data;
	int i = 1;       //iterator for while loop

	node * tmp = malloc(sizeof(node));
	tmp->next = NULL;
	tmp->value=_data;

	node * current = malloc(sizeof(node));
	current=ll->head;

//Verify the requested index is in range

	if( (_index + 1) > (ll->length))
	{
		printf("Out of range\n");
		return;
	}

//To insert at index 0	
	if(_index == 0)
	{
		insert_front(ll,_data);
		return;
	}

//For everything else	
	while(i < _index)
	{
		current = current->next;	
		i++;
	}	

//Rearrange pointers to perform insert operation	
	tmp->next = current->next;
	current->next = tmp;
	
	ll->length++;

}
int main()
{

	linkedlist *ll = initialize(15);
	insert_end(ll, 20);
	insert_end(ll, 30);	
	insert_front(ll,10);
	insert_front(ll,5);
	insert_end(ll, 35);	
	insert_end(ll, 100);	
//	insert_front(ll, 1);
	insert_end(ll, 110);
	insert_at(ll,0,1);
	insert_front(ll, 456);
	display_list(ll);
	printf("%d\n", ll->length);
	

	return 0;
}
