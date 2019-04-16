#include "node.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Precondition: "word" points to the upper-case English word with length > 1.
Post condition: The function inserts each character of "word" in Trie appropriately. Note that global variable "root" stores the root of the Trie datastructure.
You have to strictly implement this function as non-recursive.

*/

void insert_word(char *word)
{
	NODE** head=(NODE**)malloc(sizeof(NODE*));
	NODE* temp2=NULL;
	if(root==NULL)
			return;
	temp2=root;
	NODE* temp=root->child;
	*head=temp;
		

	for(int i=0;i<strlen(word);i++)
	{

		temp=search(word[i],temp);
		if(temp==NULL)
		{
			NODE* new=create_node(word[i]);
			if(*head==NULL)
			{
				temp2->child=new;
			}
			else
			insert(head,new);
			temp2=new;
			temp=new->child;
			*head=temp;
		}
		else
		{
			temp2=temp;
			temp=temp->child;
			*head=temp;
		}
		if(i==strlen(word)-1)
		{
			temp2->stop_word=TRUE;	
			printf("%c   ",temp2->c);

		}		
	}
		
}
