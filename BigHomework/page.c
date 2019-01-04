#ifndef _PAGE_C
#define _PAGE_C

#include<stdio.h>
#include<stdlib.h>

#include"clerkClient.h"
#include"database.c"
#include"interface.c"   

void page_auth(void)
{
    add_edge('#', '#', DEFAULT_TERMINAL_WIDTH,
	     "Log in",
	     NULL);
}

void page_rec_com(void)
{
    add_edge('#', '#', DEFAULT_TERMINAL_WIDTH,
	     "1. Show storage",
	     "2. New item /",
	     "Change remain",
	     "3. Delete item",
	     "4. Search item",
	     "5. Purchase item",
	     "6. Accounting & Exit",
	     NULL);
}

void page_show_list(void)
{
    add_edge('#', '#', DEFAULT_TERMINAL_WIDTH,
	     "Show list",
	     NULL);
}

void page_new_change(void)
{
    add_edge('#', '#', DEFAULT_TERMINAL_WIDTH,
	     "Create new item / Manually change storage",
	     NULL);
}

void page_wrong_name(void)
{
    add_edge('+', '+', DEFAULT_TERMINAL_WIDTH,
	     "Wrong name",
	     NULL);
}

void page_change(void)
{
    add_edge('#', '#', DEFAULT_TERMINAL_WIDTH,
	     "Manually change storage",
	     NULL);
}

void page_new_item(void)
{
    add_edge('#', '#', DEFAULT_TERMINAL_WIDTH,
	     "Create new item",
	     NULL);
}

void page_delete(void)
{
    add_edge('#', '#', DEFAULT_TERMINAL_WIDTH,
	     "Delete item",
	     NULL);
}

void page_search(void)
{
    add_edge('#', '#', DEFAULT_TERMINAL_WIDTH,
	     "Search item",
	     NULL);
}

void page_purchase(void)
{
    add_edge('#', '#', DEFAULT_TERMINAL_WIDTH,
	     "Purchase",
	     NULL);
}

void page_wrong_command(void)
{
    add_edge('#', '#', DEFAULT_TERMINAL_WIDTH,
	     "Invalid command!",
	     NULL);
}

void page_sum(void)
{
    add_edge('#', '#', DEFAULT_TERMINAL_WIDTH,
	     "Sum expense",
	     NULL);
}

void page_exit(void)
{
    add_edge('#', '#', DEFAULT_TERMINAL_WIDTH,
	     "Exit",
	     NULL);
}

#endif
