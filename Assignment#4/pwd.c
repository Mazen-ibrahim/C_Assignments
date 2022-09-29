#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

int main()
{
     char Buf[256];
     char *ret;
     ret = getcwd(Buf,sizeof(Buf));
     if(ret != NULL)
     {
	 printf("Current Working Direcotry is: %s\n",Buf);    
     } 
     else
     {
	    printf("Size of Buffer is not enough");
     }
     
    

    return 0;
}
