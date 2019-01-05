#ifndef _DATABASE_H
#define _DATABASE_H

#include"clerkClient.h"

int is_valid_name(char *s);
void addRemain(item *p, int r);
item *constructItem(void);
item *initList(void);
void destroyItem(item *pi);// Dangerous! Use with a second concern.
void deleteItem(item *pi);// Actually this will delete the item after *pi and return the address of the next next item(*pi->next->next).
void destroyList(item *head);
int cmpstr6(char *str1, char *str2);
int isRightPosition(item *pi, item *newItem);
item *findPosition(item *head, item *newItem);// Actually find the item before the wanted item
int isExist(item *pos, item *newItem);
void insertItem(item *insertPos, item *newItem);// Insert newItem after insertPos.

#endif
