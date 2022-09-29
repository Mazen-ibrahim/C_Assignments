#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argn , char *argv[])
{   
    int source_Descriptor , destination_Descriptor, size_Bytes ;
    char *Buf = malloc(sizeof(char)*100);
    source_Descriptor = open(argv[1], O_RDONLY);
    destination_Descriptor = creat(argv[2], O_CREAT|O_WRONLY);	    
    if( source_Descriptor == -1 )
    {
         printf("File Not Exist\n");
               exit(1);
    }
    else
    {   
       size_Bytes = read(source_Descriptor, Buf, sizeof(Buf));
       while( size_Bytes != 0 )
       {       
	    write(destination_Descriptor, Buf, size_Bytes);
	    size_Bytes = read(source_Descriptor, Buf, sizeof(Buf)); 
       }
        
        remove(argv[1]);
        close(source_Descriptor);
        close(destination_Descriptor);	    
	free(Buf);
    }


  
  
   return 0;
}
