#include<stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    n = n + 1;
    long long product = 1;
    for(int i = 2; i <= n; i = i + 1)
	product = product * 2 / i * (2 * i - 1);
    printf("%lld\n", product);
    return 0;
}
