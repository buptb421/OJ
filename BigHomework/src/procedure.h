#ifndef _PROCEDURE_H
#define _PROCEDURE_H

#include"clerkClient.h"
#include"database.h"
#include"interface.h"
#include"page.h"

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
void procedure_found_item(item *pi);
void procedure_purchase_item(item *pi, int *sumExpense);
void procedure_wrong_command(int command);
void procedure_sum_expense(int sumExpense);
void procedure_exit(void);

#endif
