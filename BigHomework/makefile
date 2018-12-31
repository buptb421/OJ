debugprog : debugprog.o
	gcc debugprog.o -o debugprog

debugprog.o : debugprog.c clerkClient.h database.c interface.c
	gcc debugprog.c -c

.PHONY : clean

clean :
	rm debugprog.o debugprog
