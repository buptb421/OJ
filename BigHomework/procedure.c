#include<stdio.h>

#include"clerkClient.h"
#include"database.c"
#include"interface.c"
#include"page.c"

void backstage_insert_item(item *pPos, item *pNew)
{
    insertItem(pPos, pNew);
}

void backstage_new_item(item **ppi)
{
    *ppi = constructItem();
}

void backstage_destroy_item(item *pi)
{
    destroyItem(pi);
} 

void backstage_destroy_list(item *head)
{
    destroyList(head);
}

void procedure_authentication(int *is_auth)
{
    *is_auth = 0;
    int i;
    char a[7], passw[] = "000000", *p, *q;
    
	changePage_silent();
	page_auth();
	
    printf("\n    Please enter password.\n");
    
    for(int try = 0; try < 3 && *is_auth == 0; try++)
    {
		printf("    PassWord :");
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
		{
	    	*is_auth = 1;
	    }
    }
	changePage_silent();
}

void procedure_access_denied(void)
{
	page_auth();
	
    printf("\n    Access denied.\n");
    
    changePage();
}

void procedure_welcome(void)
{
	page_auth();
	
    printf("\n    Logged in.\n    Welcome, operator.\n");
    
    changePage();
}

void procedure_fail_init()
{
	page_fail_init();
	
	printf("Failed to construct storage information database. Exit.\n");
	
	changePage();
}

void procedure_receive_command(int *pcommand)
{
    page_rec_com();
    
    printf("\n    enter command from options 1 to 6.\n    Command :");
    scanf("%d", pcommand);
    absorbBlanc();
    
    changePage_silent();    
}

void procedure_show_list(item *head)
{   
	page_show_list();
	
    printf("\n    There are %d items.\n", showList(head));
    
    changePage();
}

void procedure_name_item(item *pi)
{   
    char *s = pi->name;

    printf("\n    Please enter the name of the item.\n    Item name :");
    scanf("%c", s);
    
    for(int i = 1; i < NAMELEN && *s != '\n' && *s != '\0'; i++)
    {
		s++;
		scanf("%c", s);
    }
    if(*s != '\n' && *s != '\0')
    	absorbBlanc();
    else
    	*s = '\0';

	s = pi->name;
    if(*s == '\0')
    {
		printf("\nInvalid input!\n");
		
		changePage();
    }
    else
    {   
    	changePage_silent();
	}
}

void procedure_wrong_name()
{
	page_wrong_name();
	
    printf("\n    Since the name is not valid, the operation has been aborted.\n");
    
    changePage();
}

void procedure_change_storage(item *pi)
{
	item i, *tpi;
	i.next = pi;
	tpi = pi->next;
	pi->next = NULL;
    int r;
    
	page_change();
	
	showList(&i);
    printf("\n    Please enter the number of item that will be added into storage.\n    Add :");
    scanf("%d", &r);
    absorbBlanc();
    addRemain(pi, r);
    printf("\n    the item will be changed into :\n");
    showList(&i);
    
    pi->next = tpi;

    changePage();
}

void procedure_ask_item_price_remain(item *pi)
{
	item i;
	i.next = pi;
	double price;
	int remain;
	
	page_new_item();
	printf("\n    Add price.\n\n");
	showList(&i);
    printf("\n    Please enter the price of the item.\n    Price :");
    scanf("%lf", &price);
    absorbBlanc();
    pi->price100 = (price + 0.005) * 100;

    changePage_silent();
    
    page_new_item();
    printf("\n    Add remaining number.\n\n");
    showList(&i);
    printf("\n    Please enter the remaining number of item.\n    Remain :");
    scanf("%d", &remain);
    absorbBlanc();
    addRemain(pi, remain);
    
    changePage_silent();
    
    page_new_item();
    printf("\n    The following item has been added.\n\n");
    showList(&i);
	
    changePage();
}

void procedure_delete_item(item *pi)
{   
	item *tp = pi->next->next;
    pi->next->next = NULL;
    char c;
    
	page_delete();
    showList(pi);
	pi->next->next = tp;
	printf("\n    The item will be deleted. Are you sure to proceed? Please enter y/n.\n    [y]es or [n]o :");
	scanf("%c", &c);
	absorbBlanc();
    
    if(c == 'y')
    {
    	deleteItem(pi);
    	printf("\n    The item is deleted.\n");
	}
	else if(c == 'n')
	{
		printf("\n    Will not delete item.\n");
	}
	else 
	{
		printf("\nWrong input!\nOperation abort.\n");
	}
	
    changePage();
}

void procedure_n_found(item *pi)
{
	printf("\n    The item :\n      ");
    outputTempStr(dealName(pi->name));
    printf("    does not exist.\n");
    
    changePage();
}

void procedure_found_item(item *pi)
{
	item i, *tpi = pi->next;
	pi->next = NULL;
	
	page_search();
    printf("\n    Item has been found :\n\n");
    showList(&i);
    pi->next = tpi;
    
    changePage();
}

void procedure_purchase_item(item *pi, int *sumExpense)
{
    int buyNum;
    item i, *tpi = pi->next;
    i.next = pi;
    
    page_purchase();
    showList(&i);
    printf("\n    Please enter the number of purchase.\n    Number :");
    scanf("%d", &buyNum);
    absorbBlanc();
    if(buyNum > pi->remain_num)
    {
    	printf("\n    The remain number of item is not enough!\n    Will not purchase anything.\n");
	}
	else
	{
		*sumExpense += buyNum * pi->price100;
    	pi->remain_num -= buyNum;
    	printf("\n    The item will be changed into :\n");
    	showList(&i);
	}
    pi->next = tpi;
    
    changePage();
}

void procedure_wrong_command(int command)
{
	page_rec_com();
    printf("\n    Command %d is wrong!\n", command);
    
    changePage();
}

void procedure_sum_expense(int sumExpense)
{
   	page_sum();
    printf("\n    The total expense is %.2lf Yuan.", tranPrice(sumExpense));
    
    changePage();
}

void procedure_exit(void)
{
	page_exit();
    changePage();
}
