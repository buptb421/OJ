#define nullptr NULL
#include<stdio.h>
#include<stdlib.h>

int* constructD1(int n);
int** constructD2(int m, int n);

void destroyD1(int *p);
void destroyD2(int **p, int m);

void inputD1(int *p, int n);
void inputD2(int **p, int m, int n);
void outputD1(int *p, int n);
void outputD2(int **p, int m, int n);

void transD1(int *p, int n);
void transD2(int **p, int m, int n);

int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    
    int **p = constructD2(m, n);
    if(p == nullptr)
    {
	printf(" A.\n");
	return 1;
    }
    else
    {
	inputD2(p, m, n);
	transD2(p, m, n);
	outputD2(p, m, n);
	destroyD2(p, m);
	
	return 0;
    }
}

// Construct the arrays.----------------------------------\|
int* constructD1(int n)
{
    int *p = (int*)malloc(sizeof(int) * n);
    if(p == nullptr)
	printf("Memory overflow while locating 1 dimension array");
    return p;
}

int** constructD2(int m, int n)
{
    int **p = (int**)malloc(sizeof(int*) * m), **temp;
    if(p == nullptr)
	printf("Memory overflow while locating 2 dimension array");
    else
    {
	temp = p;
	for(int i = 0; i < m; i++)
	{
	    *temp = constructD1(n);
	    if(*temp == nullptr)
	    {
		printf(", row %d of 2 dimension array", i);
		destroyD2(p, i);
		return nullptr;
	    }
	    else
		temp++;
	}
    }
    return p;
}
//--------------------------------------------------------/|

// Destroy the arrays.------------------------------------\|
void destroyD1(int *p)
{
    free(p);
}

void destroyD2(int **p, int m)
{
    int **temp = p;
    for(int i = 0; i < m; i++, temp++)
	free(*temp);
    free(p);
}
//--------------------------------------------------------/|

// I/O----------------------------------------------------\|
void inputD1(int *p, int n)
{
    for(int i = 0; i < n; i++)
    {
	scanf("%d", p);
	p++;
    }
}

void inputD2(int **p, int m, int n)
{
    int **temp = p;
    for(int i = 0; i < m; i++, temp++)
	inputD1(*temp, n);
}
    
void outputD1(int *p, int n)
{
    for(int i = 1; i < n; i++, p++)
	printf("%d ", *p);
    printf("%d\n", *p);
}

void outputD2(int **p, int m, int n)
{
    for(int i = 0; i < m; i++, p++)
	outputD1(*p, n);
}
//--------------------------------------------------------/|

// Transform the arrays.----------------------------------\|
void transD1(int *p, int n)
{
    for(int i = 0; i < n; i++, p++)
	*p = *p * (-10);
}

void transD2(int **p, int m, int n)
{
    for(int i = 0; i < m; i++, p++)
	transD1(*p, n);
}
//--------------------------------------------------------/|
