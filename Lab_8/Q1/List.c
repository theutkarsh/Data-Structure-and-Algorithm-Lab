#include "List.h"

List createList(Student studArray, int arraySize)
{
	List St;
	St=(List)myalloc(sizeof(struct list));
	St->first=(Node)malloc(sizeof(struct node));
	Node temp=St->first;
	Node temp2;
	for(int i=0;i<arraySize;i++)
	{
		temp->record=&studArray[i];
		 temp2=temp;
		
		temp->next=(Node)malloc(sizeof(struct node));
		temp=temp->next;
		St->count++;
	}
	temp2->next=NULL;
	St->last=temp2;	
	return St;
}
void insertInOrder(List list, Node newNode)
{
if(list!=NULL){
	Node temp=list->first;

	if( temp==NULL|| temp->record->marks >newNode->record->marks)
	{

		list->first=newNode;
		newNode->next=temp;
		list->count++;
	
	}
	else{
	while(temp->next!=NULL &&temp->next->record->marks<newNode->record->marks )
	{
	temp=temp->next;
	}
	Node temp2=temp->next;
	temp->next=newNode;
	newNode->next=temp2;
	list->count++;
	if(temp2==NULL)
	{
		list->last=newNode;
	}
	}
}
	
}

List insertionSort(List list)
{
	if(list!=NULL){
	Node temp=list->first;
	if(temp!=NULL){
	int c=list->count;
	Node temp2=temp->next;
	temp->next=NULL;
	Node newNode;
	for(int i=1;i<c;i++)
	{
		Node newNode=temp2;
		if(temp2->next!=NULL)
		temp2=temp2->next;
		newNode->next=NULL;
	
		insertInOrder( list,  newNode); 
	
	}
	list->last=newNode;
	return list;
}
}	
}	
	
double measureSortingTime(List list)
{

     clock_t start, end;
     double cpu_time_used;
     
     start = clock();
     list = insertionSort(list);

     end = clock();
     cpu_time_used =( (((double) (end - start))/CLOCKS_PER_SEC)*1000.0); 
     myfree(list);
	 return  cpu_time_used;
	
}

void * myalloc(int size)
{
	int *ptr=malloc(sizeof(int)+size);
	*ptr=size;
	globalCounter+=size;
	return (void*)(ptr+1);
}
	
	
void myfree(void* ptr)
{
	int s=*((int*)ptr-1);
	globalCounter-=s;
	free((void*)((int*)ptr-1));
}

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
