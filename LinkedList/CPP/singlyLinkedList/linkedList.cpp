#include "linkedList.h"

List::List()
{
	tail = nullptr;
	head = tail;
}

List::~List()
{
	while (head != nullptr)
	{
		dequeue();
	}
}

void List::appendNode(int val)
{
	Node* tmp = new Node;

	tmp->val = val;
	tmp->next = nullptr;

	if(tail == nullptr)
	{
		head = tmp;
		tail = tmp;
	
	}
	else
	{
		tail->next = tmp;
		tail=tmp;
	}

}

void List::printList()
{
	Node* current = head;

	while(current != nullptr)
	{
		std::cout << current->val << std::endl;

		current = current->next;
	}


}

int List::dequeue()
{
	int nodeVal = head->val;
	Node* current = head;
	head = head->next;

	delete current;

	return nodeVal;

}

void List::enqueue(int data)
{
	Node* tmp = new Node;
	tmp->val = data;
	tmp->next = nullptr;

	if ( tail == nullptr)
	{
		head = tmp;
		tail = tmp;
	}
	else
	{
		tmp->next = head;
		head = tmp;
	}

}

void List::enqueueNode(Node* newNode)
{
	if ( tail == nullptr)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		newNode->next = head;
		head = newNode;
	}
}

void List::reverse()
{
	Node* current = head;
	Node* nextNode = nullptr;
	Node* nextNextNode = nullptr;

	if (tail == nullptr)
	{
		std::cout << "HI" << std::endl;
		return;
	}

	nextNode = current->next;
	nextNextNode = nextNode->next;

	while( nextNextNode != nullptr)
	{
		nextNode->next = current;
		current = nextNode;
		nextNode = nextNextNode;
		nextNextNode = nextNode->next;
	}	

	nextNode->next = current;
	tail = head;
	tail->next = nullptr;
	head = nextNode;

}

Node* List::getHead()
{
	return head;
}

void List::orderedInsert(Node* headRef, Node* newNode)
{
	Node* current;

	if( headRef == nullptr || headRef->val >= newNode->val)
	{
		enqueueNode(newNode);
	}
	else
	{
		current = head;

		while (current->next != nullptr && current->next->val <= newNode->val)
		{
			current = current->next;
		}
			newNode->next = current->next;
			current->next = newNode;
			
		
	}
}
