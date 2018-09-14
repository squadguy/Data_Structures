#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*
 *must compile with -lm after source file for math lib
 */


	//Define a node
	typedef struct node{
		int data;
		struct node* next;
	} node;

//creates a node
	node* createNode(int data);


//Finds val that goes in middle 
	int findMiddleVal(int *);

int main(){

	//number of node in a side
	int sideSize = 3;
	//create an array representing the magic Squar
	node *magicSquare[sideSize][sideSize];

	//Our 'foothold' in [0][0] of our magic square
	//ceil returns a double need to cast sideSize to Double and then Cast back to int
	//int cornerCase = (int)ceil((double)sideSize/2);

		
	int midVal = findMiddleVal(&sideSize);

	printf("%d\n", midVal);

	
//Init the magic square (need to make a function)
	for (int i = 0; i < sideSize; ++i)
	{
		for (int j = 0; j < sideSize; ++j)
		{
			magicSquare[i][j] = createNode(0);
		}
	}


	return 0;
}

//Find the value which will go in the middle of the matrix
	int findMiddleVal(int* sideSize)
	{
		//ceil takes a double and returns a double
		//cast the int* to doubles, square them/divide by two and ceil it
		//Type cast that val to an int and return it
		int midVal = (int) ceil((double)((*sideSize * *sideSize))/2);

		return midVal;
	}	

//Create a magic cube node
	node* createNode(int data){
		node* tmp = malloc(sizeof(node));

		tmp->data = data;
		node* next = NULL;
		node* prev = NULL;

		return tmp;
	}
