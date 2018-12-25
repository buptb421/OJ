#ifndef _STRINGOPERATION_HPP
#define _STRINGOPERATION_HPP

void addStringPiece(const char *r, char *w);
void moveStringPiece(char *p, int lenPiece, int step);
int inputString(char *s);
void outputString(char *s);
int isMatchLocation(char *str1,char *str2);
char *locateSubStr(char *str1, char *str2);
int freadLine_Str(FILE *pFile, char *s);

#endif
