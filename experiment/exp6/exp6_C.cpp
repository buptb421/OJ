#include<stdio.h>

int mypow(int x, int n);

int main()
{
    int x, n;
    scanf("%d%d", &x, &n);
    
    printf("%d\n", mypow(x, n));

    return 0;
}

int mypow(int x, int n)
{
    int temp = 1;
    
    while(n > 0)
    {
	if(n % 2 == 0)
	{
	    x = x * x;
	    n = n / 2;
	}
	else
	{
	    temp = temp * x;
	    n = n - 1;
	}
    }
    
    return temp;
}
