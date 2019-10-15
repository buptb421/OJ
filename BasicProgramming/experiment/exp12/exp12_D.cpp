#include<stdio.h>
#include<stdlib.h>

#define MAX_STRING_NUMBER 100
#define MAX_STRING_LENGTH 100000

void getLine(int n, char *p, char *start[]);
int compareStr(char *str1, char *str2);
void sort(int n, char *star[]);
void outputLine(int n, char *start[]);


int main()
{
    char *s = (char*)malloc(sizeof(char) * (MAX_STRING_NUMBER + MAX_STRING_LENGTH));
    if(s != nullptr)
    {
	int n;
	scanf("%d", &n);
	getchar();

	char *start[100];
	getLine(n, s, start);

	sort(n, start);

	outputLine(n, start);

	return 0;
    }
    else
	return 1;
}

void getLine(int n, char *p, char *start[])
{
    
    int charNum = 0;
    *start = p;
    start++;
    *p = '\0';
    while(n > 0 && charNum <= MAX_STRING_NUMBER + MAX_STRING_LENGTH)
    {
	charNum++;
	scanf("%c", p);
	if(*p == '\n')
	{
	    n--;
	    *p = '\0';
	    p++;
	    *start = p;
	    start++;
	}
	else
	{
	    p++;
	}
    }
}

int compareStr(char *str1, char *str2)
{
    while(*str1 == *str2 && *str1 != '\0' && *str2 != '\0')
    {
	str1++;
	str2++;
    }
    if(*str1 > *str2)
	return 1;
    else
	return 0;
}

void sort(int n, char *start[])
{
    char *temp;
    for(int i = 1; i < n; i++)
	for(int j = 0; j < n - i; j++)
	    if(compareStr(start[j], start[j + 1]))
	    {
		temp = start[j];
		start[j] = start[j + 1];
		start[j + 1] = temp;
	    }
}

void outputLine(int n, char *start[])
{
    for(int i = 0; i < n; i++)
    {
	puts(start[i]);
    }
}
