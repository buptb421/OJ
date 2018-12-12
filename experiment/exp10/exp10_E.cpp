#include<stdio.h>

void nextr(int *r, int *w, int *border);
void nextrw(int *r, int *w, int *border);
void outputArray(int a[], int n);

int main()
{
    int a[200], addmap[200];
    
    int n;
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++)
	addmap[i] = i;
    
    int w = 0, r = 0, border = n;
    
    for(int i = 0; i < n; i++)
    {	
	a[addmap[r]] = i + 1;
	nextr(&r, &w, &border);
	
	addmap[w] = addmap[r];
        nextrw(&r, &w, &border);
	
	
	addmap[w] = addmap[r];
	nextrw(&r, &w, &border);
    }
    outputArray(a, n);
    return 0;
}

void outputArray(int a[], int n)
{
    for(int i = 0; i < n; i++)
	printf("%d ", a[i]);
    printf("\n");
}

void nextr(int *r, int *w, int *border)
{
    if((*r + 1) >= *border)
    {
	*border = *w;
	*r = 0;
	*w = 0;
    }
    else
    {
	*r = *r + 1;
    }
}

void nextrw(int *r, int *w, int *border)
{
    if((*r + 1) >= *border)
    {
	*border = *w + 1;
	*r = 0;
	*w = 0;
    }
    else
    {
	*r = *r + 1;
	*w = *w + 1;
    }
}

