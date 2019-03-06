#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
typedef struct Stack
{
	int top;
	unsigned capacity;
	int* l;
	int* h;
}Stack;


Stack* createStack(unsigned capacity);
int isFull(Stack* stack) ;
int isEmpty(Stack* stack);
void push(Stack* stack,  int l,int h);
int pop(Stack* stack ) ;



