#include "linkedList.h"

int main()
{
	List* ll = new List;

	ll->appendNode(5);
	
	ll->printList();

	ll->reverse();

	ll->printList();
	ll->reverse();
	ll->printList();
	ll->reverse();
	ll->printList();

	delete ll;

	return 0;
}
