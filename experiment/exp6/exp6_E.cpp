#include<stdio.h>

int isPerfect(int n);
void printPerfect(int n);

int main()
{
    int a, b;    
    scanf("%d%d", &a, &b);

    int count = 0;
    for(int i = a; i <= b; i = i + 1)
    {
	if(isPerfect(i))
	{
	    printPerfect(i);
	    count = count + 1;
	}
    }

    printf("The total number is %d.", count);
    
    return 0;
}

int isPerfect(int n)
{
    int temp = 0;
    for(int i = 1; i <= n; i = i + 1)
	if((n % i) == 0)
	    temp = temp + i;
    
    if((2 * n) == temp)
	return 1;
    else
	return 0;
}

void printPerfect(int n) // Actually just list the factors.
{
    printf("%d=1", n);
    for(int i = 2; i < n; i = i + 1)
	if((n % i) == 0)
	    printf("+%d", i);
    printf("\n");
}
