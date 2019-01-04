#include<stdio.h>
#include<stdlib.h>

int findInArray(const int *array, const int element, const int size);
void outputAdjacent(const int *array, const int m, const int size);
int main()
{
    int m, n;
    
    scanf("%d", &m);
    int *p = (int*)malloc(sizeof(int) * m);
    if(p == NULL)
    {
	printf("[Memory overflow.]\n");
	return 1;
    }
    else
    {
	int *tp = p;
	for(int i = 0; i < m; i++)
	{
	    scanf("%d", tp);
	    tp++;
	}

	scanf("%d", &n);
	int *search = (int*)malloc(sizeof(int) * n);
	if(search == NULL)
	{
	    printf("[Memory overflow.]\n");
	    free(p);
	    return 2;
	}
	else
	{
	    tp = search;
	    for(int i = 0; i < n; i++)
	    {
		scanf("%d", tp);
		tp++;
	    }

	    tp = search;
	    for(int i = 0; i < n; i++)
	    {
		outputAdjacent(p, findInArray(p, *tp, m), m);
		tp++;
	    }
	    
	    free(p);
	    free(search);
	}
    }
}

int findInArray(const int *array, const int element, const int size)
{
    int i;
    for(i = 1; i <= size && *array != element; i++)
    {
	array++;
    }
    if(i <= size && *array == element)
	return i;
    else
	return 0;    
}

void outputAdjacent(const int *array, const int m, const int size)
{
    if(m < 1)
	printf("NULL\n");
    else if(m == 1)
    {
	array++;
	printf("%d\n", *array);
    }
    else if(m <= size)
    {
	for(int i = 2; i < m; i++)
	{
	    array++;
	}
	if(m == size)
	    printf("%d\n", *array);
	else
	    printf("%d %d\n", *array, *(array + 2));
    }
    else
    {
	printf("[Unexpected entrence.]\n");
    }
}
