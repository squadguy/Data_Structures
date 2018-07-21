#include<stdio.h>
#include<stdlib.h>

typedef struct node 
{
	int data;
	struct node *next;
} node;

typedef struct queue
{
	int count;
	node *front;
	node *rear;
} queue;


int main()
{
//Driver to test our Node Struct
//make nodes for list and tmp node
	node *list = NULL;
	node *tmp = NULL;
	tmp = malloc(sizeof(node));
	list = malloc(sizeof(node));
	tmp->data=NULL;
	tmp->next=NULL;

//create intial node 
	list->data = 12;
	list->next = NULL;
	printf("%d\n", list->data);

//Change tmp value
	tmp->data=8;

//create second node
	list->next=malloc(sizeof(node));
	list->next->data = tmp->data;
	list->next->next = NULL;

	printf("%d\n", list->next->data);

//Update tmp value
	tmp->data=55;

//Create third node
	list->next->next=malloc(sizeof(node));
	list->next->next->data = tmp->data;
	list->next->next->next = NULL;

	printf("%d\n", list->next->next->data);
		
	return 0;
}
