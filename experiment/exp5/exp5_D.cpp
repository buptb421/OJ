#include<stdio.h>

int main()
{
    int n;
    int sum = 0;
    int t1, t2;
    int max;
    
    scanf("%d", &n);
    for(int i = 1; i <= n / 3; i = i + 1)
    {
	t1 = 2 * i;
	t2 = n / 2 + 1;
	if(t1 > t2)
	    sum = sum + n - (n - i + 1) / 2 - t1 + 1;
	else
	    sum = sum + n - (n - i + 1) / 2 - t2 + 1;
    }
    printf("%d\n", sum);
    return 0;
}
