#include"Employee.h"

int read_data(char* fileName, Emp* Em)
{
    FILE* file = fopen (fileName, "r") ;
    if(file!=NULL){
    int i=0;
    while(!feof(file)){
        fscanf(file,"%s %d\n",Em[i].name,&Em[i].empID);
        i++;
    }
    
    return i;
    }
    return 0;
} 

void Print_Employee(Emp* Em,int size)
{
    for(int i=0;i<size ;i++)
    {
        printf("%s \t %d\n",Em[i].name,Em[i].empID);
    }

}