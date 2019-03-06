#include "stack.h"

Stack* createStack(unsigned capacity)
{
	Stack* St=(Stack*)malloc(sizeof(Stack));
	St->top=-1;
	St->capacity=capacity;
    St->l=(int*)malloc(sizeof(int)*St->capacity);
    St->h=(int*)malloc(sizeof(int)*St->capacity);
	return St;
}

int isFull(Stack* stack) 
{   return stack->top == stack->capacity - 1; } 
  
// Stack is empty when top is equal to -1 
int isEmpty(Stack* stack) 
{   return stack->top == -1;  } 
  
// Function to add an item to stack.  It increases top by 1 
void push(Stack* stack,  int l,int h) 
{ 
    if (isFull(stack)) 
        return; 
     stack->h[++stack->top]=h;
     stack->l[stack->top]=l;

} 
  
// Function to remove an item from stack.  It decreases top by 1 
int pop(Stack* stack ) 
{ 
    if (isEmpty(stack)) 
        return -1; 
    return stack->top--;
} 
