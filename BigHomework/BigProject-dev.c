#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include<string.h>

#define NAMELEN 6	   				   
#define DEFAULT_TERMINAL_WIDTH 80
#define DEFAULT_TERMINAL_HEIGHT 60

#define CLEAR_SCREEN "clear"
//#define CLEAR_SCREEN "cls"

typedef struct item_info{  				   
    char name[NAMELEN];	   				   
    int price100;	   				   
    int remain_num;	   				   
    struct item_info *next;				   
}item;

//------ Special, line buffer.
#define BUF_LINE 20
char *cline[BUF_LINE];
//int lock[BUF_LINE];
int ml = 0;

void initLine(void)
{
    for(int i = 0; i < BUF_LINE; i++)
	cline[i] = (char*)malloc(sizeof(char) * (DEFAULT_TERMINAL_WIDTH + 1));
}

void destroyLine(void)
{
    for(int i = 0; i < BUF_LINE; i++)
	free(cline[i]);
}

void debug_buffer(void)
{
    for(int i = 0; i < BUF_LINE; i++)
    {
	for(int j = 0; j < DEFAULT_TERMINAL_WIDTH + 1; j++)
	    printf("%c", cline[i][j]);
	printf("[line]\n");
    }
    printf("[end][%d]\n", ml);
}
//------

int is_valid_name(char *s);
void addRemain(item *p, int r);
item *constructItem(void);
item *initList(void);
void destroyItem(item *pi);// Dangerous! Use with a second concern.
void deleteItem(item *pi);// Actually this will delete the item after *pi and return the address of the next next item(*pi->next->next).
void destroyList(item *head);
int cmpStrDig(int dig, char *str1, char *str2);
int isRightPosition(item *pi, item *newItem);
item *findPosition(item *head, item *newItem);// Actually find the item before the wanted item
int isExist(item *pos, item *newItem);
int isPart(item *pi, item *pi1);
void insertItem(item *insertPos, item *newItem);// Insert newItem after insertPos.
void namePlus(item *pi, int n);

void debugName(item *pi);

void absorbBlanc(void);
void changePage(void);
void changePage_silent(void);

char *constructStr(int n);
void destroyStr(char *s);
void outputTempStr(char *s);

char *dealName(char *s);// Need to be destoried later
void showName(item *p);
double tranPrice(int price100);
char *myStr(const char *const s);// Need to be destroied later
void vsnpItem(char *s, int len, ...);
char *itemchart(int count, item *pi);
char *putMiddle(char *s, char c, int desLen);
char *tranItem(int count, item *head);
void showItem(int count, item *head);

void edge_up(char line, char point, int width);
void edge_body(char *s, char line, int width);// s should be temp string.
void edge_down(char line, char point, int width);
int showList(item *head);

void page_auth(void);
void page_fail_init(void);
void page_rec_com(void);
void page_show_list(void);
void page_new_change(void);
void page_wrong_name(void);
void page_change(void);
void page_new_item(void);
void page_delete(void);
void page_search(void);
void page_purchase(void);
void page_wrong_command(void);
void page_sum(void);
void page_exit(void);

void backstage_insert_item(item *pPos, item *pNew);
void backstage_new_item(item **ppi);
void backstage_destroy_item(item *pi);
void backstage_destroy_list(item *head);

void interact_name_item(item *pi);
void interact_n_found(item *pi);

void procedure_authentication(int *is_auth);
void procedure_access_denied(void);
void procedure_welcome(void);
void procedure_fail_init(void);
void procedure_receive_command(int *pcommand);
void procedure_show_list(item *head);
void procedure_wrong_name(void);
void procedure_change_storage(item *pi);
void procedure_ask_item_price_remain(item *pi);
void procedure_delete_item(item *pi);
void procedure_found_item(item *pi, item *piEnd, item *key);
void procedure_purchase_item(item *pi, int *sumExpense);
void procedure_wrong_command(int command);
void procedure_sum_expense(int sumExpense);
void procedure_exit(void);

int main()
{
    initLine();
    int is_authenticated;
    procedure_authentication(&is_authenticated);
    if(!is_authenticated)
    {
	procedure_access_denied();
	destroyLine();
	return -1;
    }
    else
    {
	procedure_welcome();
	item *head = initList();
	if(head == NULL)
	{
	    procedure_fail_init();
	    destroyLine();
	    return 1;
	}
	else
	{
	    item *tpi, *tPos, *tPos1;
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
			if(isPart(tPos, tpi))
			{
			    namePlus(tpi, 1);
			    tPos1 = findPosition(tPos, tpi);
			    namePlus(tpi, -1);
			    procedure_found_item(tPos->next, tPos1, tpi);
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
		tPos1 = NULL;
	    }while(command != 6);
	    procedure_sum_expense(sumExpense);
	    procedure_exit();
	    backstage_destroy_list(head);
	    head = NULL;
	    destroyLine();
	    return 0;
	}
    }
}

int is_valid_name(char *s)
{
    return *s != '\0';
}

void addRemain(item *p, int r)
{
    p->remain_num = p->remain_num + r;
}

item *constructItem(void)
{
    item *pi;
    pi =  (item*)malloc(sizeof(item));
    if(pi != NULL)
    {
	*pi->name = '\0';
	pi->price100 = 0;
	pi->remain_num = 0;
	pi->next = NULL;
    }
    return pi;
}

item *initList(void)
{
    item *tpi = constructItem();
    if(tpi != NULL)
    {
	char *write = tpi->name;
	for(int i = 0; i < NAMELEN; i++)
	{
	    *write = '\0';
	    write++;
	}
	tpi->price100 = 0;
	tpi->remain_num = 0;
	tpi->next = NULL;
    }
    else
    {
	printf("\n\nMemory overflow.\n\n\n");
    }
    return tpi;
}

void destroyItem(item *pi)// Dangerous! Use with a second concern.
{
    if(pi != NULL)
	free(pi);   
}

void deleteItem(item *pi)// Actually this will delete the item after *pi and return the address of the next next item(*pi->next->next).
{
    if(pi != NULL)
    {
	item *tobeDeleted = pi->next;
	if(tobeDeleted != NULL)
	    pi->next = tobeDeleted->next;
	free(tobeDeleted);
    }
}

void destroyList(item *head)
{
    if(head != NULL)
    {
	while(head->next != NULL)
	{
	    deleteItem(head);
	}
	free(head);
    }
    else
    {
	printf("Error, delete void list.\n");
    }
}

int cmpStrDig(int dig, char *str1, char *str2)
{
    int i;
    for(i = 0; i < dig && *str1 == *str2 && *str1 != '\0' && *str2 != '\0'; i++)
    {
	str1++;
	str2++;
    }
    if(i == dig || (i < dig && *str1 == *str2))
	return 0;
    else if(*str1 > *str2)
	return 1;
    else
	return -1;
}

int isRightPosition(item *pi, item *newItem)
{
    if(cmpStrDig(NAMELEN, pi->name, newItem->name) >= 0)
	return 1;
    else
	return 0; 
}

item *findPosition(item *head, item *newItem)// Actually find the item before the wanted item
{
    item *prevItem = NULL;
    while(head != NULL && !isRightPosition(head, newItem))
    {
	prevItem = head;
	head = head->next;
    }
    return prevItem;
}

int isExist(item *pos, item *newItem)
{
    if(pos->next != NULL && cmpStrDig(NAMELEN, (pos->next)->name, newItem->name) == 0)
	return 1;
    else
	return 0;
}

int isPart(item *pos, item *key)
{
    if(pos->next != NULL)
    {
	pos = pos->next;
	int i;
	char *p = pos->name, *k = key->name;
	for(i = 0; i < NAMELEN && *p == *k && *p != '\0' && *k != '\0'; i++)
	{
	    p++;
	    k++;
	}
	if(i == NAMELEN || (i < NAMELEN && *k == '\0'))
	    return 1;
	else
	    return 0;
    }
    else
	return 0;
}

void insertItem(item *insertPos, item *newItem)// Insert newItem after insertPos.
{
    if(insertPos != NULL)
    {
	newItem->next = insertPos->next;
	insertPos->next = newItem;
    }
    else
    {
	printf("Insertion can't be done, void target.\n");
    }
}

void namePlus(item *pi, int n)
{
    char *s = pi->name;
    for(int i = 0; i < NAMELEN && *s != '\0'; i++)
    {
	s++;
    }
    *(s - 1) += n;
}

void debugName(item *pi)
{
    char *c = pi->name;
    printf("[");
    for(int i = 0; i < NAMELEN + 2; i++)
    {
	if(*c <= 32)
	  printf("[%d]", *c);
	else
	    printf("%c", *c);
	c++;
    }
    printf("]");
}

void absorbBlanc(void)
{
    char a;
    do
    {
	a = getchar();
    }while(a != '\n');
}

void changePage(void)
{
    printf("\nPress ENTER to proceed.");
    
    absorbBlanc();
    
    system(CLEAR_SCREEN);
}

void changePage_silent(void)
{
    system(CLEAR_SCREEN);
}

char *constructStr(int n)
{
    char *ts;
    if(ml < BUF_LINE)
    {
	ts = cline[ml];
	ml = ml + 1;
	return ts;
    }
    else
    {
	ml = 0;
	return constructStr(0);
    }
}

void destroyStr(char *s)
{
    /*
    if(s != NULL)
	free(s);
    else
	printf("Try to clear void string.\n");
    */
}

void outputTempStr(char *s)
{
    puts(s);
    destroyStr(s);
}

char *dealName(char *s)// Need to be destoried later
{
    char *ns, *tp;
    ns = constructStr(NAMELEN + 1);
    if(ns != NULL)
    {
	tp = ns;
	for(int i = 0; i < NAMELEN && *s != '\0'; i++)
	{
	    *tp = *s;
	    tp++;
	    s++;
	}
	*tp = '\0';
    }
    
    return ns;
}


void showName(item *p)
{
    char *s = p->name;
    for(int i = 0; i < 6 && *s != '\0'; i++, s++)
	printf("%c", *s);
}

double tranPrice(int price100)
{
    double lf = price100 / 100.000;
    return lf;
}

char *myStr(const char *r)// Need to be destroied later
{
    char *w;
    char *ns;
    ns = constructStr(NAMELEN + 1);

    if(ns != NULL)
    {
	w = ns;
	
	while(*r != '\0')
	{
	    *w = *r;
	    w++;
	    r++;
	}
	*w = '\0';
    }
    
    return ns;
}

void vsnpItem(char *s, int len, ...)
{
    va_list argum;
    va_start (argum, len);
    vsnprintf(s, len, "%-5d%15s%20.2lf%20d", argum);
    va_end(argum);
}

char *itemchart(int count, item *pi)
{
    char *s = constructStr(DEFAULT_TERMINAL_WIDTH + 1);
    if(s != NULL)
    {
	char *pName = dealName(pi->name);
	if(pName != NULL)
	{
	    vsnpItem(s, DEFAULT_TERMINAL_WIDTH, count, pName, tranPrice(pi->price100), pi->remain_num);
	    destroyStr(pName);
	}
    }
    return s;
}

char *putMiddle(char *s, char c, int desLen)
{
    int len = strlen(s);
    char *news, *ts, *r;
    if(len >= desLen)
    {
    	return s;
    }
    else
    {
    	news = constructStr(desLen + 1);
	if(news != NULL)
    	{
	    ts = news;
	    for(int i = 0; i < (desLen - len) / 2; i++)
	    {
		*ts = c;
		ts++;
	    }	
	    r = s;
	    for(int i = 0; i < len; i++)
	    {
		*ts = *r;
		ts++;
		r++;
	    }
	    for(int i = 0; i < (desLen - len + 1) / 2; i++)
	    {
		*ts = c;
		ts++;
	    }
	    *ts = '\0';
	    destroyStr(s);
	}
    	return news;
    }
}

char *tranItem(int count, item *head)
{
    if(head != NULL)
    {
	return itemchart(count, head);
    }
    else
    {
	printf("Try to show void item.\n");
	return NULL;
    }
}

void showItem(int count, item *head)
{
    char *ts = tranItem(count, head);
    if(ts != NULL)
    {
	outputTempStr(ts);
    }
}

void edge_up(char line, char point, int width)
{
    for(int i = 0; i < (DEFAULT_TERMINAL_WIDTH - width) / 2; i++)
	printf(" ");
    printf("%c", point);
    for(int i = 0; i < width - 2; i++)
	printf("%c", line);
    printf("%c\n", point);

    for(int i = 0; i < (DEFAULT_TERMINAL_WIDTH - width) / 2; i++)
	printf(" ");
    printf("%c", line);
    for(int i = 0; i < width - 2; i++)
	printf(" ");
    printf("%c\n", line);
}

void edge_body(char *s, char line, int width)// s should be temp string.
{
    outputTempStr(
	putMiddle(
	    putMiddle(
		putMiddle(
		    s,
		    ' ', width - 2),
		line, width),
	    ' ', DEFAULT_TERMINAL_WIDTH)
	    );
}

void edge_down(char line, char point, int width)
{
    for(int i = 0; i < (DEFAULT_TERMINAL_WIDTH - width) / 2; i++)
	printf(" ");
    printf("%c", line);
    for(int i = 0; i < width - 2; i++)
	printf(" ");
    printf("%c\n", line);

    for(int i = 0; i < (DEFAULT_TERMINAL_WIDTH - width) / 2; i++)
	printf(" ");
    printf("%c", point);
    for(int i = 0; i < width - 2; i++)
	printf("%c", line);
    printf("%c\n", point);
}

int showList(item *head)
{
    int count = 0;
    if(head == NULL)
    {
	printf("There is no list.\n");
    }
    else
    {
	head = head->next;
	if(head == NULL)
	    printf("Empty list!");
	else
	{
	    edge_up('=', '+', DEFAULT_TERMINAL_WIDTH - 6);
	    edge_body(myStr("    ID           Item code             Price       Remaining number     "), '=', DEFAULT_TERMINAL_WIDTH - 6);
	    edge_body(myStr("------------------------------------------------------------------------"), '=', DEFAULT_TERMINAL_WIDTH - 6);
	    while(head != NULL)
	    {
		count++;
		edge_body(tranItem(count, head), '=', DEFAULT_TERMINAL_WIDTH - 6);
		head = head->next;
	    }
	    edge_down('=', '+', DEFAULT_TERMINAL_WIDTH - 6);
	}
    }
    return count;
}

void page_auth(void)
{
    edge_up('#', '#', DEFAULT_TERMINAL_WIDTH);
    edge_body(myStr("Log in"), '#', DEFAULT_TERMINAL_WIDTH);
    edge_down('#', '#', DEFAULT_TERMINAL_WIDTH);
}

void page_fail_init(void)
{
    edge_up('#', '#', DEFAULT_TERMINAL_WIDTH);
    edge_body(myStr("Fail to initiate"), '#', DEFAULT_TERMINAL_WIDTH);
    edge_down('#', '#', DEFAULT_TERMINAL_WIDTH);
}

void page_rec_com(void)
{
    edge_up('#', '#', DEFAULT_TERMINAL_WIDTH);
    edge_body(myStr("1. Show storage"), '#', DEFAULT_TERMINAL_WIDTH);
    edge_body(myStr("2. New item /"), '#', DEFAULT_TERMINAL_WIDTH);
    edge_body(myStr("Change remain"), '#', DEFAULT_TERMINAL_WIDTH);
    edge_body(myStr("3. Delete item"), '#', DEFAULT_TERMINAL_WIDTH);
    edge_body(myStr("4. Search item"), '#', DEFAULT_TERMINAL_WIDTH);
    edge_body(myStr("5. Purchase item"), '#', DEFAULT_TERMINAL_WIDTH);
    edge_body(myStr("6. Accounting & Exit"),'#', DEFAULT_TERMINAL_WIDTH);
    edge_down('#', '#', DEFAULT_TERMINAL_WIDTH);		     
}

void page_show_list(void)
{
    edge_up('#', '#', DEFAULT_TERMINAL_WIDTH);
    edge_body(myStr("Show list"), '#', DEFAULT_TERMINAL_WIDTH);
    edge_down('#', '#', DEFAULT_TERMINAL_WIDTH);
}

void page_new_change(void)
{
    edge_up('#', '#', DEFAULT_TERMINAL_WIDTH);
    edge_body(myStr("Create new item / Manually change storage"), '#', DEFAULT_TERMINAL_WIDTH);
    edge_down('#', '#', DEFAULT_TERMINAL_WIDTH);
}

void page_wrong_name(void)
{
    edge_up('#', '#', DEFAULT_TERMINAL_WIDTH);
    edge_body(myStr("Wrong name"), '#', DEFAULT_TERMINAL_WIDTH);
    edge_down('#', '#', DEFAULT_TERMINAL_WIDTH);
}

void page_change(void)
{
    edge_up('#', '#', DEFAULT_TERMINAL_WIDTH);
    edge_body(myStr("Manually change storage"), '#', DEFAULT_TERMINAL_WIDTH);
    edge_down('#', '#', DEFAULT_TERMINAL_WIDTH);
}

void page_new_item(void)
{
    edge_up('#', '#', DEFAULT_TERMINAL_WIDTH);
    edge_body(myStr("Create new item"), '#', DEFAULT_TERMINAL_WIDTH);
    edge_down('#', '#', DEFAULT_TERMINAL_WIDTH);
}

void page_delete(void)
{
    edge_up('#', '#', DEFAULT_TERMINAL_WIDTH);
    edge_body(myStr("Delete item"), '#', DEFAULT_TERMINAL_WIDTH);
    edge_down('#', '#', DEFAULT_TERMINAL_WIDTH);
}

void page_search(void)
{
    edge_up('#', '#', DEFAULT_TERMINAL_WIDTH);
    edge_body(myStr("Search item"), '#', DEFAULT_TERMINAL_WIDTH);
    edge_down('#', '#', DEFAULT_TERMINAL_WIDTH);
}

void page_purchase(void)
{
    edge_up('#', '#', DEFAULT_TERMINAL_WIDTH);
    edge_body(myStr("Purchase"), '#', DEFAULT_TERMINAL_WIDTH);
    edge_down('#', '#', DEFAULT_TERMINAL_WIDTH);
}

void page_wrong_command(void)
{
    edge_up('#', '#', DEFAULT_TERMINAL_WIDTH);
    edge_body(myStr("Invalid command!"), '#', DEFAULT_TERMINAL_WIDTH);
    edge_down('#', '#', DEFAULT_TERMINAL_WIDTH);
}

void page_sum(void)
{
    edge_up('#', '#', DEFAULT_TERMINAL_WIDTH);
    edge_body(myStr("Sum expense"), '#', DEFAULT_TERMINAL_WIDTH);
    edge_down('#', '#', DEFAULT_TERMINAL_WIDTH);
}

void page_exit(void)
{
    edge_up('#', '#', DEFAULT_TERMINAL_WIDTH);
    edge_body(myStr("Exit"), '#', DEFAULT_TERMINAL_WIDTH);
    edge_down('#', '#', DEFAULT_TERMINAL_WIDTH);
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

void backstage_destroy_list(item *head)
{
    destroyList(head);
}

void interact_name_item(item *pi)
{   
    char *s = pi->name;

    printf("\n    Please enter the name of the item.\n    Item name :");
    scanf("%c", s);
    
    for(int i = 1; i < NAMELEN && *s != '\n' && *s != '\0'; i++)
    {
	s++;
	scanf("%c", s);
    }
    if(*s != '\n' && *s != '\0')
    	absorbBlanc();
    else
    	*s = '\0';
    
    s = pi->name;
    if(*s == '\0')
    {
	printf("\nInvalid input!\n");
	
	changePage();
    }
    else
    {   
    	changePage_silent();
    }
}

void interact_n_found(item *pi)
{
    printf("\n    The item :\n      ");
    outputTempStr(dealName(pi->name));
    printf("    does not exist.\n");
    
    changePage();
}

void procedure_authentication(int *is_auth)
{
    *is_auth = 0;
    int i;
    char a[7], passw[] = "000000", *p, *q;
    
    changePage_silent();
    page_auth();
	
    printf("\n    Please enter password.\n");
    
    for(int tr = 0; tr < 3 && *is_auth == 0; tr++)
    {
	printf("    PassWord :");
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
	{
	    *is_auth = 1;
	}
    }
    changePage_silent();
}

void procedure_access_denied(void)
{
    page_auth();
	
    printf("\n    Access denied.\n");
    
    changePage();
}

void procedure_welcome(void)
{
    page_auth();
	
    printf("\n    Logged in.\n    Welcome, operator.\n");
    
    changePage();
}

void procedure_fail_init(void)
{
    page_fail_init();
	
    printf("Failed to construct storage information database. Exit.\n");
    
    changePage();
}

void procedure_receive_command(int *pcommand)
{
    page_rec_com();
    
    printf("\n    enter command from options 1 to 6.\n    Command :");
    scanf("%d", pcommand);
    absorbBlanc();
    
    changePage_silent();    
}

void procedure_show_list(item *head)
{   
    page_show_list();
	
    printf("\n    There are %d items.\n", showList(head));
    
    changePage();
}


void procedure_wrong_name(void)
{
    page_wrong_name();
	
    printf("\n    Since the name is not valid, the operation has been aborted.\n");
    
    changePage();
}

void procedure_change_storage(item *pi)
{
    item i, *tpi;
    i.next = pi;
    tpi = pi->next;
    pi->next = NULL;
    int r;
    
    page_change();
    
    showList(&i);
    printf("\n    Please enter the number of item that will be added into storage.\n    Add :");
    scanf("%d", &r);
    absorbBlanc();
    addRemain(pi, r);
    printf("\n    the item will be changed into :\n");
    showList(&i);
    
    pi->next = tpi;

    changePage();
}

void procedure_ask_item_price_remain(item *pi)
{
    item i;
    i.next = pi;
    double price;
    int remain;
    
    page_new_item();
    printf("\n    Add price.\n\n");
    showList(&i);
    printf("\n    Please enter the price of the item.\n    Price :");
    scanf("%lf", &price);
    absorbBlanc();
    pi->price100 = (price + 0.0050) * 100;

    changePage_silent();
    
    page_new_item();
    printf("\n    Add remaining number.\n\n");
    showList(&i);
    printf("\n    Please enter the remaining number of item.\n    Remain :");
    scanf("%d", &remain);
    absorbBlanc();
    addRemain(pi, remain);
    
    changePage_silent();
    
    page_new_item();
    printf("\n    The following item has been added.\n\n");
    showList(&i);
	
    changePage();
}

void procedure_delete_item(item *pi)
{   
    item *tp = pi->next->next;
    pi->next->next = NULL;
    char c;
    
    page_delete();
    showList(pi);
    pi->next->next = tp;
    printf("\n    The item will be deleted. Are you sure to proceed? Please enter y/n.\n    [y]es or [n]o :");
    scanf("%c", &c);
    absorbBlanc();
    
    if(c == 'y')
    {
    	deleteItem(pi);
    	printf("\n    The item is deleted.\n");
    }
    else if(c == 'n')
    {
	printf("\n    Will not delete item.\n");
    }
    else 
    {
	printf("\nWrong input!\nOperation abort.\n");
    }
	
    changePage();
}



void procedure_found_item(item *pi, item *piEnd, item *key)
{
    char *tps = dealName(key->name);
    item i, *tpi = piEnd->next;
    i.next = pi;
    piEnd->next = NULL;
    
    page_search();
    printf("\n    Item %s has been found :\n\n", tps);
    showList(&i);
    piEnd->next = tpi;
    destroyStr(tps);
    
    changePage();
}

void procedure_purchase_item(item *pi, int *sumExpense)
{
    int buyNum, buyMon;
    item i, *tpi = pi->next;
    i.next = pi;
    pi->next = NULL;
    
    page_purchase();
    showList(&i);
    printf("\n    Please enter the number of purchase.\n    Number :");
    scanf("%d", &buyNum);
    absorbBlanc();
    if(buyNum > pi->remain_num)
    {
    	printf("\n    The remain number of item is not enough!\n    Will not purchase anything.\n");
    }
    else
    {
	buyMon = buyNum * pi->price100;   
    	pi->remain_num -= buyNum;
    	printf("\n    The item will be changed into :\n");
    	showList(&i);
	printf("\n    You need to pay : %.2lf + %.2lf = ", tranPrice(*sumExpense), tranPrice(buyMon));
	*sumExpense += buyNum * pi->price100;
	printf("%.2lf Yuan.\n", tranPrice(*sumExpense));
    }
    pi->next = tpi;
    
    changePage();
}

void procedure_wrong_command(int command)
{
    page_rec_com();
    printf("\n    Command %d is wrong!\n", command);
    
    changePage();
}

void procedure_sum_expense(int sumExpense)
{
    page_sum();
    printf("\n    The total expense is %.2lf Yuan.\n", tranPrice(sumExpense));
    
    changePage();
}

void procedure_exit(void)
{
    page_exit();
	
    changePage();
}



