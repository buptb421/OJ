#include<stdio.h>
#define BINARY_SEARCH_LENGTH_MIN 5
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
    for(nSeg = 0; end >= sta && nSeg < m; end--)
    {
	nSeg = septest(end, n);
//	printf("%lld %d\n", end, nSeg);
    }
    printf("%lld\n", end + 1);
    
    return 0;
}

int septest(long long testlen, int n)
{
    int sum = 0;
    for(int i = 0; i < n; i++)
	sum += string[i] / testlen;
    return sum;
}

void binaryS(long long *i, long long *j, int n, int m)
{
    while((*j - *i) >= BINARY_SEARCH_LENGTH_MIN)
    {
	if(septest((*i + *j) / 2, n) >= m)
	    *i = (*i + *j) / 2;
	else
	    *j = (*i + *j) / 2;
    }
}
