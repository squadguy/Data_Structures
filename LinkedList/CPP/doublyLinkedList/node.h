#ifndef NODE_H
#define NODE_H

typedef struct Node
{
	struct Node* next;
	struct Node* prev;
	int val;
} Node;


#endif
