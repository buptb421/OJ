#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void destroyStrList(int n, char **ps);
int inputStr(int n, char** ps);

void outputStrList(int n, char **ps);

void merge_refill(char **buffer, int dig1, char **ps1, int dig2, char **ps2);
void merge_iter(char **buffer, int dig, char **ps);
void merge_sort(int dig, char **ps);

int main()
{
    int n;
    scanf("%d", &n);
    getchar();

    char **ps = (char**)malloc(sizeof(char*) * n);
    int ti = inputStr(n, ps);
    if(ti < n)
    {
	destroyStrList(ti, ps);
	return 1;
    }
    else
    {
	merge_sort(n, ps);
	outputStrList(n, ps);
	destroyStrList(n, ps);
	return 0;
    }
}

void destroyStrList(int n, char **ps)
{
    char *ts, **tps = ps;
    for(int i = 0; i < n; i++)
    {
	ts = *tps;
	tps++;
	free(ts);
    }
    free(ps);
}

int inputStr(int n, char **ps)
{
    char a[1001], *ts;
    int i, j, err = 0;
    char *r, *w;
    for(i = 0; i < n && err == 0; i++)
    {
	ts = a;
	scanf("%c", ts);
	for(j = 0; j < 1000 && *ts != '\n'; j++)
	{
	    ts++;
	    scanf("%c", ts);
	}
	*ts = '\0';
	
	*ps = (char*)malloc(sizeof(char) * (j + 1));
	if(*ps == NULL)
	{
	    err = 1;
	}
	else
	{
	    r = a;
	    w = *ps;
	    for(int k = 0; k < j + 1; k++)
	    {
		*w = *r;
		r++;
		w++;
	    }
	}
	ps++;
    }
    return i - err;
}

void outputStrList(int n, char **ps)
{
    for(int i = 0; i < n; i++)
    {
	puts(*ps);
	ps++;
    }
}

void merge_refill(char **buffer, int dig1, char **ps1, int dig2, char **ps2)
{
    int d1 = dig1, d2 = dig2, cmp;
    char **r1 = ps1, **r2 = ps2, **w = buffer;
    while(d1 > 0 && d2 > 0)
    {
	cmp = strcmp(*r1, *r2);
	if(cmp < 0)
	{
	    *w = *r1;
	    r1++;
	    d1--;
	}
	else
	{
	    *w = *r2;
	    r2++;
	    d2--;
	}
	w++;
    }
    while(d1 > 0)
    {
	*w = *r1;
	w++;
	r1++;
	d1--;
    }
    while(d2 > 0)
    {
	*w = *r2;
	w++;
	r2++;
	d2--;
    }
    r1 = buffer;
    w = ps1;
    for(int i = 0; i < dig1 + dig2; i++)
    {
	*w = *r1;
	w++;
	r1++;
    }
}

void merge_iter(char **buffer, int dig, char **ps)
{
    if(dig > 1)
    {
	merge_iter(buffer, dig / 2, ps);
	merge_iter(buffer, (dig + 1) / 2, ps + (dig / 2));
	merge_refill(buffer, dig / 2, ps, (dig + 1) / 2, ps + (dig / 2));
    }
}

void merge_sort(int n, char **ps)
{
    char **buffer = (char**)malloc(sizeof(char*) * n);
    if(buffer == NULL)
    {
	printf("Memory overflow.\n");
    }
    else
    {
	merge_iter(buffer, n, ps);
	free(buffer);
    }
}
