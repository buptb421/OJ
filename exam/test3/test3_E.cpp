#include<stdio.h>

long long string[10000];

int septest(long long testlen, int n);
long long findMaxSep(long long len, int n, int m);
long long improve(long long len, int add);

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    long long max = 100;
    for(int i = 0; i < n; i++)
    {
	scanf("%lld", &string[i]);
    }

    long long estimate = 0;
    for(int i = 0; i < n; i++)
	estimate += string[i] / m;

    if(septest(estimate, n) > m)
    {

    }
    else if(septest)
    
    printf("%lld\n", findMaxSep(estimate, n, m));
    
    return 0;
}

int septest(long long testlen, int n)
{
    int sum = 0;
    for(int i = 0; i < n; i++)
	sum += string[i] / testlen;
    return sum;
}

int binaryS(long long i, long long j)
{
    while(j - i > 100 && ((i + j) / 2))
}
