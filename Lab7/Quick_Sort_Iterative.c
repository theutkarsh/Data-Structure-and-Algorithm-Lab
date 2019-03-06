#include"Quick_Sort_Iterative.h"


void swap(Emp* em,int i,int j)
{
    Emp temp=em[i];
    em[i]=em[j];
    em[j]=temp;
}
int partition(Emp* Ls, int lo, int hi)
{
    int piv=Ls[hi].empID;
    int i = lo;     // place for swapping
    for(int j = lo; j<hi ;j++)
	{ 
	if (Ls[j].empID <= piv) 
	{
		swap(Ls,i,j) ;   
		i++;
	}
	}
	swap(Ls,i,hi);
	return i;


}
void Quick_Sort_Iteraive(Emp* Em, int low,int hi, int S)
{
    Stack* St = createStack(10);
    push(St,low,hi);

    while(St->top>=0)
    {
        int i=pop(St);
        low=St->l[i];
        hi=St->h[i];
        int pv=partition(Em,low,hi);
        if((pv-low)>S &&  (pv-low)>1 )
        {
            push(St,low,pv-1);

        }
        if((hi-pv)>S && (hi-pv)>1)
        {
            push(St,pv+1,hi);
        }
    }


}
