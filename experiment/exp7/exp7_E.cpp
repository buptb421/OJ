#include<stdio.h>

int getx2(int xn, int n)
{
    int sum = 0;
    for(int pow = 1; xn > 0; xn = xn / 10, pow = pow * n)
	sum = sum + (xn % 10) * pow;
    return sum;
}

int numConvert(int x2, int m)
{
    if(x2 < m)
	return x2;
    else
	return (x2 % m) + 10 * numConvert(x2 / m, m);
}

int main()
{
    int xn, n, m;
    scanf("%d%d%d", &xn, &n, &m);
    printf("%d\n", numConvert(getx2(xn, n), m));
    return 0;
}
