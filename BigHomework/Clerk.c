#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"clerkClient.h"
#include"database.c"
#include"interface.c"

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
	return -1;
    }
    else
    {
	procedure_welcome();
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
		procedure_receive_command(&command);
		if(command == 1)// Show list
		{
		    procedure_show_list(head);
		}
		else if(command == 2)// Add new item or change storage condition of existing item
		{   
		    backstage_new_item(&tpi);
		    procedure_name_item(tpi, command);
		    tPos = findPosition(head, tpi);
		    if(isExist(tPos, tpi))
		    {
			tPos = tPos->next;
			procedure_change_storage(tPos);
			backstage_destroy_item(tpi);
		    }
		    else
		    {
			procedure_ask_item_price_remain(tpi);
			backstage_insert_item(tPos, tpi);
		    }
		}
		else if(command == 3)// Delete item
		{
		    backstage_new_item(&tpi);
		    procedure_name_item(tpi, command);
		    tPos = findPosition(head, tpi);
		    if(isExist(tPos, tpi))
		    {
			procedure_delete_item(tPos);
			backstage_destroy_item(tpi);
		    }
		}
		else if(command == 4)// Search item
		{
		    backstage_new_item(&tpi);
		    procedure_name_item(tpi, command);
		    tPos = findPosition(head, tpi);
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
		}
		else if(command == 5)// Purchase item
		{
		    backstage_new_item(&tpi);
		    procedure_name_item(tpi, command);
		    tPos = findPosition(head, tpi);
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
		}
		else if(command != 6)// Wrong command
		{
		    procedure_wrong_command(command);
		}
		tpi = NULL;
		tPos = NULL;
	    }while(command != 6);
	    procedure_sum_expense(sumExpense);
	    procedure_exit();
	    return 0;
	}
    }
}

int is_authenticated(void)
{
    /*
      return 1;
     */
    int i;
    char a[7], passw[] = "000000", *p, *q;
    for(int try = 0; try < 3; try++)
    {
	
	scanf("%s", a);
	printf("%s", a);
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
    printf("access denied.\n");
    changePage();
}

void procedure_welcome(void)
{
    printf("Logged in.\nWelcome, operator.\n");
    changePage();
}

void procedure_receive_command(int *pcommand)
{
    printf("[Command]\n");
    askCommand(pcommand);
    changePage();
}

void procedure_show_list(item *head)
{
    printf("[Show list]\n");
    printf("There are %d items.\n", showList(head));
    changePage();
}

void procedure_name_item(item *pi, int command)
{
    printf("Scene %d.\n", command);
    char a[NAMELEN + 1];
    askName(a);
    setName(pi, a);
    changePage();
}

void procedure_change_storage(item *pi)
{
    int r;
    printf("[Change]\n");
    askRemain(&r);
    addRemain(pi, r);
    changePage();
}

void procedure_ask_item_price_remain(item *pi)
{
    int pri, rem;
    printf("[Price]\n");
    askPrice(&pri);
    setPrice(pi, pri);
    changePage();
    printf("[Remain]\n");
    askRemain(&rem);
    addRemain(pi, rem);
    changePage();
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
    showItem(pi);
    changePage();
}

void procedure_n_found_item(item *pi, int command)
{
    printf("scene %d\n", command);
    printf("Not found\n");
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

/*
int main()
{
    item *head = initList();
    if(head == NULL)
	return 1;
    else if(Authenticated())
    {
	int nItem;
	int sumPrice = 0;
	int command;
	item *tpi;
	while(command != 6)// if command is 6, sum up the expense and exit 
	{
	    system("clear");
	    outputIntro();
	    printf("Please ");
		askcommand(&command);
	    if(command == 1)// Show current item
	    {
		printf("There are %d items.\n", showList(head));
	    }
	    else if(command == 2)// Add item
	    {
		tpi = constructItem();
		if(tpi == NULL)
		{
		    printf("Memory overflow, can't construct new item.\n");
		    command = 6;
		}
		else
		{
		    char a[NAMELEN + 1];
		    askName(a);
		    setName(tpi, a);

		    item *insertPos = findPosition(head, tpi);
		    if(insertPos->next == NULL)
		    {
			setPrice(tpi, askPrice());
			addRemain(tpi, askRemain());
			insertItem(insertPos, tpi);// New
		    }
		    else
		    {

			int cmpresult = cmpstr6(tpi->name, (insertPos->next)->name);
			if(cmpresult == -1)
			{
			    setPrice(tpi, askPrice());
			    addRemain(tpi, askRemain());
			    insertItem(insertPos, tpi);// New
			}
			else
			{
			    if(cmpresult == 0)
			    {
				addRemain(insertPos->next, askChangeStorage());
			    }
			    else
			    {
				printf("[debug : insert]\n");
			    }
			    destroyItem(&tpi);
			}
		    }
		}
	    }
	    else if(command == 3)// Delete item 
	    {
		
	    }
	    else if(command == 4)// Search item
	    {
		
	    }
	    else if(command == 5)// Purchase item
	    {
		
	    }
	    else if(command != 6)// wrong command
	    {
		printf("Wrong command : %d. So, again, please ", command);
	    }
	    printf("Press [Enter] to proceed.\n");
	    getchar();
	}
	// sum up the expense
	destroyList(&head);
	printf("Exit program.\n");
	return 0;
    }
}
*/  

