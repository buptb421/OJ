#include<stdio.h>
#include<math.h>

int reverse(int n)
{
    int sum = 0;
    while(n > 0)
    {
	sum = sum * 10 + n % 10;
	n = n / 10;
    }
    return sum;
}

int constructPalindrome(int n)
{
    if(n <= 9)
	return n;
    else if(n <= 18)
	return 11 * (n - 9);
    else if(n <= 108)
	return (n - 9) * 10 + (n - 9) / 10;
    else if(n <= 198)
	return (n - 99) * 100 + reverse(n - 99);
    else
	return (n - 99) * 100 + reverse((n + 1) / 10 - 10);
}

int getFirstPalindrome(int n)
{
    int sequence;
    if(n < 10)
	sequence = n;
    else if(n < 1000)
	sequence = n / 10 + 9;
    else
	sequence = n / 100 + 99;
    return sequence;
}

int isPalindrome(int n)
{
    int sum = 0;
    while(n > sum)
    {
	sum = 10 * sum + n % 10;
	n = n / 10;
    }
    if(n == sum || n == (sum / 10))
	return 1;
    else
	return 0;
}

int isPrime(int n)
{
    int i, sqrtn;
    sqrtn = sqrt(n);
    if(n % 2)
    {
	for(i = 3; i < n; i = i + 2)
	    if(n % i == 0)
		return 0;
	return 1;
    }
    else
	return 0;
}

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    int temp;
    
    temp = getFirstPalindrome(a);
    if(constructPalindrome(temp) < a)
	a = temp + 1;
    else
	a = temp;

    temp = getFirstPalindrome(b);
    if(constructPalindrome(temp) > b)
	b = temp - 1;
    else
	b = temp;

    for(int i = a; i <= b; i = i + 1)
    {
	temp = constructPalindrome(i);
	if(isPrime(temp))
	    printf("%d\n", temp);
    }
    return 0;
}
