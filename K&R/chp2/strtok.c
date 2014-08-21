#include<string.h>
#include<stdio.h>

int main(void)
{
    char input[16]="a,b";
    char *p;
    p=strtok(input,",");
    if(p) printf("s:%s, p:%s\n",s, p); //s:a, p:a

    p=strtok(NULL,","); 
    if(p) printf("s:%s, p:%s\n",s, p); //s:a, p:b
    
    return 0;
}

