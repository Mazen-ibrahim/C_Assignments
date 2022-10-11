#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>



/************************************************************************
  Name: Struct data                                                     *
  Description: Holds the infotmation of local variables entered by user *
*************************************************************************/
struct data
{
   char name[20];
   char value[20];
};


/****************************************************************************************
  Name: Parse                                                                           *
  Description: Function Used to parse the command line entered by user                  *
  input:                                                                                *
         1-char input[] that hold the command line                                      *
	 2-char *output[] that hold the command line after parse                        *
	 3-delimeter that used by built in function strtok() used to parse data by it   *
                                                                                        *
*****************************************************************************************/
void parse(char input[], char *output[],char delim[])
{

	char *ptr;
       	ptr = strtok(input, delim);
	int k = 0;
        while(ptr != NULL)
	{
		output[k] = ptr;
		ptr = strtok(NULL, delim);
		k++;
	}
	output[k]=NULL;

}

/****************************************************************************************
  Name: checkEqual                                                                      *
  Description: Fucntion Used to check if command line entered is Variable or not        *
  input:                                                                                *
         1-char input[] that hold the command line                                      *
	                                                                                *
*****************************************************************************************/

int checkEqual(char input[])
{
	for(int i = 0 ; i <strlen(input); i++)
	{
		if(input[i] == '=')
		  {return i;}
	}

       return 0;
}


/****************************************************************************************
  Name: checkExport                                                                     *
  Description: Function used to check for export in command line                        *
  input:                                                                                *
         1-char input[] that hold the command line                                      *
                                                                                        *
*****************************************************************************************/

int checkExport (char input[])
{
     if ( input[0] == 'e' && input[1] == 'x' && input[2] == 'p' && input[3] == 'o' && input[4] == 'r' && input[5] == 't')
           return 1;
     else
	   return 0;     
}


int main()
{ 
  
  int counter_variables = 0;
  int Export;
  int equal;
  int j;
  struct data variables[20];
  int id , status , ret;
  char Buf[100];
  char *output[20];

  while(1)
  {

    printf("Ana Gahez ya Basha > ");
    fgets(Buf,100,stdin);
    Buf[strlen(Buf)-1] = 0;
        

         if( strlen(Buf) == 0 )
	      continue;
             



	 //Set command code section
      	 //-----------------------------------------------------------------------------------------------------------
	
	 if( strcmp(Buf,"set") == 0 )
         {
             
            for(int i = 0 ; i<counter_variables; i++)
            {
                 printf("Local variable[%d] is %s = %s \n", i+1 ,  variables[i].name , variables[i].value);
            }
	    continue;

         }
         
         //-----------------------------------------------------------------------------------------------------------


         //Export code section 
         //---------------------------------------------------------------------------------------------------------

            Export = checkExport(Buf);

         if ( Export == 1 )
         {
            char found = 0;
            char success = -1;
            parse(Buf,output," ");
            for(int i = 0 ;i<counter_variables; i++)
             {
                  if ( strcmp(output[1] , variables[i].name) == 0 )
                    {
                       found = 1;
                       success = setenv(variables[i].name,variables[i].value,1);
                       if( success == 1 )
                               printf("Variable set to enviroment variables\n");

                        break;
                    }
             }

           if(found == 0)
               printf("Variable not found\n");

            continue;
         }

         //----------------------------------------------------------------------------------------------------------

         
	 //Add variable code section
	 //-----------------------------------------------------------------------------------------------------------
        
	   equal = checkEqual(Buf);
           j = 0;

	 if ( equal > 0)
         {
            for(int i = 0 ;i<strlen(Buf); i++)
	    {  
              if( i < equal ) 
	      {
		   variables[counter_variables].name[i] = Buf[i];
	      }
	      else
	      {  
                 variables[counter_variables].name[i] = '\0';
	       	 variables[counter_variables].value[j]  = Buf[i+1];
		 j++; 
	      }

	    }
         
            variables[counter_variables].value[j] = '\0'; 
            counter_variables++;
	    continue;
         }

	 //------------------------------------------------------------------------------------------------------------


    id = fork();

    if( id < 0 )
	printf("Fork Failed\n");
    
    else if ( id > 0 )   //Parent process
    {  
       
       wait(&status);   	    
    }

    else if (id == 0 )   //child process
    {      
	   printf("%s\n",Buf);
           parse(Buf,output," ");
           ret = execvp(output[0],output);
           if ( ret == -1 )
	     printf("Failed to exec\n"); 
	
     }

                 
  }


}

