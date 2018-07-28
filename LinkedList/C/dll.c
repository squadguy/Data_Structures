#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
	struct node *prev;
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
	ll->head->prev=NULL;

}

void add (linkedList *ll, int value)
{
	node_t * tmp;
	node_t * current;
	tmp = malloc(sizeof(node_t));
	tmp->data=value;
	tmp->next=NULL;
	tmp->prev=NULL;
	
	current = ll->head;

	while (current->next != NULL)
	{
		current = current->next;
	}
	tmp->prev=current;
	current->next = tmp;
}

void print(linkedList *ll)
{
	node_t * current;
	current = ll->head;

	while (current->next != NULL)
	{
		printf("%d\n", current->data);
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

//	print(ll);

	printf("%d\n", ll->head->data);
	printf("%d\n", ll->head->next->data);
	printf("%d\n", ll->head->next->next->data);
	printf("%d\n", ll->head->next->next->prev->data);
	printf("%d\n", ll->head->next->next->prev->prev->data);
	

	return 0;
}
