#include "bisection.h"


int main(int argc, char* argv[])
{
	char * fileName = argv[1];
    Emp* Em= (Emp*)malloc(sizeof(Emp)*1000);
    int size= read_data(fileName , Em);
    Print_Employee(Em,size);
    /*if(size>10)
    Quick_Sort_Iteraive(Em,0,size-1,1);
    else
    Insertion_Sort_Iterative(Em, size);
    */
  

    double tim[2];
    testRun( Em,tim, size);
    printf("%lf \t %lf\n",tim[0],tim[1]);
    printf("Sorted :\n");
    Print_Employee(Em,size);
}