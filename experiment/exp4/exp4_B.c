#include<stdio.h>

int main()
{
    int n;
    int i, j, k;
    int symm;
    int prime;
    scanf("%d", &n);
    if(n == 4)
	printf("2 and 2");
    else
    {
	for(i = 3; i <= (n / 2); i = i + 2)
	{
	    prime = 0;
	    symm = n - i;
	    for(j = 3; (j * j) <= i; j = j + 2)
	    {
		if((i % j) == 0)
		{
		    prime = 1;
		    break;
		}
	    }
	    for(k = 3; (k * k) <= symm; k = k + 2)
	    {
		if((symm % k) == 0)
		{
		    prime = 1;
		    break;
		}
	    }
	    if(prime == 0)
		printf("%d and %d\n", i, symm);
	}
    }
    return 0;
}
