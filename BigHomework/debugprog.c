#include<stdio.h>

#include"clerkClient.h"
#include"database.c"
#include"interface.c"

int main()
{
    item *p = initList();
    p->next = constructItem();
    char a[] = "abcd";
    setName(p->next, a);
    setPrice(p->next, 100);
    addRemain(p->next, 10);

    printf("There is %d items in storage.\n", showList(p));
    
    destroyList(&p);
    return 0;
}
