#include<stdio.h>

void getString(char *p)
{
    scanf("%c", p);
    while(*p != '\n')
    {
	p++;
	scanf("%c", p);
    }
    *p = '\0';
}

void outputString(char *str);
int isRightLocation(char *str1, char *str2);
char *locatesubstr(char *str1,char *str2);

int main()
{
    char str1[501], str2[501];
    getString(str1);
    getString(str2);
    
//    outputString(str1);
//    outputString(str2);
    
    char *Loc = locatesubstr(str1, str2);
    
    if(Loc == NULL)
		printf("NULL!\n");
    else
    	outputString(Loc);

    return 0;    
}

void outputString(char *str)
{
	int safe = 0;
	while(*str != '\0' && safe < 500)
	{
		printf("%c", *str);
		str++;
		safe++;
	}
	printf("\n");
}

int isRightLocation(char *str1,char *str2)
{
    while(*str1 == *str2 && *str1 != '\0' && *str2 != '\0')
    {
	str1++;
	str2++;
    }
    if(*str2 == '\0')
	return 1;
    else
	return 0;
}

char *locatesubstr(char *str1,char *str2)
{
    char *p = str1;
    while(*p != '\0' && !isRightLocation(p, str2))
    {
	p++;
    }
    if(*p == '\0')
	return NULL;
    else
	return p;
}
