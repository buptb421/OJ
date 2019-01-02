#include<stdio.h>
#include<stdlib.h>

#include"clerkClient.h"
#include"database.c"
#include"interface.c"
    
void edge_up(char c, int width)
{
    outputTempStr(putMiddle(myStr(""), c, width));
    outputTempStr(putMiddle(putMiddle(myStr(""), ' ', width - 2), c, width));
}

void edge_body(char *s, char c, int width)
{
    outputTempStr(putMiddle(putMiddle(s, ' ', width - 2), c, width));
}

void edge_down(char c, int width)
{
    outputTempStr(putMiddle(putMiddle(myStr(""), ' ', width - 2), c, width));
    outputTempStr(putMiddle(myStr(""), c, width));
}

void page_auth()
{
    edge_up('#', DEFAULT_TERMINAL_WIDTH);
    edge_body(myStr("Log in"), '#', DEFAULT_TERMINAL_WIDTH);
    edge_down('#', DEFAULT_TERMINAL_WIDTH);
}

void page_rec_com()
{
    char c = '#';
    edge_up(c, DEFAULT_TERMINAL_WIDTH);
    edge_body(myStr("1. Show storage"), c, DEFAULT_TERMINAL_WIDTH);
    edge_body(myStr("2. New item /"), c, DEFAULT_TERMINAL_WIDTH);
    edge_body(myStr("Change remaining"), c, DEFAULT_TERMINAL_WIDTH);
    edge_body(myStr("3. Delete item"), c, DEFAULT_TERMINAL_WIDTH);  
    edge_body(myStr("4. Search item"), c, DEFAULT_TERMINAL_WIDTH);
    edge_body(myStr("5. Purchase item"), c, DEFAULT_TERMINAL_WIDTH);
    edge_body(myStr("6. Account & Exit"), c, DEFAULT_TERMINAL_WIDTH);
    edge_down(c, DEFAULT_TERMINAL_WIDTH);
}
