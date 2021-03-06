#ifndef _LINEOPERATION_CPP
#define _LINEOPERATION_CPP

#include<stdio.h>
#include<new>
#include"ConstData.hpp"
#include"StringOperation.cpp"
#include"LineOperation.hpp"

Line *constructLine(int lenLine)
{
    Line *p = new Line;
    if(p == nullptr)
    {
	printf("\n\nMemory overflow when locating new Line.\n\n\n");
	return p;
    }
    else
    {
	p -> nChar = lenLine;
	p -> Str = new char[(p -> nChar) + 1];
	if (p -> Str == nullptr)
	{
	    printf("\n\nMemory overflow when locating new string.\n\n\n");
	    delete p;
	    return nullptr;
	}
	else
	{
	    p -> Str[p -> nChar] = '\0';
	    return p;
	}
    }
}

void relateLine(Line *p, int lenLine, char *r)
{
    char *w = p -> Str;
    for(int i = 0; i <= lenLine; i++, r++, w++)
	*w = *r;
    r--;
    if(*r != '\0')
	printf("Error ending: %c\n", *r);
}

void destroyLine(Line *p)
{
    if(p == nullptr)
    {
	printf("\n\nLine has already been deleted.\n\n\n");
    }
    else
    {
	if(p -> Str == nullptr)
	    printf("\n\nString is empty.\n\n\n");
	else
	    delete [](p -> Str);
	delete p;
    }
}

Line *storeLine(int lenLine, char *s)
{
    Line *p = constructLine(lenLine);
    if(p != nullptr)
	relateLine(p, lenLine, s);
    return p;
}

Line *freadLine_Line(FILE *pFile)
{
    Line *l;
    char line[MAX_LINE + 1];
    int lenLine;
    lenLine = freadLine_Str(pFile, line);
    if(lenLine != 0 && !feof(pFile))
    {
	l = storeLine(lenLine, line);
	if(l != nullptr)
	    return l;
	else
	    return constructLine(0);
    }
    else
	return constructLine(0);
}

void displayLine(Line *l)
{
    printf("[%-3d]", l -> nChar);
    outputString(l -> Str);
    printf("\n");
}

int isLineScope(Line *l)
{
    char scoS[] = "//-----";
    if(locateSubStr(l -> Str, scoS) == l -> Str)
	return 1;
    else
	return 0;
}

int freadScope_Line(FILE *pFile, Line **l)
{
    int countl, findScope = 0;
    Line *p = freadLine_Line(pFile);
    findScope = isLineScope(p)
    while(p -> nChar != 0 && !feof(pFile) && !findScope)
    {
	destroyLine(p);
	p = freadLine_Line(pFile);
	findScope = isLineScope(p);
    }
    destroyLine(p);
    if(!findScope)
    {
	printf("\n\nNo scope in file.\n\n\n");
	return 0;
    }
    else
    {
	p = freadLine_Line(pFile);
	for(countl = 0; countl < MAX_LINE_SCOPE && findScope && !feof(pFile); countl++)
	{
	    *l = p;
	    l++;
	    p = freadLine_Line(pFile);
	    if(isLineScope(p))
		findScope = 0;
	}
	if(findScope)
	{
	    printf("\n\nError scope.\n\n\n");
	    return countl;
	}
	else
	{
	    *l = nullptr;
	    destroyLine(p);
	    return countl - 1;
	}
    }
}

#endif
