#include "node.h"
#include <iostream>

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class List
{
	public:
		List();
		~List();

		void appendNode(int);
		void printList();
		int dequeue();
		void reverse();
		

	private:
		Node* tail;
		Node* head;

};

#endif
