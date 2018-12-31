#ifndef _INTERFACE_C
#define _INTERFACE_C

#include<stdio.h>
#include"database.c"

void askcommand(int *pcommand)
{
    printf("enter command from options 1 to 6.\nCommand :");
    scanf("%d", pcommand);
}

void showName(item *p)
{
    char *s = p->name;
    for(int i = 0; i < 6 && *s != '\0'; i++, s++)
	printf("%c", *s);
}

int showList(item *head)
{
    int count = 0;
    if(head != NULL)
    {
	head = head->next;
	while(head != NULL)
	{
	    printf("Name : ");
	    showName(head);
	    printf("\nPrice : %d\nRemain : %d\n", head->price100, head->remain_num);
	    
	    for(int i = 0; i < 60; i++)
		printf("-");
	    printf("\n");
	    
	    count++;
	    head = head->next;
	}
    }
    return count;
}




#endif
