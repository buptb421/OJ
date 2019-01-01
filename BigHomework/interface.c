#ifndef _INTERFACE_C
#define _INTERFACE_C

#include<stdio.h>
#include<string.h>
#include"clerkClient.h"
#include"database.c"

void changePage(void)
{
    printf("Press ENTER to proceed.\n");
    getchar();
    system("clear");
}

void askCommand(int *pcommand)
{
    printf("enter command from options 1 to 6.\nCommand :");
    scanf("%d", pcommand);
    getchar();
}

int askChangeStorage()
{
    int change;
    printf("Change storage.\nadd :");
    scanf("%d", &change);
    return change;
}

void askRemain(int *r)
{
    printf("Please enter the remaining number of item.\nRemain :");
    scanf("%d", r);
    getchar();
}

void askPrice(int *pri)
{
    float price;
    printf("Please enter the price of the item.\nPrice :");
    scanf("%f", &price);
    getchar();
    *pri = (price + 0.005) * 100;
}

void askPurchaseNum(int *pur)
{
    printf("Please enter the number of purchase.\n");
    scanf("%d", pur);
    getchar();
}

void showName(item *p)
{
    char *s = p->name;
    for(int i = 0; i < 6 && *s != '\0'; i++, s++)
	printf("%c", *s);
}

void showPrice(int price100)
{
    double lf = price100 / 100.000;
    printf("%.2lf", lf);
}

void showItem(item *head)
{
    if(head != NULL)
    {
	printf("Name : ");
	showName(head);
	printf("\nPrice : %d\nRemain : %d\n", head->price100, head->remain_num);
	
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
    *s = '\0';
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

char *putMiddle(const char *s, char c, int desLen)
{
    int len = strlen(s);
    char *news, *ts;
    if(len >= desLen)
	desLen = len;

    news = constructStr(desLen + 1);
    ts = news;
    for(int i = 0; i < (desLen - len) / 2; i++)
    {
	*ts = c;
	ts++;
    }
    for(int i = 0; i < len; i++)
    {
	*ts = *s;
	ts++;
	s++;
    }
    for(int i = 0; i < (desLen - len + 1) / 2; i++)
    {
	*ts = c;
	ts++;
    }
    *ts = '\0';
    
    return news;
}
/*
char *chart(int n, int *space, char **s)
{
    
}
*/
void outputIntro()
{
    printf("Intro :\n");
}
  
#endif
