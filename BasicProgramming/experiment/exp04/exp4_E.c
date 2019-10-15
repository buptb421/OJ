#include<stdio.h>

int main()
{
    int m, n, x, y;
    scanf("%d%d", &m, &n);
    x = m;
    y = n;
    while((x != 0) && (y != 0))
    {
	if (x > y)
	{
	    x = x % y;
	}
	else
	{
	    y = y % x;
	}
    }
    x = x + y;
    y = m / x * n;
    printf("%d %d\n", x, y);
    return 0;
}
