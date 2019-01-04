#include<stdio.h>

#include"clerkClient.h"
#include"database.c"
#include"interface.c"
#include"page.c"

void procedure_authentication(int *is_auth)
{
    *is_auth = 0;
    printf("Please enter password.\n");
    int i;
    char a[7], passw[] = "Xltsb0", *p, *q;
    for(int try = 0; try < 3 && *is_auth == 0; try++)
    {
	printf("PassWord :");
	scanf("%s", a);
	getchar();
	p = passw;
	q = a;
	for(i = 0; i < 6 && *p == *q; i++)
	{
	    p++;
	    q++;
	}
	if(i == 6)
	    *is_auth = 1;
    }
    changePage_silent();
}

void procedure_access_denied(void)
{
    printf("\nAccess denied.\n");
    changePage();
}

void procedure_welcome(void)
{
    printf("\nLogged in.\nWelcome, operator.\n");
    changePage();
}

void procedure_receive_command(int *pcommand)
{
    printf("\n");
    
    askCommand(pcommand);
    changePage_silent();    
}

void procedure_show_list(item *head)
{   
    printf("There are %d items.\n", showList(head));
    changePage();
}

void procedure_name_item(item *pi)
{   
    char a[NAMELEN + 1];
    askName(a);
    if(*a == '\0')
    {
	printf("\nInvalid input!\n");
	changePage();
    }
    setName(pi, a);
    changePage_silent();
}

void procedure_wrong_name()
{
    printf("Since the name is not valid, the operation has been aborted.\n");
    changePage();
}

void procedure_change_storage(item *pi)
{
    int r;
    printf("[Change]\n");
    askRemain(&r);
    addRemain(pi, r);
    showItem(1, pi);

    changePage();
}

void procedure_ask_item_price_remain(item *pi)
{
    int pri, rem;
    askPrice(&pri);
    setPrice(pi, pri);

    changePage_silent();
    page_new_item();
    askRemain(&rem);
    addRemain(pi, rem);

    item temp;
    temp.next = pi;
    showList(&temp);

    changePage();
}

void procedure_delete_item(item *pi)
{
    printf("[Delete]\n");
    
    item *tp = pi->next->next;
    pi->next->next = NULL;
    showList(pi);

    pi->next->next = tp;
    deleteItem(pi);
    changePage();
}

void procedure_delete_n_found(item *pi)
{
    printf("[Delete not found]\n");
    changePage();
}

void procedure_found_item(item *pi)
{
    printf("[found]\n");
    showItem(1, pi);
    changePage();
}

void procedure_n_found_item(item *pi)
{
    printf("[Not found]");
    outputTempStr(dealName(pi->name));
    changePage();
}

void procedure_purchase_item(item *pi, int *sumExpense)
{
    int buyNum;
    printf("[purchase]\n");
    askPurchaseNum(&buyNum);
    *sumExpense += buyNum * pi->price100;
    pi->remain_num -= buyNum;
    changePage();
}

void procedure_wrong_command(int command)
{
    printf("[wrong command]\n");
    changePage();
}

void procedure_sum_expense(int sumExpense)
{
    printf("[sumup]\n");
    printf("The total expense is %d Yuan.", sumExpense);
    changePage();
}

void procedure_exit(void)
{
    printf("[exit]\n");
    changePage();
}
