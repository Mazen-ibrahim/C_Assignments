#generate Dynamic library

myexe: libRFF.so  FemtoShell.o
	  gcc  FemtoShell.o -o myexe  -lRFF -L.  
           
FemtoShell.o: FemtoShell.c
	  gcc -c FemtoShell.c -I.

libRFF.so: rand.o fib.o fact.o
	  gcc -shared  *.o -o libRFF.so

rand.o: rand.c
	  gcc -c -fPIC rand.c

fib.o: fib.c
	  gcc -c -fPIC fib.c

fact.o: fact.c
	  gcc -c -fPIC fact.c



