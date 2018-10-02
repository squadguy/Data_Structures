#include "linkedList.h"

int main()
{
	
        List* ll = new List;

        ll->createNode(5);
        ll->createNode(10);
        ll->createNode(15);

        ll->printList();
        ll->reverseList();
        ll->printList();
        ll->reverseList();
        ll->printList();


        delete ll;


	return 0;
}
