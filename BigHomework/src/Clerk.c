#include"Clerk.h"

#include<stdlib.h>

int main()
{
    int is_authenticated;
    procedure_authentication(&is_authenticated);
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
			procedure_fail_init();
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
					page_new_change();
					
		    		backstage_new_item(&tpi);
		    		interact_name_item(tpi);
		    		
		    		if(!is_valid_name(tpi->name))
		    		{
						procedure_wrong_name();
						backstage_destroy_item(tpi);
		    		}
		    		else
		    		{
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
				}
				else if(command == 3)// Delete item
				{   
					page_delete();
					
		    		backstage_new_item(&tpi);
		    		interact_name_item(tpi);
		    		if(!is_valid_name(tpi->name))
		    		{
						procedure_wrong_name();
		    		}
		    		else
		    		{
						tPos = findPosition(head, tpi);
						if(isExist(tPos, tpi))
						{
			    			procedure_delete_item(tPos);
						}
						else
						{
							page_delete();
							
			    			interact_n_found(tpi);
						}
		    		}
		    		backstage_destroy_item(tpi);
				}
				else if(command == 4)// Search item
				{
					page_search();
					
		    		backstage_new_item(&tpi);
		    		interact_name_item(tpi);
		    		if(!is_valid_name(tpi->name))
		    		{
						procedure_wrong_name();
		    		}
		    		else
		    		{
						tPos = findPosition(head, tpi);
						if(isExist(tPos, tpi))
						{
			    			tPos = tPos->next;
			    			procedure_found_item(tPos);
						}
						else
						{
							page_search();
							
			    			interact_n_found(tpi);
						}
		    		}
		    		backstage_destroy_item(tpi);
				}
				else if(command == 5)// Purchase item
				{
					page_purchase();
					
		    		backstage_new_item(&tpi);
		    		interact_name_item(tpi);
		    		if(!is_valid_name(tpi->name))
		    		{
						procedure_wrong_name();
		    		}
		    		else
		    		{
						tPos = findPosition(head, tpi);
						if(isExist(tPos, tpi))
						{
			    			tPos = tPos->next;
			    			procedure_purchase_item(tPos, &sumExpense);
						}
						else
						{
							page_purchase();
			    			interact_n_found(tpi);
						}
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
			backstage_destroy_list(head);
			head = NULL;
			return 0;
		}
	}
}


