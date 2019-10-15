#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"clerkClient.h"
#include"database.c"
#include"interface.c"

//#define DEFAULT_TERMINAL_WIDTH 80
//#define DEFAULT_TERMINAL_HEIGHT 60

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
	while(command != 6)// if command is 6, sum up the expense and exit 
	{
	    printf("Please ")
		askcommand(&command);
	    if(command == 1)// Show current item
	    {
		showList(head);
	    }
	    else if(command == 2)// Add item
	    {
		
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
	}
	// sum up the expense
	printf("Exit program.\n");
	return 0;
    }
    else
    {
	printf("Your identify is not recorded, access denied.\n");
	return -1;
    }
}
    

