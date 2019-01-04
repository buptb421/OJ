#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"clerkClient.h"
#include"database.c"
#include"interface.c"
#include"procedure.c"
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

int main()
{
    int is_authenticated;

    changePage_silent();
    page_auth();
    procedure_authentication(&is_authenticated);

    page_auth();
    if(!is_authenticated)
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
		page_rec_com();
		procedure_receive_command(&command);
		
		if(command == 1)// Show list
		{
		    page_show_list();
		    procedure_show_list(head);
		}
		else if(command == 2)// Add new item or change storage condition of existing item
		{
		    page_new_change();
		    
		    backstage_new_item(&tpi);
		    procedure_name_item(tpi);
		    
		    if(!is_valid_name(tpi->name))
		    {
			page_wrong_name();
			procedure_wrong_name();
			backstage_destroy_item(tpi);
		    }
		    else
		    {
			tPos = findPosition(head, tpi);
			
			if(isExist(tPos, tpi))
			{
			    page_change();
			    
			    tPos = tPos->next;
			    procedure_change_storage(tPos);
			    backstage_destroy_item(tpi);
			}
			else
			{
			    page_new_item();
			    
			    procedure_ask_item_price_remain(tpi);
			    backstage_insert_item(tPos, tpi);
			}
		    }
		}
		else if(command == 3)// Delete item
		{
		    page_delete();
		    
		    backstage_new_item(&tpi);
		    procedure_name_item(tpi);
		    
		    if(!is_valid_name(tpi->name))
		    {
			page_wrong_name();
			procedure_wrong_name();
		    }
		    else
		    {
			tPos = findPosition(head, tpi);
			
			page_delete();
			
			if(isExist(tPos, tpi))
			{
			    procedure_delete_item(tPos);
			}
			else
			{
			    procedure_delete_n_found(tpi);
			}
		    }
		    backstage_destroy_item(tpi);
		}
		else if(command == 4)// Search item
		{
		    page_search();
		    
		    backstage_new_item(&tpi);
		    procedure_name_item(tpi);
		    if(!is_valid_name(tpi->name))
		    {
			page_wrong_name();
			procedure_wrong_name();
		    }
		    else
		    {
			tPos = findPosition(head, tpi);
			
			page_search();
			
			if(isExist(tPos, tpi))
			{
			    tPos = tPos->next;
			    procedure_found_item(tPos);
			}
			else
			{
			    procedure_n_found_item(tpi);
			}
		    }
		    backstage_destroy_item(tpi);
		}
		else if(command == 5)// Purchase item
		{
		    page_purchase();
		    
		    backstage_new_item(&tpi);
		    procedure_name_item(tpi);

		    if(!is_valid_name(tpi->name))
		    {
			page_wrong_name();
			procedure_wrong_name();
		    }
		    else
		    {
			tPos = findPosition(head, tpi);
			
			page_purchase();
			
			if(isExist(tPos, tpi))
			{
			    tPos = tPos->next;
			    procedure_purchase_item(tPos, &sumExpense);
			}
			else
			{
			    procedure_n_found_item(tpi);
			}
		    }
		    backstage_destroy_item(tpi);
		}
		else if(command != 6)// Wrong command
		{
		    page_wrong_command();

		    procedure_wrong_command(command);
		}
		tpi = NULL;
		tPos = NULL;
	    }while(command != 6);

	    page_sum();
	    procedure_sum_expense(sumExpense);

	    page_exit();
	    procedure_exit();
	    
	    backstage_destroy_list(head);
	    head = NULL;
	    
	    return 0;
	}
    }
}

