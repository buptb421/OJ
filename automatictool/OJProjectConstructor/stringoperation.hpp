#ifndef _STRINGOPERATION_HPP
#define _STRINGOPERATION_HPP

#include"dataheader.hpp"

int inputString(char *s);
void outputString(char *s);
void moveStringPiece(char *p, int lenPiece, int step);
void addStringPiece(const char *r, char *w);
int isRightLocation(char *str1,char *str2);
char *locateSubStr(char *str1, char *str2); 

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

char *locateSubStr(char *str1, char *str2)
{
    char *p = str1;
    while(*p != '\0' && !isRightLocation(p, str2))
    {
	p++;
    }
    if(*p == '\0')
	return nullptr;
    else
	return p;
}

#endif
