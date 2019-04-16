#include "node.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern NODE * root;
/*
Precondition: "word" points to the upper-case English word with length > 1.
Post condition: the function returns TRUE if "word" is present in the Trie; FALSE otherwise. Note that global variable "root" stores the root of the Trie data structure.
You have to strictly implement this fun as non-recursive.

*/

boolean search_word(char *word)
{
	NODE* temp=root->child;

	for(int i=0;i<strlen(word);i++)
	{
		if(temp==NULL)
			return FALSE;
		temp=search(word[i],temp);

		if(temp==NULL)
			return FALSE;

		if(i==strlen(word)-1)
		{
			if(temp->stop_word==TRUE)
				return TRUE;
			else
				return FALSE;
		}	
		temp=temp->child;		
	}
	
}
