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


//seond node in linked list
//allocate memory
	head->next = malloc(sizeof(node_t));
//ensure memory allocated
	if (head->next == NULL)
	{
		return 1;
	}

	head->next->dataValue = 3;
	head->next->next= NULL;
//	printf("%d\n", head->next->dataValue);

//third node in linked list
	head->next->next = malloc(sizeof(node_t));

	if (head->next->next == NULL)
	{
		return 1;
	}

	head->next->next->dataValue=6;
	head->next->next->next=NULL;
//	printf("%d\n", head->next->next->dataValue);

//Prints a node, takes the linked lists head as arguement
	void print_list (node_t * head)
	{
		node_t * current = head;

		while (current != NULL)
		{
			printf("%d\n", current->dataValue);
			current = current->next;

		}
		
/**
  *		printf("%d\n", current->dataValue);
//		printf("%d\n", head->next->dataValue);
//
		current = current->next;
		printf("%d\n", current->dataValue);

		current = current->next;
* 		printf("%d\n", current->dataValue);
**/
	}

	void q_push (node_t * head, int val)
	{
		node_t * current = head;

		while (current->next != NULL)
		{
			current = current->next;
		}

		current->next = malloc(sizeof(node_t));
/*
		if (current->next == NULL)
		{
			return 1;
		}
*/
		current->next->dataValue = val;
		current->next->next = NULL;


	
	
	}

	print_list(head);
	q_push(head, 5);
	print_list(head);

	return 0;
}
