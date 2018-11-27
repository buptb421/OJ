#include<stdio.h>

long long GCD(long long a, long long b)
{
    if(a == 0)
	return b;
    else
	return GCD(b % a, a);
}

void elimination(long long *up, long long *down)
{
    long long com = GCD(*up, *down);
    *up = *up / com;
    *down = *down / com;
}

int main()
{
    int n;
    scanf("%d", &n);
    
    long long up = 1, down = 1;
    long long i, j;
    for(i = n + 2, j = 1; j <= n; i++, j++)
    {
	/*
	up = up * i;
	down = down * j
	*/
	long long multi_up = i, multi_down = j;

	elimination(&up, &down);
	elimination(&up, &multi_down);
	elimination(&multi_up, &down);
	elimination(&multi_up, &multi_down);
	up = up * multi_up;
	down = down * multi_down;
    }
    printf("%lld\n", up);
    return 0;
}
