#define MAX_LENGTH 100
#include<stdio.h>
#include<stdlib.h>

char **constructStringArray(int n);
void destroyStringArray(char **p, int n);

void inputStringArray(char **p, int n);
void outputStringArray(char **p, int n);

int compareStrings(char *a, char *b);
void tocode(char **p, char **pn, int *code);
void carryback(char **p, int i);
void sortStringArray(char **start, int n);


int main()
{
    int n;
    char thr;//throw a '\n'
    scanf("%d%c", &n, &thr);
    
    char **p = constructStringArray(n);
    if(p == NULL)
	return 1;
    else
    {
	inputStringArray(p, n);
	
	sortStringArray(p, n);

	outputStringArray(p, n);
	
	destroyStringArray(p, n);
	p = NULL;
	
	return 0;
    }
}

char **constructStringArray(int n)
{
    char **p = (char**)malloc(sizeof(char*) * n);
    if(p == NULL)
    {
	printf("Memory overflow 1.\n");
    }
    else
    {
	char **temp = p;
	for(int i = 0; i < n; i++)
	{
	    *temp = (char*)malloc(sizeof(char) * (MAX_LENGTH + 1));
	    if(*temp == NULL)
	    {
		printf("Memory overflow 2.\n");
		destroyStringArray(p, i);
		return NULL;
	    }
	    else
	    {
		temp++;
	    }	
	}
    }
    return p;
}

void destroyStringArray(char **p, int n)
{
    char **temp = p;
    for(int i = 0; i < n; i++)
    {
	free(*temp);
	temp++;
    }
    free(p);
}

void inputStringArray(char **p, int n)
{
    char *s;
    for(int i = 0; i < n; i++)
    {
	s = *p;
	scanf("%c", s);
	while(*s != '\n')
	{
	    s++;
	    scanf("%c", s);
	}
	*s = '\0';
	p++;
    }
}

void outputStringArray(char **p, int n)
{
    char *s;
    for(int i = 0; i < n; i++)
    {
	s = *p;
	while(*s != '\0')
	{
	    printf("%c", *s);
	    s++;
	}
	printf("\n");
	p++;
    }
}

int compareStrings(char *a, char *b)
{
    while(*a != '\0' && *a == *b)
    {
	a++;
	b++;
    }
    
    if(*a == *b)
	return 0;
    else if(*a > *b)
	return 1;
    else
	return -1;
}

void tocode(char **p, char **pn, int *code)
{
    *code = 0;
    while(pn != p)
    {
	if(compareStrings(*p, *pn) != 1)
	    *code = *code + 1;
	p++;
    }
}

void carryback(char **p, int i)
{
    char **q = p;
    char *temp = *p;
    for(int j = 0; j < i; j++)
    {
	*q = *(q - 1);
	q--;
    }
    *q = temp;
}

void sortStringArray(char **p, int n)
{
    int *code = (int*)malloc(sizeof(int) * n);
    if(code == NULL)
    {
	printf("Memory overflow 3.\n");
    }
    else
    {
	char **pe = p;
	int *pcode = code;
	for(int i = 0; i < n; i++)
	{
	    tocode(p, pe, pcode);
	    *pcode = i - *pcode;
	    pe++;
	    pcode++;
	}

	pe = p;
	pcode = code;
	for(int i = 0; i < n; i++)
	{
	    carryback(pe, *pcode);
	    pe++;
	    pcode++;
	}
	
    }
}

