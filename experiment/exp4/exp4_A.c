#include<stdio.h>

int main()
{
    long n, oct;
    int i, digit, started; 
    scanf("%ld", &n);
    oct = 1000000000;
    started = 0;
    for(i=0; i < 9; i++)
    {
	oct = oct/10;
	digit = n / oct;
	if(digit == 0 && started == 0)
	    continue;
	else
	{
	    if(started == 0)
		started = 1;
	    printf("%d", digit);
	    if(i == 8)
		printf("\t");
	    else
		printf(" ");
	    n = n % oct;
	}
	    
    }
    return 0;
}
	
