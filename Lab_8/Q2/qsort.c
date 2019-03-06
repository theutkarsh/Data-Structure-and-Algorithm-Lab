#include "qsort.h"
int Counting_Sort( int* A, int* B,int lokey,int hikey, int sz);
void printArray(int* studArray, int arrSize)
{
	// printing the array
	int i = 0;
	for(i=0;i<arrSize;i++)
	{
		printf("Arr[%d] is %d\n", i, studArray[i]);
	}
}

int* readData(char * fileName)
{
	 FILE* file = fopen (fileName, "r") ;
  	int i = 0;
	
	char s1[10];
  	fscanf (file, "%d", &i);
	size=i; 
	int j=0;
	int* a= malloc(sizeof(int)*i);
	while (!feof (file))
{           
	
	fscanf (file, "%s %d", s1, a+j);
	j++;
  }

return a;
}


KeyStruct extractKeys(int* Ls, int lsSize, int loKey, int hiKey)
{
	
	KeyStruct ks=(KeyStruct)malloc(sizeof(struct keyStruct));
	ks->Keys=(int*)malloc(sizeof(int)*lsSize);
	ks->keysSize=Counting_Sort(Ls,ks->Keys, loKey,hiKey,lsSize);
	return ks;
}

int Counting_Sort( int* A, int* B,int lokey,int hikey, int sz)
{
int r=hikey-lokey+1;
int C[hikey+1];
for(int i=lokey;i<hikey+1;i++)
{
	C[i]=0;
}	

for(int i=0;i<sz;i++)
{
	C[A[i]]=1;
}
int j=0;
for(int i=lokey;i<hikey+1;i++)
{
	if(C[i]==1)
	B[j++]=i;
}


return j;
}



int part2Loc(int* Ls, int lo, int hi, int piv)
{

	int flag=0;
    int i = lo;     // place for swapping
    for(int j = lo; j<hi ;j++)
	{ 
	if (Ls[j]==piv && flag==0)
	{
		int tem=Ls[j];
		Ls[j]=Ls[hi];
		Ls[hi]=tem;	
		j--;
		flag=1;
	}
	else if (Ls[j] <= piv) 
	{
		int tem=Ls[i];
		Ls[i]=Ls[j];
		Ls[j]=tem;         
		i++;
	}
	}
	int tem=Ls[i];
	Ls[i]=Ls[hi];
	Ls[hi]=tem;
	return i;

//Partition Pseudo code	
 /*
	partition(arr[], lo, hi) 
    pivot = arr[hi]
    i = lo     // place for swapping
    for j := lo to hi – 1 do
        if arr[j] <= pivot then
            swap arr[i] with arr[j]
            i = i + 1
    swap arr[i] with arr[hi]
    return i
*/
 

}

 void quickSortKnownKeyRange(int * Ls, int size, int loKey, int hiKey)
{
	KeyStruct ks= extractKeys(Ls, size, loKey,hiKey);
	for(int i=0;i<ks->keysSize-1;i++){
	int l=0;
	l= part2Loc( Ls, l,size  , ks->Keys[i]);
	l++;
}	
}



		
