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

void List::reverse()
{
	Node* current = head;
	Node* nextNode = nullptr;
	Node* nextNextNode = nullptr;

	if (current == tail)
	{
		return;
	}

	nextNode = current->next;
	nextNextNode = nextNode->next;

	while( nextNextNode != nullptr)
	{

	}	

	nextNode->next = current;
	tail = head;
	tail->next = nullptr;
	head = nextNode;

}

