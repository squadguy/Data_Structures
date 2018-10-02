#include <iostream>
#include "node.h"
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class List
{
	public:
		List();
		~List();

		void createNode(int data);
		void printList();
		void reversePrintList();
		void reverseList();
		int dequeue();

	private:
		Node* head = NULL;
		Node* tail = NULL;
};

#endif
