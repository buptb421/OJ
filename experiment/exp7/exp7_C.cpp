#include<stdio.h>

void recurePrintFactor(int n)
{
    for(int i = 2; i <= n; i = i + 1)
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
		return recurePrintFactor(n);
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
	recurePrintFactor(n);
}

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    for(int i = a; i <= b; i = i + 1)
	printWhole(i);
    return 0;
}
