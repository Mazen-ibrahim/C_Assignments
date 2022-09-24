/*
  Description: This code used to echo any sentence you enter.
  used function: printf() , malloc(), strcmp() , free().
  Terminate command : exit    

*/



#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{ 
  size_t BufferSize = 128;	
  char *Buffer = (char*)malloc(sizeof(char)*BufferSize);
  
  while(1)
  {      
	 printf("Yalla Ana Gahez> ");
         getline(&Buffer,&BufferSize,stdin);
         
	if( strcmp(Buffer,"exit\n") == 0 )
	 {   
		 printf("Good Bye\n");
		 free(Buffer);
		 exit(1);
	 }
	 else
	 {
		 printf("You said: %s",Buffer);
	 }


  }

}

