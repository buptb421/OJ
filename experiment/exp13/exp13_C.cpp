#include<stdio.h>
#include<stdlib.h>

int BinarySearch(int *a,int n,int key);
void outputResult(int pos, int n);

int main()
{
    int m, n;
    scanf("%d%d", &n, &m);

    int *Array, *Search;
    Array = (int*)malloc(sizeof(int) * n);
    if(Array == NULL)
    {
	printf("Memory overflow[Array].\n");
	return 1;
    }
    else
    {
	Search = (int*)malloc(sizeof(int) * m);
	if(Search == NULL)
	{
	    printf("Memory overflow.[Search]\n");
	    free(Array);
	    return 2;
	}
	else
	{
	    int *tp;

	    tp = Array;
	    for(int i = 0; i < n; i++)
	    {
		scanf("%d", tp);
		tp++;
	    }

	    tp = Search;
	    for(int i = 0; i < m; i++)
	    {
		scanf("%d", tp);
		printf("%d ", BinarySearch(Array, n, *tp));
		tp++;
	    }
	    printf("\n");
	    
	    free(Array);
	    free(Search);
	    
	    return 0;
	}
		
    }
}

int BinarySearch(int *a,int n,int key)
{
    int up, down, mid, i;
    down = 0;
    up = n - 1;
    while(up - down > 4)
    {
	mid = (up + down) / 2;
	if(a[mid] > key)
	{
	    up = mid;
	}
	else
	{
	    down = mid;
	}
    }
    for(i = down; i <= up; i++)
    {
	if(a[i] == key)
	    return i;
    }
    return -1;
}
