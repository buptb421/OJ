#include<stdio.h>

long long string[10000];

int septest(long long testlen, int n);
void binaryS(long long *i, long long *j, int n, int m);

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    for(int i = 0; i < n; i++)
    {
	scanf("%lld", &string[i]);
    }

    long long sta = 1, end = 2000000;
    binaryS(&sta, &end, n, m);
    int nSeg;
    for(nSeg = 0; end > sta && nSeg < m; end--)
      nSeg = septest(end, n);
    printf("%lld\n", end);
    
    return 0;
}
3
int septest(long long testlen, int n)
{
    int sum = 0;
    for(int i = 0; i < n; i++)
	sum += string[i] / testlen;
    return sum;
}

void binaryS(long long *i, long long *j, int n, int m)
{
    while((*j - *i) > 8)
    {
	if(septest((*i + *j) / 2, n) >= m)
	    *i = (*i + *j) / 2;
	else
	    *j = (*i + *j) / 2;
    }
}
