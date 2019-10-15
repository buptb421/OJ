#include<stdio.h>

void InsertSort(int a[],int n);

int main()
{
    int n, a[1000];
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
	scanf("%d", &a[i]);

    for(int i = 2; i <= n; i++)
    {
	InsertSort(a, i);
	for(int j = 0; j < n; j++)
	    printf("%d ", a[j]);
	printf("\n");
    }
    
    return 0;
}

void InsertSort(int a[],int n)
{
    int i, temp = a[n - 1];
    for(i = n - 1; a[i - 1] > temp && i > 0; i--)
	a[i] = a[i - 1];
    a[i] = temp;
}
