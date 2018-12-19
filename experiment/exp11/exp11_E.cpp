#include<stdio.h>
#include<stdlib.h>

/*
Dependencies:
 * main
 ** constructD2
 *** constructD1
 ** constructD2Index
 *** relateD2Index
 ** destroyD2
 *** destroyD1
 *** [*main]destroyD2index
 ** outputD2
 *** outputD1
 ** fillin
 *** next
 */

// Debug functin------------------------------------------\|
/*

 */
//--------------------------------------------------------/|

int *constructD1(int n);
int **constructD2(int m, int n);

void relateD2Index(int **index, int **p, int m);
int **constructD2Index(int m, int **p);

void destroyD1(int *p);
void destroyD2Index(int **p);
void destroyD2(int **p, int m);

void next(int ***index, int *i, int *j, int n);
void fillin(int **index, int n);

void outputD1(int *p, int n);
void outputD2(int **p, int m, int n);



int main()
{
    int n;
    scanf("%d", &n);
    
    if(n > 0)
    {
	int **p = constructD2(n, n);
	if(p == NULL)
	{
	    printf("Memory overflow.\n");
	    return 1;
	}
	else
	{   
	    int **index = constructD2Index(n, p);
	    if(index == NULL)
	    {
		printf("Memory overflow.\n");
		destroyD2(p, n);
		return 1;
	    }
	    else
	    {	
		fillin(index, n);
		
		outputD2(p, n, n);
		
		destroyD2Index(index);
		destroyD2(p, n);
		
		return 0;
	    }
	    return 2;
	    
	}
	return 2;
    }
    else
    {
	printf("\n");
	return 0;
    }
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// Construct the arrays-----------------------------------\|
int *constructD1(int n)
{
    int *p = (int*)malloc(sizeof(int) * n);
    return p;
}

int **constructD2(int m, int n)
{
    int **p = (int**)malloc(sizeof(int*) * m);
    if(p == NULL)
    {
	return NULL;
    }
    else
    {
	int **q = p;
	for(int i = 0; i < m; i++)
	{
	    *q = constructD1(n);
	    if(*q == NULL)
	    {
		destroyD2(p, i);
		return NULL;
	    }
	    else
		q++;
	}
	return p;
    }
}
//--------------------------------------------------------/|



// Construct index----------------------------------------\|
void relateD2Index(int **index, int **p, int m)
{
    for(int i = 0; i < m; i++, index++, p++)
	    *index = *p;
}

int **constructD2Index(int m, int **p)
{
    int **q = (int**)malloc(sizeof(int*) * m);
    if(q == NULL)
    {
	return NULL;
    }
    else
    {
	relateD2Index(q, p, m);
	return q;
    }
}
//--------------------------------------------------------/|



// Recycle------------------------------------------------\|
void destroyD1(int *p)
{
    free(p);
}

void destroyD2Index(int **p)
{
    free(p);
}

void destroyD2(int **p, int m)
{
    int **q = p;
    for(int i = 0; i < m; i++, q++)
	destroyD1(*q);
    destroyD2Index(p);
}
//--------------------------------------------------------/|



// Position change and fill in----------------------------\|

void next(int ***index, int *i, int *j, int n)
{
    if((*i + *j) % 2 == 1)
    {
	if(*j == n - 1)
	{
	    *index = *index + 1;
	    *i = *i + 1;
	    *j = *j - 1;
	}
	else if(*i != 0)
	{
	    *index = *index - 1;
	    *i = *i - 1;
	}
	
	**index = **index + 1;
	*j = *j + 1;
    }
    else
    {
	if(*i != n - 1)
	{
	    *index = *index + 1;
	    *i = *i + 1;
	    if(*j == 1)
	    {
		*j = 0;
	    }
	    if(*j != 0)
	    {
		**index = **index + 1;
		*j = *j - 1;
	    }
	}
	else
	{
	    **index = **index + 1;
	    *j = *j + 1;
	}
    }
}

void fillin(int **index, int n)
{
    int i = 0, j = 0;
    for(int k = 1; k <= n * n; k++)
    {
	**index = k;
	next(&index, &i, &j, n);
    }
}
//--------------------------------------------------------/|



// Output-------------------------------------------------\|
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
