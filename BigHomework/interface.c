#ifndef _INTERFACE_C
#define _INTERFACE_C

#include<stdio.h>
#include<string.h>
#include<stdarg.h>

#include"clerkClient.h"
#include"database.c"

void changePage(void)
{
    printf("\nPress ENTER to proceed.\n");

    char a;
    do
    {
	a = getchar();
    }while(a != '\n');
    
    system("cls");
}

void changePage_silent(void)
{
    system("cls");
}

void absorbBlanc(void)
{
	char a;
    do
    {
	a = getchar();
    }while(a != '\n');
}

void askCommand(int *pcommand)
{
    printf("enter command from options 1 to 6.\nCommand :");
    scanf("%d", pcommand);

    absorbBlanc();
}

int askChangeStorage()
{
    int change;
    printf("Change storage.\nadd :");
    scanf("%d", &change);

    char a;
    do
    {
	a = getchar();
    }while(a != '\n');
    
    return change;
}

void askRemain(int *r)
{
    printf("Please enter the remaining number of item.\nRemain :");
    scanf("%d", r);

    char a;
    do
    {
	a = getchar();
    }while(a != '\n');
}

void askPrice(int *pri)
{
    float price;
    printf("Please enter the price of the item.\nPrice :");
    scanf("%f", &price);

    char a;
    do
    {
	a = getchar();
    }while(a != '\n');
    
    *pri = (price + 0.005) * 100;
}

void askPurchaseNum(int *pur)
{
    printf("Please enter the number of purchase.\n");
    scanf("%d", pur);

    char a;
    do
    {
	a = getchar();
    }while(a != '\n');
}

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

void showItem(item *head)
{
    if(head != NULL)
    {
	printf("Name : ");
	showName(head);

	printf("\nPrice : ");
	printf("%.2lf", tranPrice(head->price100));
	printf("\nRemain : %d\n", head->remain_num);
	
	for(int i = 0; i < 60; i++)
	    printf("-");
	
	printf("\n");
    }
    else
	printf("Try to show void item.\n");
}

int showList(item *head)
{
    int count = 0;
    if(head != NULL)
    {
	head = head->next;
	while(head != NULL)
	{
	    showItem(head);
	    count++;
	    head = head->next;
	}
    }
    return count;
}

void askName(char *s)
{
    printf("Please enter the name of the item.\nItem name :");
    scanf("%c", s);
    for(int i = 0; i < NAMELEN && *s != '\n' && *s != '\0'; i++)
    {
	s++;
	scanf("%c", s);
    }
    
    if(*s != '\n' && *s != '\0')
    	absorbBlanc();
    
    *s = '\0';
}

char *constructStr(int n)
{
    return (char*)malloc(sizeof(char) * n);
}

char *myStr(char *const s)
{
    char *r, *w;
    char *ns;
    ns = constructStr(NAMELEN + 1);

    r = s;
    w = ns;
    
    while(*r != '\0')
    {
	*w = *r;
	w++;
	r++;
    }
    *w = '\0';
    
    return ns;
}// Need to be destroied later

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

void destroyStr(char *s)
{
    if(s != NULL)
	free(s);
    else
	printf("Try to clear void string.\n");
}

char *putMiddle(char *s, char c, int desLen)
{
    int len = strlen(s);
    char *news, *ts, *r;
    if(len >= desLen)
	desLen = len;

    news = constructStr(desLen + 1);
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
    return news;
}

void outputTempStr(char *s)
{
    puts(s);
    free(s);
}

void vsnpItem(char *s, int len, ...)
{
    va_list argum;
    va_start (argum, len);
    vsnprintf(s, len, "%5d%15s%20.2lf%20d", argum);
    va_end(argum);
}

char *itemchart(int count, item *pi)
{
    char *s = constructStr(DEFAULT_TERMINAL_WIDTH + 1);
    char *pName = dealName(pi->name);

    vsnpItem(s, DEFAULT_TERMINAL_WIDTH + 1, count, pName, tranPrice(pi->price100), pi->remain_num);
    
    free(pName);
    return s;
}
  
#endif
