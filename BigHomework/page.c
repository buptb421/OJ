#include<stdio.h>
#include<stdlib.h>

#include"clerkClient.h"
#include"database.c"
#include"interface.c"
    
void edge_up(char line, char point, int width)
{
    outputTempStr(putMiddle(putMiddle(myStr(""), line, width - 2), point, width));
    outputTempStr(putMiddle(putMiddle(myStr(""), ' ', width - 2), line, width));
}

void edge_body(char *s, char line, int width)
{
    outputTempStr(putMiddle(putMiddle(s, ' ', width - 2), line, width));
}

void edge_down(char line, char point, int width)
{
    outputTempStr(putMiddle(putMiddle(myStr(""), ' ', width - 2), line, width));
    outputTempStr(putMiddle(putMiddle(myStr(""), line, width - 2), point, width));
}
/*
void add_edge(char line, char point, int width, ...)
{
    
}
*/
void page_auth()
{
    char c = '#';
    changePage_silent();
    edge_up(c, c, DEFAULT_TERMINAL_WIDTH);
    edge_body(myStr("Log in"), c, DEFAULT_TERMINAL_WIDTH);
    edge_down(c, c, DEFAULT_TERMINAL_WIDTH);
}

void page_rec_com()
{
    char c = '#';
    edge_up(c, c, DEFAULT_TERMINAL_WIDTH);
    edge_body(myStr("1. Show storage"), c, DEFAULT_TERMINAL_WIDTH);
    edge_body(myStr("2. New item /"), c, DEFAULT_TERMINAL_WIDTH);
    edge_body(myStr("Change remaining"), c, DEFAULT_TERMINAL_WIDTH);
    edge_body(myStr("3. Delete item"), c, DEFAULT_TERMINAL_WIDTH);  
    edge_body(myStr("4. Search item"), c, DEFAULT_TERMINAL_WIDTH);
    edge_body(myStr("5. Purchase item"), c, DEFAULT_TERMINAL_WIDTH);
    edge_body(myStr("6. Account & Exit"), c, DEFAULT_TERMINAL_WIDTH);
    edge_down(c, c, DEFAULT_TERMINAL_WIDTH);
}
