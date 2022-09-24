void fib(int number, int *sequence)
{ 
 
   int num1 = 0;
   int num2 = 1;
   int next;
   int i;
   for( i  = 0 ;i<number; i++)
   {
     next = num1 + num2;
     num1 = num2;
     num2 = next;
     sequence[i] = next;
   }

}
