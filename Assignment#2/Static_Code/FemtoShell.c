/*
  Description: This code used to echo any sentence you enter.
  used function: printf() , malloc(), strcmp() , free().
  Terminate command : exit    

*/



#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "RFF.h"

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
       
	else if( strcmp(Buffer,"rand\n") == 0)
        {    
	      unsigned int res;
	      res = Random();
	      printf("%d\n",res);
	}

	else if( strcmp(Buffer,"fib\n") == 0)
	{     
	      int number;
	      int i;
              printf("Enter a Number: ");
	      scanf("%d",&number);
	      int *sequence = (int*)malloc(sizeof(int)*number);
	      fib(number,sequence);
	      printf("0 1 ");
	      for( i = 0 ;i<number; i++)
	      {
		  printf("%d ", sequence[i]);
	      }
	     
	      printf("\n");
	      free(sequence); 
	      while(getchar() != '\n');

	}

       else if( strcmp(Buffer,"fact\n") == 0 )
        {     
	      int number, returnValue;
	      printf("Enter a Number: ");
              scanf("%d",&number);	      
	      returnValue = fact(number);
	     
	      if ( returnValue != -1)
	      {printf("Result: %d\n",returnValue);}
	      else
	      {printf("Invalid Number\n");}

	      while(getchar() != '\n');
	}

        else 
	{ 
          printf("You said : %s" , Buffer);
       
       	}

    
  }

}

