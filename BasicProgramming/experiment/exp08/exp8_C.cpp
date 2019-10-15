#include<stdio.h>

int* inputArray(int *p, int n)// Return end + 1
{
    for(int i = 1; i <= n; i = i + 1, p = p + 1)
	scanf("%d", p);
    return p;
}
/*
void outputArray(int *p, int n)
{
    for(int i = 1; i < n; i = i + 1, p = p + 1)
	printf("%d ", *p);
    printf("%d\n", *p);
}
*/
int* countPlatform(int *p, int *end, int *countPlatformLength)// return end + 1 
{
    int count = 0;
    int record =  *p;
    while(*p == record && p != end)
    {
	p = p + 1;
	count = count + 1;
    }

    *countPlatformLength = count;
    return p;
}

int main()
{
    int n;
    int a[1000];
    scanf("%d", &n);

    int *end = inputArray(a, n);
    int *p = a;
    int length, max = 0;
    while(end != p)
    {
	p = countPlatform(p, end, &length);
	if(length > max)
	    max = length;
    }

    printf("%d\n", max);
    return 0;
}
