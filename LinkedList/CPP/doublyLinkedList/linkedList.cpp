#include "linkedList.h"

		List::List()
			{
				tail = NULL;
				head = tail;
			}
		List::~List()
			{	
				while(head != NULL)
				{
					dequeue();
				}	
			}


		void List::createNode(int data) 
			{
				Node* tmp = new Node;
				tmp->val = data;
				tmp->next = NULL;
				tmp->prev = NULL;

				if(tail == NULL)
				{
					head = tmp;
					tail = tmp;	
				}
				else
				{
					tail->next = tmp;
					tmp->prev = tail;
					tail = tmp;
				}
			}

		void List::printList()
			{
				Node* current = head;
				while( current != NULL)
				{
					std::cout << current->val << std::endl;
					current = current->next;
				}
			}

		void List::reversePrintList()
			{
				Node* current = tail;
				while( current != NULL)
				{
					std::cout << current->val << std::endl;
					current = current->prev;
				}
			}

		void List::reverseList()
			{
				Node* current = tail;
				Node* prevNode = NULL;

				while ( current->prev != NULL )
				{
					prevNode = current->next;
					current->next = current->prev;
					current->prev = prevNode;
					current = current->next;
				}

				current->next = current->prev;
				current->prev = prevNode->next;

				/* Reverse tail && head ptrs */

				head = tail;
				tail = current;

			}

		int List::dequeue()
			{
				int value = head->val;
				Node* current = head;
			//	std::cout << head->val << std::endl;
				head = head->next;

				delete current; 

				return value;
			}


