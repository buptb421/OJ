#include<stdio.h>
#include<stdlib.h>
#define nullptr NULL

typedef struct {
    int *start;
    int *end;
}line;

int *constructD1Array(int n);
void destroyD1Array(int *pi);

int **constructD2Array(int m, int n);
void destroyD2Array(int **ppi, int m);

line *constructLineIndex(int m);
void destroyLineIndex(line *ppl);
void relateLineIndex(int **ppi, line *ppl, int n);

void fill_one(line *pl, int *pcount, int step);
void fill_row(int n, line **ppl, int *pcount, int step);
void fill_column(int n, line **ppl, int *pcount, int step);
void fill_circle(int n, line **ppl, int *pcount);
void fill(int n, int **ppi);

void outputD1Array(int n, int *pi);
void outputD2Array(int m, int n, int **ppi);

int main()
{
    
    int n;
    scanf("%d", &n);

    int **ppi = constructD2Array(n, n);
    if(ppi == nullptr)
    {
	return 1;
    }
    else
    {	
	fill(n, ppi);
	
	outputD2Array(n, n, ppi);
	
	destroyD2Array(ppi, n);
	
	return 0;
    }
    
}

void outputD1Array(int n, int *pi)
{
    for(int i = 1; i < n; i++)
    {
	printf("%d ", *pi);
	pi++;
    }
    printf("%d\n", *pi);
}

void outputD2Array(int m, int n, int **ppi)
{
    for(int i = 0; i < m; i++)
    {
	outputD1Array(n, *ppi);
	ppi++;
    }
}

int *constructD1Array(int n)
{
    int *pi = (int*)malloc(sizeof(int) * n);
    if(pi == nullptr)
	printf("Memory overflow.\n");
    return pi;
}
void destroyD1Array(int *pi)
{
    free(pi);
}

int **constructD2Array(int m, int n)
{
    int **ppi = (int**)malloc(sizeof(int*) * m);
    if(ppi == nullptr)
    {
	return ppi;
    }
    else
    {
	int **tp = ppi;
	for(int i = 0; i < m; i++)
	{
	    *tp = constructD1Array(n);
	    if(*tp == nullptr)
	    {
		printf("\n\nMemory overflow.\n\n\n");
		destroyD2Array(ppi, i);
		return nullptr;
	    }
	    else
		tp++;
	}
	return ppi;
    }
}

void destroyD2Array(int **ppi, int m)
{
    int **tp = ppi;
    for(int i = 0; i < m; i++)
    {
	destroyD1Array(*tp);
	tp++;
    }
    free(ppi);
}

line *constructLineIndex(int m)
{
    line *tp = (line*)malloc(sizeof(line) * m);
    return tp;
}

void destroyLineIndex(line *l)
{
    printf("free pl.\n");
    free(l);
    printf("after free pl.\n");
}

void relateLine(int *pi, line *emptyl, int n)
{
    emptyl->start = pi;
    emptyl->end = pi;
    for(int i = 1; i < n; i++)
	emptyl->end++;
}

void relateLineIndex(int **ppi, line *emptyIndex, int m, int n)
{
    for(int i = 0; i < m; i++)
    {
	relateLine(*ppi, emptyIndex, n);
	ppi++;
	emptyIndex++;
    }
}

void fill_one(line *pl, int *pcount, int step)
{
    *pcount = *pcount + 1;
    if(step > 0)
    {
	*(pl->start) = *pcount;
	pl->start = pl->start + step; 
    }
    else if(step < 0)
    {
	*(pl->end) = *pcount;
	pl->end = pl->end + step;
    }
}

void fill_row(int n, line **ppl, int *pcount, int step)
{
    for(int i = 0; i < n; i++)
	fill_one(*ppl, pcount, step);
}

void fill_column(int n, line **ppl, int *pcount, int step)
{
    for(int i = 0; i < n; i++)
    {
	fill_row(1, ppl, pcount, -step);
	*ppl = *ppl + step;
    }
}

void fill_circle(int n, line **ppl, int *pcount)
{
    n = n - 1;
    fill_row(n, ppl, pcount, 1);
    fill_column(n, ppl, pcount, 1);
    fill_row(n, ppl, pcount, -1);
    fill_column(n, ppl, pcount, -1);
}

void fill(int n, int **ppi)
{
    line *pl;
    pl = constructLineIndex(n);
    if(pl == nullptr)
    {
	printf("\n\nMemory overflow.\n\n\n");
    }
    else
    {
	line *temppl = pl;
	int count = 0, i;
	relateLineIndex(ppi, pl, n, n);
	for(i = n; i > 1; i = i - 2)
	{
	    fill_circle(i, &temppl, &count);
	    temppl = temppl + 1;
	}
	
	if(i == 1)
	    *(temppl->start) = count + 1;
	free(pl);
    }
}

