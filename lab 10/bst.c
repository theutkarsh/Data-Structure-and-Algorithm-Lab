#include"avl.h"

Node* create(int v)
{
	Node * t= malloc(sizeof(Node));
	t->val=v;
	t->left=NULL;
	t->right=NULL;
	t->bal =0;
	return t;
}
void print(Node* root)
{	
	if(root-> left!=NULL)
		print(root->left);
	printf("%d\t",root->val);
	if(root-> right!=NULL)
		print(root->right);
}
Node* parent(Node *root,Node *se)
{
if(root!=NULL){
	int v=se->val;
	Node *temp=root;
	Node* temp2=NULL;
while(1)
{
	if(temp->val>v )
	{
		if(temp->left!=NULL)
		{
			temp2=temp;
			temp=temp->left;

		}
		else 
		return 0;

	}
	if(temp->val<v )
	{
		if(temp->right!=NULL)
		{
			temp2=temp;
			temp=temp->right;
		}
		else 
		{
			return 0;
		}
	}
	if(temp->val==v)
	{
		return temp2;
	}

}
}	
}	
	
Node* inorder_successor(Node* root,Node* parent)
{
	if (root->right!=NULL)
	{
		Node* temp=root->right;
		while(temp->left!=NULL)
		{
			temp=temp->left;
		}
		return temp;
	}
	else if(parent==NULL)
		return NULL;
	else if(parent->left==root)
	{
		return parent;
	}
	else 
		return NULL;
}
		
void add ( Node* root, int v)
{if(root!=NULL){
	Node* new=create(v);
	Node *temp=root;
while(1)
{
	if(temp->val>v )
	{
		if(temp->left!=NULL)
		{
			temp=temp->left;
		}
		else 
		{
			temp->left=new;
			return;
		}
	}
	if(temp->val<v )
	{
		if(temp->right!=NULL)
		{
			temp=temp->right;
		}
		else 
		{
			temp->right=new;
			return;
		}
	}
	if(temp->val==v)
	{
		if(temp->right!=NULL)
		{
			temp=temp->right;
		}
		else if(temp->left!=NULL)
		{
			temp=temp->left;
		}
		else
		{
			temp->left=new;
			return;
		}
	}

}
}				
}
	
	
int find ( Node* root, int v)
{
if(root!=NULL){

	Node *temp=root;
while(1)
{
	if(temp->val>v )
	{
		if(temp->left!=NULL)
		{
			temp=temp->left;
		}
		else 
		return 0;

	}
	if(temp->val<v )
	{
		if(temp->right!=NULL)
		{
			temp=temp->right;
		}
		else 
		{
			return 0;
		}
	}
	if(temp->val==v)
	{
		return 1;
	}

}
}	
}	

void deleten( Node* root, int v)
{
	if(root!=NULL){

		Node *temp=root;
		Node *temp2=NULL;
	while(1)
	{
		if(temp->val>v )
		{
			if(temp->left!=NULL)
			{
				temp2=temp;
				temp=temp->left;
			}
			else 
			return ;

		}
		if(temp->val<v )
		{
			if(temp->right!=NULL)
			{
				temp2=temp;
				temp=temp->right;
			}
			else 
			{
				return ;
			}
		}
		if(temp->val==v)
		{
			while(1)
			{	
				Node* succ=inorder_successor(temp,temp2);
				if(temp->left==NULL && temp->right==NULL)
				{
					//for root node
					if(temp2==NULL){
						temp->val=NULL;
						free(temp);
						printf("Empty root\n");
						return;}
					if(temp2->left==temp)
					{
						temp2->left=NULL;
						free(temp);
						return;
					}
					else if(temp2->right==temp)
					{
						temp2->right=NULL;
						free(temp);
						return;
					}
				}
				//if left child is there but no successor.
				else if(succ==NULL )
				{
					//for root node
					if(temp2==NULL)
					{
						Node* new=temp->left;
						root->left=new->left;
						root->val=new->val;
						root->right=new->right;
						root->bal=new->bal;
						free(new);
						return;
					}
					temp2->right=temp->left;
					free(temp);
					return;
				}
				else 
				{
					temp2=parent(root ,succ);
					int t=succ->val;
					succ->val=temp->val;
					temp->val=t;
					temp=succ;
				}				
			
			}

		}
	
	}	
}
}
	
	
	
	
	
	
	
	
