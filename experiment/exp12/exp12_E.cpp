#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int *start;
    int *end;
}pline;

pline constructD1Array(int n);
void destroyD1Array(pline l);

pline *constructD2Array(int m, int n);
void destroyD2Array(pline *pl, int m);

pline *constructLineIndex(int m);
void destroyLineIndex(pline l);
void relateLineIndex(*pline p, *pline q, int n);

fill(int n, pline *pl);

void outputD1Array(int n, pline l);
void outputD2Array(int m, int n, *pline pl);

int main()
{
    int n;
    scanf("%d", &n);

    pline *pl = constructD2Array(n, n);
    if(pl == nullptr)
    {
	return 1;
    }
    else
    {
	fill(n, pl);
	
	outputD2Array(n, p);
	return 0;
    }
}

pline constructD1Array(int n)
{
    int *pi = (int*)malloc(sizeof(int*) * n);
    
    pline a;
    a.start = pi;
    a.end = nullptr;
    return a;
}

void destroyD1Array(pline l)
{
    free(l.start);
}

pline *constructD2Array(int m, int n)
{
    pline *pl = (pline*)malloc(sizeof(pline) * m);
    pline *tpl;
    for(int i = 0; i < m; i++)
    {
	
    }
    
}
void destroyD2Array(pline *pl, int m);

pline *constructLineIndex(int m);
void destroyLineIndex(pline l);
void relateLineIndex(*pline p, *pline q, int n);

fill(int n, pline *pl);

void outputD1Array(int n, pline l);
void outputD2Array(int m, int n, *pline pl);
