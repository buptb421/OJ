#ifndef _DATABASE_C
#define _DATABASE_C

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"clerkClient.h"

void setName(item *p, char *s)
{
    char *w = p->name;
    int i;
    for(i = 0; i < 6 && *s != '\0'; i++)
    {
	*w = *s;
	w++;
	s++;
    }
    if(i < 6)
	*w = '\0';
}

int is_valid_name(char *s)
{
    return *s != '\0';
}

void setPrice(item *p, int p100)
{
    p->price100 = p100;
}

void addRemain(item *p, int r)
{
    p->remain_num = p->remain_num + r;
}

item *constructItem(void)
{
    item *pi;
    pi =  (item*)malloc(sizeof(item));
    if(pi != NULL)
    {
	char c[] = "\0";
	setName(pi, c);
	setPrice(pi, 0);
	pi->remain_num = 0;
	pi->next = NULL;
    }
    return pi;
}

item *initList(void)
{
    item *tpi = constructItem();
    if(tpi != NULL)
    {
	char *write = tpi->name;
	for(int i = 0; i < NAMELEN; i++)
	{
	    *write = '\0';
	    write++;
	}
	tpi->price100 = 0;
	tpi->remain_num = 0;
	tpi->next = NULL;
    }
    else
    {
	printf("\n\nMemory overflow.\n\n\n");
    }
    return tpi;
}

void destroyItem(item *pi) // Dangerous! Use with a second concern.
{
    if(pi != NULL)
	free(pi);
}

void deleteItem(item *pi)// Actually this will delete the item after *pi and return the address of the next next item(*pi->next->next).
{
    if(pi != NULL)
    {
	item *tobeDeleted = pi->next;
	if(tobeDeleted != NULL)
	    pi->next = tobeDeleted->next;
	free(tobeDeleted);
    }
}

void destroyList(item *head)
{
    if(head != NULL)
    {
	while(head->next != NULL)
	{
	    deleteItem(head);
	}
	free(head);
    }
    else
    {
	printf("Error, delete void list.\n");
    }
}

int cmpstr6(char *str1, char *str2)
{
    int i;
    for(i = 0; i < NAMELEN && *str1 == *str2 && *str1 != '\0' && *str2 != '\0'; i++)
    {
	str1++;
	str2++;
    }
    if(i == NAMELEN || *str1 == *str2)
	return 0;
    else if(*str1 > *str2)
	return 1;
    else
	return -1;
}

int isRightPosition(item *pi, item *newItem)
{
    if(cmpstr6(pi->name, newItem->name) >= 0)
	return 1;
    else
	return 0; 
}

item *findPosition(item *head, item *newItem)// Actually find the item before the wanted item
{
    item *prevItem = NULL;
    while(head != NULL && !isRightPosition(head, newItem))
    {
	prevItem = head;
	head = head->next;
    }
    return prevItem;
}

int isExist(item *pos, item *newItem)
{
    if(pos->next != NULL && cmpstr6((pos->next)->name, newItem->name) == 0)
	return 1;
    else
	return 0;
}

void insertItem(item *insertPos, item *newItem)// Insert newItem after insertPos.
{
    if(insertPos != NULL)
    {
	newItem->next = insertPos->next;
	insertPos->next = newItem;
    }
    else
    {
	printf("Insertion can't be done, void target.\n");
    }
}



#endif
