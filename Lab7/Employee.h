#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[10];
    int  empID;
}Emp;

int read_data(char* fileName, Emp* Em);
void Print_Employee(Emp* Em,int size);
