#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int hash_func(char *s, long long base_Num, int sz);
int collision(char **s, int arr_sz, long long base_Num, int sz)	 ;
//char** parse(FILE* fp,int* arr_sz);
int is_prime(int n);
void profile(char **s,int arr_sz);
char** parse(FILE* infile, int* bookSize);
