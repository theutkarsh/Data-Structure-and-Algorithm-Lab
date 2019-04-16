#include"node.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//2016581p
Locality * ReadFileintoLists(char *filename)
{
	Locality* lo=(Locality*)malloc(sizeof(Locality));
	Locality* templ=lo;
		Locality* templ2;
	FILE *file =fopen(filename, "r");
	for(int i=0;i<N;i++)
	{
	templ->first=(Member*)malloc(sizeof(Member));
	templ->next=(Locality*)malloc(sizeof(Locality));
	fscanf(file,"%d",&templ->count);
	Member* temp=templ->first;
	Member* temp2;
	for(int j=0;j<templ->count;j++)
	{
		fscanf(file,",%d",&temp->id);
		temp->next=(Member*)malloc(sizeof(Member));
		temp2=temp;

		temp=temp->next;

	}
	char c;
	//fscanf(file,"\n",&c);
	temp2->next=NULL;
	templ2=templ;
	templ=templ->next;
	}
	templ2->next=NULL;
	fclose(file);
	return lo;
	
}

void PrintLists (Locality *start)
{
	Locality* templ=start; 
	while(templ!=NULL)
	{

				int nu=templ->count;
				Member* temp=templ->first;
		for(int j=0;j<nu;j++)
		{
			printf("%d\t ",temp->id);
			temp=temp->next;
		}
		printf("\n");
		templ=templ->next;
	}	

}
