Clerk : Clerk.o
	gcc Clerk.o -o Clerk

Clerk.o : Clerk.c clerkClient.h database.c interface.c procedure.c page.c
	gcc Clerk.c -c

.PHONY : clean

clean :
	rm Clerk.o Clerk
