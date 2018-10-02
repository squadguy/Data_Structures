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
	//	void sortedInsert(Node*, Node*);
		Node* getHead();
		

	private:
		Node* tail;
		Node* head;

};

#endif
