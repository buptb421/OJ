#include<stdio.h>

void outputArray(int a[], int n)
{
    for(int i = 0; i < n; i++)
	printf("%d ", a[i]);
    printf("\n");
}

int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    int b[5] = {6, 7, 8, 9, 0};
    int c[5];
    c = b;
    b = a;
    a = c;

    outputArray(a, 5);
    outputArray(b, 5);
    outputArray(c, 5);   
}
