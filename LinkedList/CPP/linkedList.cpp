
#include <iostream>

int main()
{
	struct Node
	{
		struct Node* next;
		struct Node* prev;
		int val;

	};

	class List
	{
		public:
			List()
			{
				tail = NULL;
				head = tail;
			}
			~List()
			{	
				while(head != NULL)
				{
					dequeue();
				}	
			};


			void createNode(int data) 
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

			void printList()
			{
				Node* current = head;
				while( current != NULL)
				{
					std::cout << current->val << std::endl;
					current = current->next;
				}
			}

			void reversePrintList()
			{
				Node* current = tail;
				while( current != NULL)
				{
					std::cout << current->val << std::endl;
					current = current->prev;
				}
			}

			void reverseList()
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

			int dequeue()
			{
				int value = head->val;
				Node* current = head;
			//	std::cout << head->val << std::endl;
				head = head->next;

				delete current; 

				return value;
			}

		private:
			Node* head = NULL;
			Node* tail = NULL;
	};

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
