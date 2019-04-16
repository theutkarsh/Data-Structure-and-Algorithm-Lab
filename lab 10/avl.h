#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int val;
	struct node* left;
	struct node* right;
	int bal:2;
}Node;

Node* create(int v);
void print(Node* root);
Node* parent(Node *root,Node *se);
Node* inorder_successor(Node* root,Node* parent);
void add ( Node* root, int v);
int find ( Node* root, int v);
void deleten( Node* root, int v);
