#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0

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

void initialize(queue *q)
{
	q->count = 0;
	q->front = NULL;
	q->rear = NULL;
}

int isEmpty(queue *q)
{
	return(q->rear == NULL);
}

void enqueue (queue *q, int value)
{
	node *tmp;
	tmp = malloc(sizeof(node));
	
	tmp->data=value;
	tmp->next=NULL;
	
	if (!isEmpty(q))
	{
		q->rear->next = tmp;
		q->rear = tmp;	
	}
	else
	{
		q->front = q->rear = tmp;
	}
	q->count++;

}

int main()
{
	queue *q;
	q = malloc(sizeof(queue));
	initialize(q);

	enqueue(q,10);
	enqueue(q,12);

	printf("%d\n", q->rear->data);
	printf("%d\n", q->count);


	/*
//Init a queue
	queue *q;
	q = malloc(sizeof(queue));
	
//Init a tmp node
	node *tmp = NULL;
	tmp = malloc(sizeof(queue));
	tmp->data = 15;
	tmp->next = NULL;

	printf("%d\n", tmp->data);

//Simulate intial enqueue
	q->front = q->rear = tmp->data;
	q->count++;
	printf("%d\n", q->count);
	printf("%d\n", q->front);
	printf("%d\n", q->rear);
//Enqueue second node
	tmp->data=33;
	q->rear=malloc(sizeof(node));
	q->rear->next=tmp;
	q->rear=tmp;	
	printf("%d\n", q->rear->data);
	q->count++;
	printf("%d\n", q->count);

//Enqueue third Node	
	tmp->data=55;
	q->rear->next=tmp;
	q->rear=tmp;	
	printf("%d\n", q->rear->data);
	q->count++;
	printf("%d\n", q->count);

//Enqueue fourth Node	
	tmp->data=100;
	q->rear->next=tmp;
	q->rear=tmp;	
	printf("%d\n", q->rear->data);
	q->count++;
	printf("%d\n", q->count);
	*/

	return 0;
}
