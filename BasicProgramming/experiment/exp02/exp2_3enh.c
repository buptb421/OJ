#include<stdio.h>

int main()
{
    int base, exponent, product, t;
    scanf("%d%d", &base, &exponent);
    product = 1;
    t = 1;
    while(exponent > 0)
    {
	if(exponent % 2 == 1)
	{
	    exponent = exponent - 1;
	    product  = product * base;
	}
	else
	{
	    base = base * base;
	    exponent = exponent / 2;
	    t = t * 2;
	}
	printf("b = %d e = %d p = %d t = %d\n", base, exponent, product, t);
    }
    printf("%d\n", product);
    return 0;
}
