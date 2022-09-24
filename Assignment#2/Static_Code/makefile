#generate static library 

myexe: libRFF.a  FemtoShell.o
	gcc  FemtoShell.o -o myexe  -lRFF -L.  

FemtoShell.o: FemtoShell.c
	  gcc -c FemtoShell.c -I.

libRFF.a: rand.o fib.o fact.o
	  ar -rs libRFF.a  *.o

rand.o: rand.c
	  gcc -c rand.c

fib.o: fib.c
	  gcc -c fib.c

fact.o: fact.c
	  gcc -c fact.c



