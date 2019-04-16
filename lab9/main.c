#include "func.h"

int main(int argc, char* argv[])
{
	FILE* fp=fopen(argv[1],"r");
	int* arr_sz=malloc(sizeof(int));
	
	char** arr=parse(fp,arr_sz);
	int b=*arr_sz;
	profile(arr, b);

}
	
	
