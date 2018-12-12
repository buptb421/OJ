#include<stdio.h>

void recurePrintFactor(int n, int sf)//suspected factor
{
    for(int i = sf; i <= n; i = i + 1 + (i != 2))
    {	
	if(n % i == 0)
	{
	    n = n / i;
	    printf("%d", i);
	    if(n == 1)
		printf("\n");
	    else
	    {
		printf("*");
		return recurePrintFactor(n, i);
	    }
	}
    }
}	

void printWhole(int n)
{
    
    printf("%d=", n);
    if(n == 1)
	printf("1\n");
    else
	recurePrintFactor(n, 2);
}

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    for(int i = a; i <= b; i = i + 1)
	printWhole(i);
    return 0;
}
