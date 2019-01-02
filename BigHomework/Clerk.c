#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"clerkClient.h"
#include"database.c"
#include"interface.c"
#include"page.c"

int is_authenticated(void);
void procedure_access_denied(void);
void procedure_welcome(void);
void procedure_receive_command(int *pcommand);
void procedure_show_list(item *head);
void procedure_name_item(item *pi, int command);
void procedure_change_storage(item *pi);
void procedure_ask_item_price_remain(item *pi);
void procedure_delete_item(item *pi);
void procedure_found_item(item *pi);
void procedure_n_found_item(item *pi, int command);
void procedure_purchase_item(item *pi, int *sumExpense);
void procedure_wrong_command(int command);
void procedure_sum_expense(int sumExpense);
void procedure_exit(void);

void backstage_insert_item(item *pPos, item *pNew);
void backstage_new_item(item **ppi);
void backstage_destroy_item(item *pi);

int main()
{
    if(!is_authenticated())
    {
	procedure_access_denied();
	changePage();
	return -1;
    }
    else
    {
	procedure_welcome();
	changePage();
	
	item *head = initList();
	if(head == NULL)
	{
	    printf("Failed to construct storage information database. Exit.\n");
	    return 1;
	}
	else
	{
	  
	    item *tpi, *tPos;
	    int command = 6;
	    int sumExpense = 0;
	    
	    do
	    {
		page_rec_com();
		procedure_receive_command(&command);
		changePage_silent();
		
		if(command == 1)// Show list
		{
		    page_show_list();
		    procedure_show_list(head);
		    changePage();
		}
		else if(command == 2)// Add new item or change storage condition of existing item
		{
		    page_new_change();
		    
		    backstage_new_item(&tpi);
		    procedure_name_item(tpi, command);
		    tPos = findPosition(head, tpi);

		    chagePage_silent();
		    
		    if(isExist(tPos, tpi))
		    {
			page_change();
			
			tPos = tPos->next;
			procedure_change_storage(tPos);
			backstage_destroy_item(tpi);

			changePage();
		    }
		    else
		    {
			page_new_item();
			
			procedure_ask_item_price_remain(tpi);
			backstage_insert_item(tPos, tpi);

			changePage();
		    }
		}
		else if(command == 3)// Delete item
		{
		    page_delete();
		    
		    backstage_new_item(&tpi);
		    procedure_name_item(tpi, command);
		    tPos = findPosition(head, tpi);

		    changePage_silent();
		    page_delete();
		    
		    if(isExist(tPos, tpi))
		    {
			procedure_delete_item(tPos);
			backstage_destroy_item(tpi);	
		    }
		    else
		    {
			procedure_delete_n_found();
		    }
		    changePage();
		}
		else if(command == 4)// Search item
		{
		    page_search();
		    
		    backstage_new_item(&tpi);
		    procedure_name_item(tpi, command);
		    tPos = findPosition(head, tpi);

		    changePage_silent();
		    page_search();
		    
		    if(isExist(tPos, tpi))
		    {
			tPos = tPos->next;
			procedure_found_item(tPos);
		    }
		    else
		    {
			procedure_n_found_item(tpi, command);
		    }
		    backstage_destroy_item(tpi);
		    changePage();
		}
		else if(command == 5)// Purchase item
		{
		    page_purchase();
		    
		    backstage_new_item(&tpi);
		    procedure_name_item(tpi, command);
		    tPos = findPosition(head, tpi);

		    changePage_slent();
		    page_purchase();
		    
		    if(isExist(tPos, tpi))
		    {
			tPos = tPos->next;
			procedure_purchase_item(tPos, &sumExpense);
		    }
		    else
		    {
			procedure_n_found_item(tpi, command);
		    }
		    backstage_destroy_item(tpi);

		    changePage();
		}
		else if(command != 6)// Wrong command
		{
		    page_wrong_command();

		    procedure_wrong_command(command);

		    changePage();
		}
		tpi = NULL;
		tPos = NULL;
	    }while(command != 6);

	    page_sum();
	    procedure_sum_expense(sumExpense);
	    changePage();

	    page_exit();
	    procedure_exit();
	    changePage();
	    
	    backstage_destroy_list(head);
	    return 0;
	}
    }
}

int is_authenticated(void)
{
    changePage_silent();
    page_auth();
    
    printf("Please enter password.\n");
    int i;
    char a[7], passw[] = "Xltsb0", *p, *q;
    for(int try = 0; try < 3; try++)
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
	    return 1;
    }
    return 0;
}

void procedure_access_denied(void)
{
    printf("\nAccess denied.\n");
}

void procedure_welcome(void)
{
    printf("\nLogged in.\nWelcome, operator.\n");
}

void procedure_receive_command(int *pcommand)
{
    printf("\n\n\n");
    
    askCommand(pcommand);
}

void procedure_show_list(item *head)
{
    puts(putMiddle(myStr(""), '#', DEFAULT_TERMINAL_WIDTH));
    puts(putMiddle(putMiddle(myStr(""), ' ', DEFAULT_TERMINAL_WIDTH - 2),
		   '#', DEFAULT_TERMINAL_WIDTH));
    puts(putMiddle(putMiddle(myStr("Show storage"), ' ', DEFAULT_TERMINAL_WIDTH - 2),
		   '#', DEFAULT_TERMINAL_WIDTH));
    puts(putMiddle(putMiddle(myStr(""), ' ', DEFAULT_TERMINAL_WIDTH - 2),
		   '#', DEFAULT_TERMINAL_WIDTH));
    puts(putMiddle(myStr(""), '#', DEFAULT_TERMINAL_WIDTH));
    printf("\n");
    
    printf("There are %d items.\n", showList(head));
}

void procedure_name_item(item *pi, int command)
{
    puts(putMiddle(myStr(""), '#', DEFAULT_TERMINAL_WIDTH));
    puts(putMiddle(putMiddle(myStr(""), ' ', DEFAULT_TERMINAL_WIDTH - 2),
		   '#', DEFAULT_TERMINAL_WIDTH));
    if(command == 2)
    {
	puts(putMiddle(putMiddle(myStr("New item / Change remaining"), ' ', DEFAULT_TERMINAL_WIDTH - 2),
		       '#', DEFAULT_TERMINAL_WIDTH));
    }
    else if(command == 3)
    {
	puts(putMiddle(putMiddle(myStr("Delete item"), ' ', DEFAULT_TERMINAL_WIDTH - 2),
		       '#', DEFAULT_TERMINAL_WIDTH));
    }
    else if(command == 4)
    {
	puts(putMiddle(putMiddle(myStr("Search item"), ' ', DEFAULT_TERMINAL_WIDTH - 2),
		       '#', DEFAULT_TERMINAL_WIDTH));
    }
    else if(command == 5)
    {
	puts(putMiddle(putMiddle(myStr("Purchase item"), ' ', DEFAULT_TERMINAL_WIDTH - 2),
		       '#', DEFAULT_TERMINAL_WIDTH));
    }
    
    puts(putMiddle(putMiddle(myStr(""), ' ', DEFAULT_TERMINAL_WIDTH - 2),
		   '#', DEFAULT_TERMINAL_WIDTH));
    puts(putMiddle(myStr(""), '#', DEFAULT_TERMINAL_WIDTH));
    
    char a[NAMELEN + 1];
    askName(a);
    setName(pi, a);
}

void procedure_change_storage(item *pi)
{
    int r;
    printf("[Change]\n");
    askRemain(&r);
    addRemain(pi, r);
    showItem(1, pi);
}

void procedure_ask_item_price_remain(item *pi)
{
    int pri, rem;
    printf("[Price]\n");
    askPrice(&pri);
    setPrice(pi, pri);
    printf("[Remain]\n");
    askRemain(&rem);
    addRemain(pi, rem);
    showItem(1, pi);
}

void procedure_delete_item(item *pi)
{
    printf("[Delete]\n");
    deleteItem(pi);
    changePage();
}

void procedure_found_item(item *pi)
{
    printf("[found]\n");
    showItem(1, pi);
}

void procedure_n_found_item(item *pi, int command)
{
    printf("scene %d\n", command);
    printf("[Not found]\n");
}

void procedure_purchase_item(item *pi, int *sumExpense)
{
    int buyNum;
    printf("[purchase]\n");
    askPurchaseNum(&buyNum);
    *sumExpense += buyNum * pi->price100;
    pi->remain_num -= buyNum;
}

void procedure_wrong_command(int command)
{
    printf("[wrong command]\n");
}

void procedure_sum_expense(int sumExpense)
{
    printf("[sumup]\n");
    printf("The total expense is %d Yuan.", sumExpense);
}

void procedure_exit(void)
{
    printf("[exit]\n");
}

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

void backstage_destroy_list(item *head);
