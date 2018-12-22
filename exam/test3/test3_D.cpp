#include<stdio.h>

void getS(char *s);

int isRight(char *str1, char *str2);
char *locateSubStr(char *str1, char *str2);

void exchangeMap(int addmap[200], int i, int j);

int compare(char *str1, char *str2);
void sort(char a[200][11], int addmap[200], int n);

int main()
{
    char mode[11];
    getS(mode);
    
    int n;
    int addmap[200];
    char a[200][11];
    scanf("%d\n", &n);

    for(int i = 0; i < n; i++)
	addmap[i] = i;
	
    for(int i = 0; i < n; i++)
        getS(a[i]);
    
    int w = 0;
    for(int i = 0; i < n; i++)
    {
        if(locateSubStr(a[i], mode) != NULL)
	{
	    addmap[w] = i;
	    w++;
	}
    }

    sort(a, addmap, w);
    
    for(int i = 0; i < w; i++)
    {
	puts(a[addmap[i]]);
    }
    
    return 0;
}

void getS(char *s)
{
    scanf("%c", s);
    while(*s != '\n' && *s != '\0')
    {
	s++;
	scanf("%c", s);
    }
    *s = '\0';
}

void exchangeMap(int addmap[200], int i, int j)
{
    if(i != j)
    {
	int temp;
	temp = addmap[i];
	addmap[i] = addmap[j];
	addmap[j] = temp;
    }
}

int compare(char *str1, char *str2)
{
    while(*str1 == *str2 && *str1 !='\0')
    {
        str1++;
        str2++;
    }
    if(*str1 == '\0')
        return 0;
    else if(*str1 > *str2)
        return 1;
    else
        return -1;   
}
void sort(char a[200][11], int addmap[200], int n)
{
    for(int i = 0; i < n; i++)
	for(int j = i + 1; j < n; j++)
	{
	    if(compare(a[addmap[i]], a[addmap[j]]) == 1)
		exchangeMap(addmap, i, j); 
	}
}

int isRight(char *str1, char *str2)
{
    while(*str1 == *str2 && *str2 != '\0')
    {
        str1++;
        str2++;            
    }
    if(*str2 == '\0')
        return 1;
    else
        return 0;
}
char *locateSubStr(char *str1, char *str2)
{
     while(*str1 != '\0' && !isRight(str1, str2))
     {
       str1++;
     }
     if(*str1 != '\0')
         return str1;
     else
         return NULL;
}
