#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"clerkClient.h"
#include"database.c"
#include"interface.c"

int Authenticated()
{
    return 1;
}



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
    else
    {
	printf("Your identify is not recorded, access denied.\n");
	return -1;
    }
}
    

