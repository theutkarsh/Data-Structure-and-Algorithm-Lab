#include<stdio.h>
#include"node.h"
#include"readdata.h"
#include"list2array.h"
#include"insertion.h"
extern int * Arr[N];
extern int Num_Elements[N];


void PrintArr()
{
  for(int i=0; i<N; i++)
  {
     for(int j = 0; j < Num_Elements[i]; j++)
       printf(" %d ", Arr[i][j]);
     printf("\n");
  }
}

int main(int argc, char* argv[])
{
	Locality * l= ReadFileintoLists(argv[1]);
	//PrintLists (l);
	ConvertListstoArray(l);
	InsertionSort_Arr();
	PrintArr();
	
}
  

  
