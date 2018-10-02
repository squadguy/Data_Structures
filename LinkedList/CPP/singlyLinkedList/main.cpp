#include "linkedList.h"

int main()
{
	List* ll = new List;
	
	Node* tmp = new Node;
	tmp->next = nullptr;
	tmp->val = 5;
	
	ll->enqueue(3);
	ll->enqueue(4);
	ll->orderedInsert(ll->getHead(), tmp);
	
	ll->printList();
	ll->reverse();
	ll->printList();
	ll->reverse();
	ll->printList();


	delete ll;

	return 0;
}
