#ifndef _INTERFACE_H
#define _INTERFACE_H

#include"clerkClient.h"
#include"database.h"

void debugname(item *pi);

void absorbBlanc(void);
void changePage(void);
void changePage_silent(void);

char *constructStr(int n);
void destroyStr(char *s);
void outputTempStr(char *s);

char *dealName(char *s);// Need to be destoried later
void showName(item *p);
double tranPrice(int price100);
char *myStr(const char *const s);// Need to be destroied later
void vsnpItem(char *s, int len, ...);
char *itemchart(int count, item *pi);
char *putMiddle(char *s, char c, int desLen);
char *tranItem(int count, item *head);
void showItem(int count, item *head);

void edge_up(char line, char point, int width);
void edge_body(char *s, char line, int width);// s should be temp string.
void edge_down(char line, char point, int width);
void add_edge(char line, char point, int width, char *str1,...);// Will free what has been transferred in.
int showList(item *head);

#endif
