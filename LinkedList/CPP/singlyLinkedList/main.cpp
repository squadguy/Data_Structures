#include "linkedList.h"

int main()
{
	List* ll = new List;


	Node* newNode = new Node;
	newNode->next = nullptr;
	newNode->val = 20;

	ll->enqueue(4);
	ll->enqueue(3);
	ll->enqueue(2);
	ll->enqueue(1);

	ll->printList();

	ll->reverse();
	ll->printList();
	ll->reverse();
	ll->printList();
	ll->appendNode(5);
	ll->printList();
	ll->reverse();
	ll->appendNode(0);
	ll->printList();
	ll->enqueue(6);
	ll->printList();
	ll->reverse();
	ll->printList();
	delete ll;

	return 0;
}
