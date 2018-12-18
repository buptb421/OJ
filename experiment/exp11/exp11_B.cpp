#include<stdio.h>

void getString(char *p);
void outputString(char *p);

int main()
{
    char c[10001];
    c[10000] = '\0';
    char *start[1000];
    start[0] = c;
    
    getString(c);
    
    int i, count = 0;
    char *p = c;
    for(i = 0; i <= 10000 && *p != '\0'; i++)
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
    int safe = 0;
    while(*p != '\0' && safe < 10000)
    {
	printf("%c", *p);
	p++;
	safe++;
    }
    printf("\n");
}
