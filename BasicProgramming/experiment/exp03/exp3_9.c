#include<stdio.h>

int main()
{
    int n,m;
    int temp, SquareSum;
    int i,j;
    int count;
    int digit;
    scanf("%d%d", &n, &m);
    count = 0;
    
    // 1 -- 10000
    for(i = 1; i <= n; i = i + 1)
    {
	temp = i;
	SquareSum = 0;
	for(j = 0; j < 4; j = j + 1)
	{
	    digit = temp % 10;
	    temp = temp / 10;
	    SquareSum = SquareSum + digit * digit;
	}
	if ((i / m) == SquareSum)
	{
	    count = count +1;
	    printf("%d", i);
	    if((count % 5) == 0)
		printf("\n", i);
	    else
		printf("\t", i);
	}
    }
    return 0;
}
