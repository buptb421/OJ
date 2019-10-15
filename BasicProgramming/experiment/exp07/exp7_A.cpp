#include<stdio.h>

int convert(int n)
{
    if(n > 0)
	return n % 10 + 2 * convert(n / 10);
    else
	return 0;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", convert(n));
    return 0;
}
