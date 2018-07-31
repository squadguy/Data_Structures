#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


struct Stack
{
	int top;
	unsigned capacity;
	int* array;
};

struct Stack* createStack(unsigned capacity)
{
	struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
	stack->capacity = capacity;
	stack->top = -1;
	stack->array = (int*) malloc(stack->capacity * sizeof(int));

	return stack;
}

int isFull(struct Stack* stack)
{
	return stack->top == stack->capacity -1;
}	

int isEmpty(struct Stack* stack)
{
	return stack->top  == -1;
}

void push (struct Stack* stack, int item)
{
	if(isFull(stack))
		return;
	stack->array[++stack->top] = item;
	printf("%d pushed to stack \n");
}

int pop (struct Stack* stack)
{
	if(isEmpty(stack))
		return INT_MIN;
	return stack->array[stack->top--];
}

int peek (struct Stack* stack)
{
	return stack->array[stack->top];
}

int main()
{
	struct Stack * stack = createStack(100);

	printf("%d\n", stack->capacity);
	printf("%d\n", isFull(stack));
	printf("%d\n", isEmpty(stack));
	push(stack, 9);
	push(stack, 8);
	push(stack, 7);
	printf("%d\n",peek(stack));
	printf("%d\n",pop(stack));
	printf("%d\n",peek(stack));


	return 0;
}
