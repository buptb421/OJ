#ifndef _LINEOPERATION_HPP
#define _LINEOPERATION_HPP

typedef struct Line{
    int nChar;
    char *Str;
}Line;

Line *constructLine(int lenLine);
void relateLine(Line *p, int lenLine, char *r);
void destroyLine(Line *p);
Line *storeLine(int lenLine, char *s);
Line *freadLine_Line(FILE *pFile);
void displayLine(Line *l);
int freadScope_Line(FILE *pFile, Line **l);

#endif
