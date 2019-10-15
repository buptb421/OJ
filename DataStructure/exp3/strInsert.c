#include<stdio.h>

#define LENGTH 1000

int main()
{
    char buffer[LENGTH];
    int a, b;
    a = getStr(buffer);
    b = getStr(&buffer[a + 1]);

    char k;
    scanf("%c", &k);

    
}

int getStr(char *w)
{
    gets(w);
    return strlen(w);
}


char *findK(char *str, char k)
{
    while(*str != k && str != '\0')
    {
	str++;
    }
    
    if(*str == k)
    {
	return str;
    }
    else
    {
	return NULL;
    }
}

void insert(char *insertion, char
