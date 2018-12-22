#ifndef _DATAHEADER_HPP
#define _DATAHEADER_HPP

#include<stdio.h>
#include<stdlib.h>

#define MAX_LINE 121
#define MAX_FILENAME 31
#define MAX_LINE_SCOPE 999
#define MAX_SCOPE 99

// Line---------------------------------------------------\|
typedef struct Line{
    int nChar;
    char *Str;
}Line;

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
	    delete(p);
	    return nullptr;
	}
	else
	    return p;
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
    p -> nChar = 0;
    delete(p -> Str);
    delete(p);
}
//--------------------------------------------------------/|

// Scope--------------------------------------------------\|
typedef struct Scope{
    int nLine;
    Line *Par;
}Scope;
//--------------------------------------------------------/|

//--------------------------------------------------------\|
typedef struct Ifile{
    int nScop;
    Scope *Sco;
}Ifile;
//--------------------------------------------------------/|



// Operations---------------------------------------------\|

//--------------------------------------------------------/|

#endif
