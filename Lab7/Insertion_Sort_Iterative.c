#include "Insertion_Sort_Iterative.h"

void Insertion_Sort_Iterative(Emp* Employee,int size)
{
    for(int i=1;i<size;i++)
    {
        Emp temp=Employee[i];
        int j=i-1;
        
        while(j>=0 && Employee[j].empID>temp.empID )
        {
            swap(Employee,j+1,j);
            j--;
        }
        Employee[j+1]=temp;
        
    }
}