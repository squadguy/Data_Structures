#include<stdio.h>
#include<stdlib.h>

int main(){

	//Define a node
	typedef struct node{
		int data;
		struct node* up;
		struct node* down;
		struct node* right;
		struct node* left;
		struct node* diagUpLeft;
		struct node* diagUpRight;
		struct node* diagDownRight;
		struct node* diagDownLeft;
	} node;


	//number of node in a side
	int sideSize = 3;
	//create an array representing the magic Squar
	node* magicSquare[sideSize][sideSize];

		
//Create a magic cube node
	node* createNode(int data){
	
		node* tmp = malloc(sizeof(node));

		tmp->data = data;
		tmp->up = NULL;
		tmp->down = NULL;
		tmp->right = NULL;
		tmp->left = NULL;
		tmp->diagUpLeft = NULL;
		tmp->diagUpRight = NULL;
		tmp->diagDownRight = NULL;
		tmp->diagDownLeft = NULL;

		return tmp;
	}

	
//Init the magic square (need to make a function)
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			magicSquare[i][j] = createNode(0);
			
		}
	}

//test
	magicSquare[0][2]->down = magicSquare[2][2];

	magicSquare[2][2]->data = 100;



	printf("%d\n", magicSquare[0][2]->down->data);


	return 0;
}
