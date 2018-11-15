#include<stdio.h>

int reverseNum(int n);

int main()
{
    int number;

    scanf("%d", &number);
    printf("The reverse form of number %d is %d.\n", number, reverseNum(number));
    return 0;
}

int reverseNum(int n)
{
    int reversed = 0;
    
    while(n > 0)
    {	
	reversed = reversed * 10 + n % 10;
	n = n / 10;
    }
    return reversed;
}
