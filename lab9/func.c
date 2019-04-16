#include "func.h"

int hash_func(char *s, long long base_Num, int sz)
{	
	int res;
	int j=0;
	while(j!=strlen(s))
	{
		 res+=(int)s[j];
		 j++;
	 }
	return (res%base_Num)%sz;
}	 

int collision(char **s, int arr_sz, long long base_Num, int sz)	 
{
	int c=0;
	int a[sz];
	for (int i=0;i<sz;i++)
	{
		a[i]=0;
	}
	for (int i=0;i<arr_sz;i++)
	{
		int z=hash_func( s[i],  base_Num,  sz);
		a[z]+=1;
		if(a[z]==2)
		{
			c++;
		}
		
	} 
	
	return c;
}
char** parse(FILE* infile, int* bookSize)
{
	//FILE* infile = fopen(input, "r");
	char** book;
	book = (char**)malloc(sizeof(char*) * 100);
	int size =100;
	int i=0, f=0;
	//book[i] = (char*)malloc(sizeof(char)*50);
	while(!feof(infile))
	{
		book[i] = (char*)malloc(sizeof(char)*50);
		fscanf(infile, "%s", book[i]);
		//printf("%s %d.\n", book[i], i);
		f=0;
		for(int j=0; j< strlen(book[i]); j++)
		{
			if (!((book[i][j]>='a' && book[i][j]<='z') ||(book[i][j]>='A' && book[i][j] <= 'Z')))
			{
				f=1;
				//printf("f=1 at %d %d %c %s\n", i, j, book[i][0], book[i]);
				break;
			}
			
		}
		if (f==0)
		{
			i++;
		}
		if ( i== size-1){
			size *= 2;
			book = (char**)realloc(book, sizeof(char*) * size);
		}
	}
	*bookSize = i;
	printf("bookSIze is: %d\n", *bookSize);
	return book;
}/*
char** parse(FILE* fp,int* a_sz)
{	
	long long  sz=100000000;
	char** arr= (char**) malloc(sz*sizeof(char*));

	int arr_sz=0;
	int buff=1000;
	arr[arr_sz]=malloc(sizeof(char)*50);
	while(fscanf(fp,"%[^\n\t ]", arr[arr_sz++] )!=EOF){
			arr[arr_sz]=malloc(sizeof(char)*50);

	}
	/*{
	
		fgets(arr[arr_sz++], buff, fp);
	}
	
	printf("%d\n",arr_sz);
	*a_sz=arr_sz;
	return arr;
}
*/
int is_prime(int n)
{
	if(n%2==0)
		return 0;
	for(int i=3;i<n/2;i+=2)
	{
		if(n%2==0)
		return 0;
	}
	return 1;
}
	
void profile(char **s, int arr_sz)
{
	int min=0;
	int base_m;
	int t_m;
	for(int t=5000;t!=500000;t*=10)
	{
		int count=0;
		for(int  i=t+1; i<2*t && count<3;i++)
		{
		 	if(is_prime(i))
		 	{
		 		count++;
		 		int h=collision(s, arr_sz,i,t);
		 		printf("%d\n",h);
		 		if(min==0|| min>h)
		 		{	
		 			min=h;
		 			base_m=i;
		 			t_m=t;
		 		}	
		 	}
		 }
		 count =0;
		 for(long long i=1000*t;count<3;i++)
		 {
		 	if(is_prime(i))
		 	{
		 		count++;
		 		int h=collision(s, arr_sz,i,t);
		 		printf("%d\n",h);
		 		if(min==0|| min>h)
		 		{	
		 			min=h;
		 			base_m=i;
		 			t_m=t;
		 		}	
		 			
		 			
		 	}
		 }	
	}
	printf("Min:%d %d",base_m, t_m);
			
}	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
		
		
