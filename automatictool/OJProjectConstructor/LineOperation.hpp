#ifndef _LINEOPERATION_HPP
#define _LINEOPERATION_HPP

#include"ConstData.hpp"
#include"StringOperation.hpp"

typedef struct Line{
    int nChar;
    char *Str;
}Line;

Line *constructLine(int lenLine);
void relateLine(Line *p, int lenLine, char *r);
void destroyLine(Line *p);
int freadLine_Str(FILE *pFile, char *s);
Line *storeLine(int lenLine, char *s);
Line *freadLine_Line(FILE *pFile);
void displayLine(Line *l);

#include"LineOperation.cpp"

#endif
