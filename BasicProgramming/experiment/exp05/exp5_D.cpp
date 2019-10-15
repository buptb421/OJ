#include<stdio.h>

int cons1(int n)
{
    int sum = 0;
    int t1, t2;
    int max;
    
    for(int i = 1; i <= n / 3; i = i + 1)
    {
	t1 = 2 * i;
	t2 = n / 2 + 1;
	if(t1 > t2)
	    sum = sum + n - (n - i + 1) / 2 - t1 + 1;
	else
	    sum = sum + n - (n - i + 1) / 2 - t2 + 1;
    }
    return sum;
}

int cons2(int n)
{
    int a = n / 2;
    int b = n / 3;
    int c = (a + 1) / 2;
    int d = c / 2;
    int e = (n + 1) / 2;
    int f = b - c;
    return c * (n - 1 + e) + b - d - c * (c - 1) / 2 - (b + c - n) * (f + 1) + (c - b) / 2 - (c % 2) * (n % 2) - ((n - c) % 2) * ((f + 1) % 2);
}

int main()
{
    int temp1, temp2;
    for(int i = 1; i <= 1000; i = i + 1)
    {
	temp1 = cons1(i);
	temp2 = cons2(i);
	if(temp1 != temp2)
	    printf("%d\t%d\t%d\n", i, temp1, temp2);
    }
}
