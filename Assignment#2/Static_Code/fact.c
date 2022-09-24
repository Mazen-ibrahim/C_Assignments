int fact(int number)
{  
    if(number > -1)
    {
	 int  res = 1;
	  for(int i = 1; i<=number; i++)
		  res*=i;
	 
	  return res;
	
    }
    else
    {
	    return -1;
    }
}
