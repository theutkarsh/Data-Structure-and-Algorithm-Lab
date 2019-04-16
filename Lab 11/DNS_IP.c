#include "DNS_IP.h"

void create(Node *new,char *x,	char *ip , Node* p)
{

	new->n=0;
	new->x=x;
	new->ip=ip;
	new->size=4;
	new->child=malloc(sizeof(Node*)*4);
	new->parent=p;
}
Node* ReadData()
{
	int t;
	scanf("%d",&t);
	Node* root =malloc(sizeof(Node));
	create(root,NULL,NULL,NULL);
	for(int i=0;i<t;i++)
	{
		char* ip=(char*)malloc(sizeof(char)*50);
		char* domain=(char*)malloc(sizeof(char*)*50);
		scanf("%s %s",domain,ip);
	

		char *tokenPtr;
	    char **reverse=malloc(sizeof(char*)*50 );

	    int i=0;  /* counter */
	    tokenPtr = strtok(domain, "." );
		
	    while(tokenPtr != NULL)
	    {  

	            reverse [i++] = tokenPtr;
	 			tokenPtr = strtok(NULL, "." );  /* get next token */
	    }	
			insert(root,reverse,i ,ip);
	}
	return root;
}
void printR(Node* root)
	{
		if(root->ip!=NULL)
		{
			printf("%s\n",root->ip);
		}
		for(int i=0;i<root->n;i++)
			{
				printR(root->child[i]);
				//printf("%s\t",root->child[i]->x);
			}
	}
	
void insert(Node* root,char** domain,int num,char * ip)
{
	Node *temp=root;
	Node *t;

	for(int k=num-1;k>=0;k--)
	{
		
		int level=search_level(temp, domain[k]);

		if(level==-1)
		{
			t =malloc(sizeof(Node));
			//if array got full
			if(temp->n==temp->size)
			{
				int siz=temp->size;
				Node** temp2=realloc(temp->child,sizeof(Node*)*siz*2);
				temp->child=temp2;
			}
			//leaf node
			if(k!=0)
				create(t,domain[k],NULL,temp);

			else
				create(t,domain[k],ip,temp);

			temp->child[temp->n]=t;
			temp->n++;
		}
		else
			t=temp->child[level];
		temp=t;
	}
}

int search_level(Node* parent, char* target)
	{
		if(parent==NULL)
			{printf("error");
			return -5;
			}
		for(int i=0;i<parent->n;i++)
		{
			if(!strcmp(parent->child[i]->x,target))
				return i;
		}
		return -1;
	}
void search(Node* root,char* name )
{
	if(root==NULL)
		return;
	char* tokenPtr=strtok(name,".");
	char* reverse[50];
	int i=0;
	while(tokenPtr!=NULL)
	{
		reverse[i++]=tokenPtr;
		tokenPtr=strtok(NULL,".");
	}
	int l[i];
	Node* temp=root;
	int j;
	for(j=0;j<i;j++)
	{
		l[j]=search_level(temp,reverse[i-j-1]);
		if(l[j]==-1)
		{
			break;
		}
		temp=temp->child[l[j]];

	}
	if(j==i)
	{
		printf("%s\n",temp->ip);
	}
	else
	{
		for(int h=0;h<j;h++)
		{
			printf("%d ",l[h]);
		}
		printf("\n");
	}

}
//void delete()
	
	
	
	
	
	
	
	
		
		
