#include"DNS_IP.h"

int main(void)
{
    Node* root;
    int in;
    scanf("%d",&in);
    do{
        if(in==-1)
            return 0;
        else if(in==1)
            root=ReadData(); 
          //Prints all ip   
        else if(in==3)
            printR(root);
        else if(in==2)
        {
            char* domain=malloc(sizeof(char)*100);
            scanf("%s",domain);
            search(root,domain);
        }
        scanf("%d",&in);
    }
    while(in!=-1);
}
