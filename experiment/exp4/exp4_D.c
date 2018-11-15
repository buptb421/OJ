#include<stdio.h>

int main()
{
    int a, b, c;
    int i, j;
    int sum, count;
    count = 0;
    scanf("%d%d%d", &a, &b, &c);
    for(i = a; i <= b; i++)
    {
	if(i == 1)
	    continue;
	sum = 1;
	for(j = 2; (j * j) < i && (sum - i) <= c; j++)
	    if((i % j) == 0)
		sum = sum + j + i / j;
	if((j * j) == i)
	    sum = sum + j;
	if((sum - i) <= c && (sum - i) >= -c)
	{
	    count = count + 1;
	    if((count % 5) == 0)
	 	printf("%d\n", i);
	    else
	 	printf("%d\t", i);
	}
    }
    if(count == 0)
	printf("There is no proper number in the interval.");
    return 0;
}
