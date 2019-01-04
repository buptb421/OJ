#ifndef _INTERFACE_C
#define _INTERFACE_C

#include<stdio.h>
#include<string.h>
#include<stdarg.h>

#include"clerkClient.h"
#include"database.c"

void debugname(item *pi)
{
    char *c = pi->name;
    printf("[");
    for(int i = 0; i < NAMELEN; i++)
    {
	if(*c <= 32)
	  printf("[%d]", *c);
	else
	    printf("%c", *c);
	c++;
    }
    printf("]");
}

void absorbBlanc(void)
{
    char a;
    do
    {
	a = getchar();
    }while(a != '\n');
}

void changePage(void)
{
    printf("\nPress ENTER to proceed.\n");
    
    absorbBlanc();
    
    system(CLEAR_SCREEN);
}

void changePage_silent(void)
{
    system(CLEAR_SCREEN);
}

char *constructStr(int n)
{
    return (char*)malloc(sizeof(char) * n);
}

void destroyStr(char *s)
{
    if(s != NULL)
	free(s);
    else
	printf("Try to clear void string.\n");
}

void outputTempStr(char *s)
{
    puts(s);
    destroyStr(s);
}

char *dealName(char *s)
{
    char *ns, *tp;
    ns = constructStr(NAMELEN + 1);
    if(ns != NULL)
    {
	tp = ns;
	for(int i = 0; i < NAMELEN && *s != '\0'; i++)
	{
	    *tp = *s;
	    tp++;
	    s++;
	}
	*tp = '\0';
    }
    
    return ns;
}// Need to be destoried later


void showName(item *p)
{
    char *s = p->name;
    for(int i = 0; i < 6 && *s != '\0'; i++, s++)
	printf("%c", *s);
}

double tranPrice(int price100)
{
    double lf = price100 / 100.000;
    return lf;
}

char *myStr(char *const s)
{
    char *r, *w;
    char *ns;
    ns = constructStr(NAMELEN + 1);

    if(ns != NULL)
    {
	r = s;
	w = ns;
	
	while(*r != '\0')
	{
	    *w = *r;
	    w++;
	    r++;
	}
	*w = '\0';
    }
    
    return ns;
}// Need to be destroied later

void vsnpItem(char *s, int len, ...)
{
    va_list argum;
    va_start (argum, len);
    vsnprintf(s, len, "%-5d%15s%20.2lf%20d", argum);
    va_end(argum);
}

char *itemchart(int count, item *pi)
{
    char *s = constructStr(DEFAULT_TERMINAL_WIDTH + 1);
    if(s != NULL)
    {
	char *pName = dealName(pi->name);
	if(pName != NULL)
	{
	    vsnpItem(s, DEFAULT_TERMINAL_WIDTH + 1, count, pName, tranPrice(pi->price100), pi->remain_num);
	    destroyStr(pName);
	}
    }
    return s;
}

char *putMiddle(char *s, char c, int desLen)
{
    int len = strlen(s);
    char *news, *ts, *r;
    if(len >= desLen)
	desLen = len;

    news = constructStr(desLen + 1);
    if(news != NULL)
    {
	ts = news;
	for(int i = 0; i < (desLen - len) / 2; i++)
	{
	    *ts = c;
	    ts++;
	}
	
	r = s;
	for(int i = 0; i < len; i++)
	{
	    *ts = *r;
	    ts++;
	    r++;
	}
	
	for(int i = 0; i < (desLen - len + 1) / 2; i++)
	{
	    *ts = c;
	    ts++;
	}
	*ts = '\0';
	
	destroyStr(s);
    }
    return news;
}

char *tranItem(int count, item *head)
{
    if(head != NULL)
    {
	return itemchart(count, head);
    }
    else
    {
	printf("Try to show void item.\n");
	return NULL;
    }
}

void showItem(int count, item *head)
{
    char *ts = tranItem(count, head);
    if(ts != NULL)
    {
	outputTempStr(ts);
	destroyStr(ts);
    }
}

void edge_up(char line, char point, int width)
{
    outputTempStr(
	putMiddle(
	    putMiddle(
		putMiddle(
		    myStr(""),
		    line, width - 2),
		point, width),
	    ' ', DEFAULT_TERMINAL_WIDTH)
	);
    
    outputTempStr(
	putMiddle(
	    putMiddle(
		putMiddle(
		    myStr(""),
		    ' ', width - 2),
		line, width),
	    ' ', DEFAULT_TERMINAL_WIDTH)
	);
}

void edge_body(char *s, char line, int width)// s should be temp string.
{
    outputTempStr(
	putMiddle(
	    putMiddle(
		putMiddle(
		    s,
		    ' ', width - 2),
		line, width),
	    ' ', DEFAULT_TERMINAL_WIDTH)
	    );
}

void edge_down(char line, char point, int width)
{
    outputTempStr(
	putMiddle(
	    putMiddle(
		putMiddle(
		    myStr(""),
		    ' ', width - 2),
		line, width),
	    ' ', DEFAULT_TERMINAL_WIDTH)
	);

    outputTempStr(
	putMiddle(
	    putMiddle(
		putMiddle(
		    myStr(""),
		    line, width - 2),
		point, width),
	    ' ', DEFAULT_TERMINAL_WIDTH)
	);
}

void add_edge(char line, char point, int width, char *str1,...)// Will not free what has been transferred in.
{
    va_list str;

    char *s = str1;

    va_start(str, str1);
    edge_up(line, point, width);
    while(s != NULL)
    {
	edge_body(myStr(s), line, width);
	s = va_arg(str, char*);
    }
    edge_down(line, point, width);
    
    va_end(str);
}

int showList(item *head)
{
    int count = 0;
    if(head == NULL)
    {
	printf("There is no list.\n");
    }
    else
    {
	head = head->next;
	if(head == NULL)
	    printf("Empty list!");
	else
	{
	    edge_up('=', '+', DEFAULT_TERMINAL_WIDTH - 6);
	    edge_body(myStr("    ID           Item code             Price       Remaining number"), '=', DEFAULT_TERMINAL_WIDTH - 6);
	    edge_body(myStr("-------------------------------------------------------------------"), '=', DEFAULT_TERMINAL_WIDTH - 6);
	    while(head != NULL)
	    {
		count++;
		edge_body(tranItem(count, head), '=', DEFAULT_TERMINAL_WIDTH - 6);
		head = head->next;
	    }
	    edge_down('=', '+', DEFAULT_TERMINAL_WIDTH - 6);
	}
    }
    return count;
}

#endif
