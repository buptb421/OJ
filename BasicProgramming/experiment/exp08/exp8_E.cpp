#include<stdio.h>

void inputArray(int *p, int n)
{
    for(int i = 1; i <= n; i = i + 1, p = p + 1)
	scanf("%d", p);
}

void printAdjacent(int *pi, int i, int length)
{
    if(i > 0 && i < length - 1)
	printf("%d %d\n", *(pi - 1), *(pi + 1));
    else if(i)
	printf("%d\n", *(pi - 1));
    else
	printf("%d\n", *(pi + 1));
}

void search_execute(int target, int *p, int length)
{
    int i;
    for(i = 0; *p != target && i < length; i = i + 1)
	p = p + 1;
    if(*p == target)
	printAdjacent(p, i, length);
    else
	printf("NULL\n");
}

int main()
{
    int n, m;
    
    scanf("%d", &n);
    int a[1000];
    inputArray(a, n);

    scanf("%d", &m);
    int b[100];
    inputArray(b, m);

    int *p = b;
    for(int i = 1; i <= m; i = i + 1, p = p + 1)
	search_execute(*p, a, n);

    return 0;
}
