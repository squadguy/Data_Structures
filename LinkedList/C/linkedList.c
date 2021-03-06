#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
} node_t;

typedef struct linkedList
{
	struct node *head;
} linkedList;

void initialize (linkedList *ll, int value)
{
	ll->head=NULL;		
	ll->head=malloc(sizeof(node_t));

	ll->head->data=value;
	ll->head->next=NULL;

}

void add (linkedList *ll, int value)
{
	node_t * tmp;
	node_t * current;
	tmp = malloc(sizeof(node_t));
	tmp->data=value;
	tmp->next=NULL;
	
	current = ll->head;

	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = tmp;
}

void insert_at_front(linkedList *ll, int value)
{
	node_t *tmp;
	tmp=malloc(sizeof(node_t));
	tmp->data=value;
	tmp->next=ll->head;
	ll->head=tmp;

}

void print(linkedList *ll)
{
	node_t * current;
	current = ll->head;

	while (current->next != NULL)
	{
		printf("%d->", current->data);
		current = current->next;
	}
		printf("%d\n", current->data);
	
}

int main()
{
	linkedList * ll = NULL;
	ll = malloc(sizeof(linkedList));

	initialize(ll,5);
	add(ll,10);
	add(ll,15);
	add(ll,20);
	print(ll);
//Test inserting at front
	insert_at_front(ll, 0);	
	print(ll);
	insert_at_front(ll, 25);	
	print(ll);
	add(ll,500);
	print(ll);

	return 0;
}
