#ifndef _STRINGOPERATION_CPP
#define _STRINGOPERATION_CPP

#include<stdio.h>
#include"ConstData.hpp"
#include"StringOperation.hpp"

void addStringPiece(const char *r, char *w)
{
    int count = 0;
    while(*(r + count) != '\0')
    {
	*w = *(r + count);
	count++;
	w++;
    }
}

void moveStringPiece(char *p, int lenPiece, int step)
{
    if(p == nullptr)
	printf("Null pointer operation detacted when moving string piece.\n");
    else
    {
	char *pw;
	if(step > 0)
	{
	    p = p + lenPiece - 1;
	    pw = p + step;
	    for(int i = 0; i < lenPiece; i++, pw--, p--)
		*pw = *p;
	}
	else if(step < 0)
	{
	    pw = p - step;
	    for(int i = 0; i < lenPiece; i++, pw++, p++)
		*pw = *p;
	}
    }
}

int inputString(char *s)
{
    int count = 0;
    scanf("%c", s);
    while(*s != '\0' && *s != '\n')
    {
	s++;
	count++;
	scanf("%c", s);
    }
    *s = '\0';
    return count;
}

void outputString(char *s)
{
    while(*s != '\0')
    {
	printf("%c", *s);
	s++;
    }
}

int isMatchLocation(char *str1,char *str2)
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

char *locateSubStr(char *str1, char *str2)
{
    char *p = str1;
    while(*p != '\0' && !isMatchLocation(p, str2))
    {
	p++;
    }
    if(*p == '\0')
	return nullptr;
    else
	return p;
}

int freadLine_Str(FILE *pFile, char *s)
{
    int i;
    fscanf(pFile, "%c", s);
    for(i = 1; i < MAX_LINE && *s != '\n' && !feof(pFile); i++)
    {
	s++;
	fscanf(pFile, "%c", s);
    }
    if(i == MAX_LINE)
    {
	s--;
	if(*s != '\n' && *s != '\0')
	{
	    printf("Too long line.\n");
	    s++;
	    *s = '\0';
	    return 0;
	}
	else if(*s == '\n')
	{
	    *(s + 1) = '\0';
	    return MAX_LINE;
	}
	else return MAX_LINE - 1;
    }
    else if(*s == '\n')
    {
	*(s + 1) = '\0';
	return i;
    }
    else
	return 0;
}// if have read a EOF, return 0 while empty line have \n for 1.

#endif
