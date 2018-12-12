#include <stdio.h>

int main()
{
	int base, exponent, product;
	product = 1;
	scanf("%d%d", &base, &exponent);
	while (exponent > 0)
	{
		product = product * base;
		exponent = exponent - 1;
	}
	printf("%d\n", product);
	return 0;
}
