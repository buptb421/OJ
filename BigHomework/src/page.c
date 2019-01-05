#include"page.h"

#include<stdlib.h>
#include<string.h>
#include<stdarg.h>

void page_auth(void)
{
    add_edge('#', '#', DEFAULT_TERMINAL_WIDTH,
	     myStr("Log in"),
	     NULL);
}

void page_fail_init(void)
{
	add_edge('+', '+', DEFAULT_TERMINAL_WIDTH,
		 myStr("Fail to initiate"),
		 NULL);
}

void page_rec_com(void)
{
    add_edge('#', '#', DEFAULT_TERMINAL_WIDTH,
	     myStr("1. Show storage"),
	     myStr("2. New item /"),
	     myStr("Change remain"),
	     myStr("3. Delete item"),
	     myStr("4. Search item"),
	     myStr("5. Purchase item"),
	     myStr("6. Accounting & Exit"),
	     NULL);
}

void page_show_list(void)
{
    add_edge('#', '#', DEFAULT_TERMINAL_WIDTH,
	     myStr("Show list"),
	     NULL);
}

void page_new_change(void)
{
    add_edge('#', '#', DEFAULT_TERMINAL_WIDTH,
	     myStr("Create new item / Manually change storage"),
	     NULL);
}

void page_wrong_name(void)
{
    add_edge('+', '+', DEFAULT_TERMINAL_WIDTH,
	     myStr("Wrong name"),
	     NULL);
}

void page_change(void)
{
    add_edge('#', '#', DEFAULT_TERMINAL_WIDTH,
	     myStr("Manually change storage"),
	     NULL);
}

void page_new_item(void)
{
    add_edge('#', '#', DEFAULT_TERMINAL_WIDTH,
	     myStr("Create new item"),
	     NULL);
}

void page_delete(void)
{
    add_edge('#', '#', DEFAULT_TERMINAL_WIDTH,
	     myStr("Delete item"),
	     NULL);
}

void page_search(void)
{
    add_edge('#', '#', DEFAULT_TERMINAL_WIDTH,
	     myStr("Search item"),
	     NULL);
}

void page_purchase(void)
{
    add_edge('#', '#', DEFAULT_TERMINAL_WIDTH,
    	 myStr("Purchase"),
	     NULL);
}

void page_wrong_command(void)
{
    add_edge('#', '#', DEFAULT_TERMINAL_WIDTH,
	     myStr("Invalid command!"),
	     NULL);
}

void page_sum(void)
{
    add_edge('#', '#', DEFAULT_TERMINAL_WIDTH,
	     myStr("Sum expense"),
	     NULL);
}

void page_exit(void)
{
    add_edge('#', '#', DEFAULT_TERMINAL_WIDTH,
	     myStr("Exit"),
	     NULL);
}

