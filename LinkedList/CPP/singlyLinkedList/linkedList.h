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
		void enqueue(int);
		void enqueueNode(Node*);
		void reverse();
		void orderedInsert(Node*, Node*);
		Node* getHead();
		

	private:
		Node* tail;
		Node* head;

};

#endif
