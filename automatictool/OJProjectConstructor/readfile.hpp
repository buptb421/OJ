#ifndef _READFILE_HPP
#define _READFILE_HPP

#include"dataheader.hpp"
#include"stringoperation.hpp"

int freadLineChar(FILE *pFile, char *s);
Line *storeLine(int lenLine, char *s);

Line *freadLineLine(FILE *pFile);
void displayLine(Line *l);

void displayFile(FILE *pFile);

char *isLineScope(char *s);
char *isLineProperty(char *s);


int freadLineChar(FILE *pFile, char *s)
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

Line *storeLine(int lenLine, char *s)
{
    Line *p = constructLine(lenLine);
    if(p != nullptr)
	relateLine(p, lenLine, s);
    return p;
}

Line *freadLineLine(FILE *pFile)
{
    Line *l;
    char line[MAX_LINE + 1];
    int lenLine;
    lenLine = freadLineChar(pFile, line);
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
}

void displayFile(FILE *pFile)
{
    Line *l;
    int numLine = 0;
    l = freadLineLine(pFile);
    for(numLine = 1; (l -> nChar) != 0 && !feof(pFile); numLine++)
    {
	printf("(%-3d)", numLine);
	displayLine(l);
	destroyLine(l);
	l = freadLineLine(pFile);
    }
    destroyLine(l);
    printf("(EOF)[end]\n");
}
/*
void fsepScope(FILE *pFile, Scope *sco)
{   
    int scopeHandle = 0;
    Line *scoLine[MAX_LINE_SCOPE];

    char line[MAX_LINE + 1];
    int numLine = 0;
    int lenLine;

    lenLine = freadLine_char(pFile, line);
    storeLine()
    while()
}
*/
char *isLineScope(char *s)
{
    char scoS[] = "//-----";
    return locateSubStr(s, scoS);
}

char *isLineProperty(char *s)
{
    char propS[] = "/*\n";
    return locateSubStr(s, propS);
}

#endif
