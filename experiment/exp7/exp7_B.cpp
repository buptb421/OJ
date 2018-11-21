#include<stdio.h>

int GCD(int a, int b)
{
    static int remainder;
    remainder = a % b;
    
    if(remainder == 0)
	return b;
    else
	return GCD(b, remainder);
	
}

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n", GCD(a, b));
    return 0;
}
