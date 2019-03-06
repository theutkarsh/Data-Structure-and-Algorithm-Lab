#include "bisection.h"

double* testRun(Emp* Ls,double* tim,int size) {
    clock_t start, end;
  
     start = clock();
     Quick_Sort_Iteraive(Ls,0,size-1,1);

     end = clock();
     tim[0] =( (((double) (end - start))/CLOCKS_PER_SEC)*1000.0); 

     
     Emp newarr[size]; // create new array
	for(int i=0;i<size;i++)
		newarr[i]=Ls[i];
    start = clock();
     Insertion_Sort_Iterative(newarr,size);
     end = clock();
     tim[1] =( (((double) (end - start))/CLOCKS_PER_SEC)*1000.0); 
    return tim;
}
  
/*

define estimateCutoff {
tt1 = testRun(Ls, min); // assert tt1.IStime < tt1.QStime
tt2 = testRun(Ls, max); // assert tt1.IStime > tt1.QStime
repeat { mid =(min+max)/2;
tt = testRun(Ls, mid);
use tt to narrow the range (i.e. min=mid or max=mid)
} (until tt.IStime approximately== tt.QStime)
return mid;
}
double measureSortingTime(Emp* list)
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



int estimateCutoff(Employee arr[], int n){
	double results[2];

	Employee newarr[n];

	int min=0;
	int max=n;

	int mid=(min+max)/2;
	int prevmid = -1;

	double resultleft,resultcenter,resultright;

	while(mid!= prevmid){
		prevmid = mid;
		fflush(stdout);
		for(int i=0;i<(min+mid)/2;i++){ //we're only sorting the first "mid" elements anyway, so there's no point copying more than that
			newarr[i]=arr[i];
		}
		// I assume that a plot of abs(IStime-QStime) will be U-shaped, with a well defined minumum
		testRun(newarr, (min+mid)/2, results);
		resultleft=fabs(results[0]-results[1]);
		
		for(int i=0;i<mid;i++){ //we're only sorting the first "mid" elements anyway, so there's no point copying more than that
			newarr[i]=arr[i];
		}
		testRun(newarr, mid, results);
		resultcenter=fabs(results[0]-results[1]);
		
		for(int i=0;i<(mid+max)/2;i++){ //we're only sorting the first "mid" elements anyway, so there's no point copying more than that
			newarr[i]=arr[i];
		}
		testRun(newarr, (mid+max)/2, results);
		resultright=fabs(results[0]-results[1]);

		printf("mid is %d, %lf,%lf,%lf\n",mid,resultleft,resultcenter,resultright);

		if(resultcenter<=resultleft && resultcenter <= resultright){
			//We've found our minimum
			return mid;
		}
		else{
			if(resultleft<=resultcenter){
				max = mid; //go left
			}
			else{
				min = mid;
			}
		}
		mid = (min+max)/2;
	}
	return mid; //mid is equal to prevmid, so return mid
}*/