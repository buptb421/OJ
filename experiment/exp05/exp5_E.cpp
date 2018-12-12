#include<stdio.h>

// Through a quick research, it is clear that under previous data scale, only 3, 5, 7, 11, 13 are capable of been eliminated. However, this version won't consider such thing.

int main()
{

    int n;
    scanf("%d", &n);
    
    long long up = 0, down = 1;
    

    int prime[12] = {3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};// Actually this can be generated by programme. However, n + 2 is under 41.
    int s[12] = {0};// Number up bound of prime factors in a single "i" in upper part "_S_ingle"
    int count, temp;
    // Calc down(by prime factors)
    for(int i = 1; i <= (n + 2); i = i + 2)
    {
	temp = i;
	for(int j = 0; j < 12; j = j + 1)
	{
	    count = 0;
	    while((temp % prime[j]) == 0)
	    {
		temp = temp / prime[j];
		count = count + 1;
	    }
	    if(count > s[j])
		s[j] = count;
	}
    }
/*
    for(int i = 0; i < 12; i++)
	printf("%d\t%d\t%d\n", prime[i], a[i], s[i]);
*/	
    for(int j = 0; j < 12; j = j + 1)
	for(int k = 1; k <= s[j]; k = k + 1)
	    down = down * prime[j];

    for(int j = 1; j <= n; j = j + 2)
	up = up + down / (j + 2) * j ;
    
    printf("%lld/%lld\n", up, down);
    return 0;
}
	

    // This is used to test the bound of data during pre-development.
/*
    for(int i = 1; i < n; i = i + 2)
    {
	temp = 1;
	for(int j = 1; j < n; j = j + 2)
	{
	    if(j == (i + 2))
	    {
		temp = temp * i;
		printf("%d ", i);
	    }
	    else
	    {
		temp = temp * j;
		printf("%d ", j);
	    }
	}
	printf("\n%lld\n\n", temp);
	up = up + temp;
    }
    printf("%lld\n", up);
    return 0;
}
*/