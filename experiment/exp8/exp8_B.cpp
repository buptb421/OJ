#include<stdio.h>

int main()
{
    int a[200], b[200];
    int n;
    scanf("%d", &n);

    int *pa = a;
    int *pb = b;
    for(int i = 1; i <= n; i = i + 1, pa = pa + 1)
    {
	scanf("%d", pa);
	if(!(*pa % 2))
	{
	    *pb = *pa;
	    pb = pb + 1;
	}
	    
    }

    pa = a;
    for(int i = 1; i <= n; i = i + 1, pa = pa + 1)
	if(*pa % 2)
	{
	    *pb = *pa;
	    pb = pb + 1;
	}

    pb = b;
    for(int i = 1; i < n; i = i + 1, pb = pb + 1)
	printf("%d ", *pb);
    printf("%d\n", *pb);

    return 0;
}
