#include "linkedList.h"

int main()
{
	List* ll = new List;

	ll->appendNode(1);
	ll->appendNode(2);
	ll->appendNode(3);
	ll->appendNode(4);
	ll->appendNode(5);
	ll->appendNode(6);
	ll->appendNode(7);
	
	std::cout << ll->getHead()->val << std::endl;

	delete ll;

	return 0;
}
