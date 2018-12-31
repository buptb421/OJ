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
    printf("Please enter the name of the new item.\nItem name :");
    scanf("%c", s);
    for(int i = 0; i < NAMELEN && *s != '\n' && *s != '\0'; i++)
    {
	s++;
	scanf("%c", s);
    }
    *s = '\0';
}



/*
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

char *putMiddle(char *s, char c, desLen)
{
    int len = strlen(s);
    char *news;
    if(len >= desLen)
	desLen = len;

    news = constructStr(desLen + 1)
    for(int i = 0; i < (desLen - len) / 2; i++)
	
    return news;
}

char *chart(int n, int *space, char **s)
*/

void outputIntro()
{
    printf("Intro :\n");
}
  
#endif
