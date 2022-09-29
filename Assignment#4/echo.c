#include<stdio.h>

int main(int argn ,char*argv[])
{    
     for(int i = 1; i<argn; i++)
         printf("%s ",argv[i]);
     
     printf("\n");
} 
