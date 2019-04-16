#include"node.h"
#include<stdio.h>
#include<stdlib.h>
#include"list2array.h"
extern int *Arr[N];
extern int Num_Elements[N];
void ConvertListstoArray(Locality *start)
{

for(int i=0;i<N;i++)
{
Num_Elements[i]=start->count;
int hk=Num_Elements[i];
Arr[i]=malloc(sizeof(int)*hk);
Member* temp=start->first;
for(int j=0;j<hk;j++)
{
	Arr[i][j]=temp->id;
	temp=temp->next;
}
start=start->next;
}
}
