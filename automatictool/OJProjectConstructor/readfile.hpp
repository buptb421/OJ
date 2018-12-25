#ifndef _READFILE_HPP
#define _READFILE_HPP

#include"dataheader.hpp"
#include"stringoperation.hpp"

int freadLine_Str(FILE *pFile, char *s);
Line *storeLine(int lenLine, char *s);

Line *freadLine_Line(FILE *pFile);
void displayLine(Line *l);

void displayFile(FILE *pFile);

char *isLineScope(char *s);
char *isLineProperty(char *s);

void displayFile(FILE *pFile)
{
    Line *l;
    int numLine = 0;
    l = freadLine_Line(pFile);
    for(numLine = 1; (l -> nChar) != 0 && !feof(pFile); numLine++)
    {
	printf("(%-3d)", numLine);
	displayLine(l);
	destroyLine(l);
	l = freadLine_Line(pFile);
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

char *isLinePropertyStart(char *s)
{
    char propS[] = "/*\n";
    return locateSubStr(s, propS);
}

char *isLinePropertyEnd(char *s)
{
    char propS[] = "*/\n";
    return locateSubStr(s, propS);
}

#endif
