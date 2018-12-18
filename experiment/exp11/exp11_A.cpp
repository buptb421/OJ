#include<stdio.h>

int isRightLocation(char *str1, char *str2);
char *locatesubstr(char *str1,char *str2);

int main()
{
    char *str1, *str2;
    gets(str1);
    gets(str2);
    
    char *Loc = locatesubstr(str1, str2);
    
    if(Loc == NULL)
	printf("NULL!\n");
    else
    {
	while(*Loc != '\0')
	{
	    printf("%c", *Loc);
	    Loc++;
	}
	printf("\n");
    }

    return 0;    
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
