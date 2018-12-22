#include<stdio.h>

void getString(char *p);

void outputString(char *p);

int main()
{
    char c[10001];
    char *start[1001];
    
    getString(c);
    
    int count;
    
    if(*c == ' ')
	count = -1;
    else
    {
	count = 0;
	start[0] = c;
    }
    
    char *p = c;
    for(int i = 0; i <= 10000 && *p != '\0'; i++)
    {
	if(*p == ' ')
	{
	    *p = '\0';
	    p++;
	    if(*p != ' ' && *p != '\0')
	    {
		count++;
		start[count] = p;
	    }
	}
	else
	    p++;
    }

    for(int j = 0; j <= count; j++)
    {
	outputString(start[j]);
    }

    return 0;
}

void getString(char *p)
{
    scanf("%c", p);
    while(*p != '\n' && *p != '\0')
    {
	p++;
	scanf("%c", p);
    }
    *p = '\0';
}

void outputString(char *p)
{
    int buffer = 0;
    while(*p != '\0' && buffer <= 10000)
    {
	printf("%c", *p);
	p++;
	buffer++;
    }
    printf("\n");
}
