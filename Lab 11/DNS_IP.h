#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
	int n;
	struct node ** child;
	char *x;
	char* ip;
	int size;
	struct node* parent;
}Node;

void create(Node *new,char *x,	char *ip , Node* p);
Node* ReadData();
void insert(Node* root,char** domain,int num,char * ip);
int search_level(Node* parent, char* target);
void search(Node* root,char* name );
void printR(Node* root);





