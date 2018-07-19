#include <stdio.h>
#include <stdlib.h>

//Demonstrating creating a linked list in C.
//A linked list is a set of nodes, each node contains a datafield
//and a pointer to the next node in the list.
//The last node in the list points to NULL
//
//To make a linked list:
//Create a Node Structure with the datafield type and the datafield
//A structure pointing to a node "next"
//Create a pointer to the "head" of the node and set it to NULL
//Add a Node (start with "head"):
//Allocate Memory for the node 
//Check if memory was allocated
//Assign a value to the node and set the "next" pointer to NULL

int main()
{
//Define a Node Structure
	typedef struct Node {
		int dataValue;

		struct Node * next;

	} node_t;
	node_t * head = NULL;
	head = malloc(sizeof(node_t));
//Validate we allocated memory
	if (head == NULL)
	{
		return 1;
	}

// Give the head value and set next to null
	head -> dataValue = 1;
	head -> next = NULL;
//	printf("%d\n", head->dataValue);

	head->next = malloc(sizeof(node_t));
	head->next->dataValue = 3;
	head->next->next= NULL;
	printf("%d\n", head->next->dataValue);


	

	return 0;
}
