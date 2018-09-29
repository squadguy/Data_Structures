
#include <iostream>

int main()
{
	struct Node
	{
		struct Node* next;
		int val;

	};

	class List
	{
		public:
			List()
			{
				head = NULL;
				tail = NULL;
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

				if(head == NULL)
				{
					head = tmp;
					tail = tmp;	
				}
				else
				{
					tail->next = tmp;
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

			int dequeue()
			{
				int value = head->val;
				Node* current = head;
				std::cout << head->val << std::endl;
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

	delete ll;

	return 0;
}
