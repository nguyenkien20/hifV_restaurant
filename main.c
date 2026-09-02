#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> // time for check in check out
#include "admin.h"

#define ADMIN_MENU 5
#define INVENTORY_SIZE (sizeof(inventory_manage_admin) / sizeof(inventory_manage_admin[0]))
#define CUSTOMER_SIZE (sizeof(customer_manage_admin) / sizeof(customer_manage_admin[0]))
#define DISCOUNT_SIZE (sizeof(discount_manage_admin) / sizeof(discount_manage_admin[0]))
#define CUSTOMER_PANEL (sizeof(customer_view) / sizeof(customer_view[0]))

// inventory_admin_views
const role_t inventory_manage_admin[4] = {{"Open inventory display", inventory_display},
                                          {"Add more item", item_add},
                                          {"Update item", item_update},
                                          {"Remove item", item_remove}};
// customer_admin_view
const role_t customer_manage_admin[4] = {{"Display all customers", customer_display},
                                         {"Add customer", customer_add},
                                         {"Remove customer", customer_remove},
                                         {"Customer's reserve", admin_view_customer_reserved}};
// discount_admin_view
const role_t discount_manage_admin[3] = {{"Display all discount", discount_display},
                                         {"Add discount", discount_add},
                                         {"Remove discount", discount_remove}};
/*CUSTOMER RESERVATION PANEL*/
const role_t customer_view[6] = {{"Reserved my table", reserve_table},
                                 {"See my reservation", see_my_reservation},
                                 {"Update my reservation", customer_reserved_update},
                                 {"Cancel my reservation", customer_reserved_cancel},
                                 {"Display menu", customer_menu_display},
                                 {"View available table", view_available_tables}};

int main()
{
    state_t state = STATE_HOME; // state = 0; meaning the program in main home

    while (state != STATE_EXIT)
    {
        switch (state)
        {
        case STATE_HOME:
            state = main_board(); // state receive value from main_board
            break;
        case STATE_ADMIN:
            state = adminPanel();
            break;
        case STATE_ADMIN_MENU:
            state = admin_menu_panel();
            break;
        case STATE_CUSTOMER:
            state = customerPanel();
            break;
        case STATE_CUSTOMER_MENU:
            state = customer_menu_panel();
        default:
            state = STATE_EXIT;
            break;
        }
    }
    printf("Exit the program!\n");
    return 0;
}
state_t main_board()
{
    char role[MAX_CHAR];
    int get_value = 0;
label_1:
    printf("---------------------------------\n");
    printf("Welcome to the HifV restaurant!\n");
    printf("---------------------------------");
    printf("\nYou are??\n");
    printf("1. Admin (enter admin)\n");
    printf("2. Customer (enter customer)\n");
    printf("3. Exit (enter exit) to end the program\n");
    printf("Enter your choice: \n");
    scanf("%10s", role);
    if (strcmp(role, "admin") == 0)
    {
        return STATE_ADMIN;
    }
    else if ((strcmp(role, "customer") == 0))
    {
        return STATE_CUSTOMER;
    }
    else if (strcmp(role, "exit") == 0)
    {
        return STATE_EXIT;
    }
    else
    {
        printf("---------------------------------");
        printf("---PLEASE TRY AGAIN AND AGAIN!---\n");
        printf("---------------------------------");
        return STATE_HOME;
    }
}
///////////////////////////////////////////////////////////////////
state_t adminPanel()
{
    admin_t admin1; // max admin account is 10
    unsigned int choose1 = 0, choose2 = 0;
    printf("\n-----------------------------\n");
    printf("----WELCOME TO ADMIN PANEL!----\n");
    printf("-----------------------------\n");
    printf("1.Sign in?\n");
    printf("2.Create a new admin account!\n");
    printf("3.Back to main board\n");
    printf("-----------------------------\n");
    printf("Enter your choice:\n");
    while (scanf("%u", &choose1) != 1 || choose1 < 1 || choose1 > 3) // nhap gia tri thanh cong ham scanf tra ve 1
    {
        printf("Must choose 1, 2 or 3!!\n");
        while (getchar() != '\n')
            ;
    }
    if (choose1 == 1)
    {
        admin_login();
        return STATE_ADMIN_MENU;
    }
    else if (choose1 == 2)
    {
        admin_create_account();
        return STATE_ADMIN;
    }
    else if (choose1 == 3)
    {
        return STATE_HOME;
    }
    else
    {
        printf("---------------------------------");
        printf("---PLEASE TRY AGAIN AND AGAIN!---\n");
        printf("---------------------------------");
        return STATE_ADMIN;
    }
}
// customer ///
///////////////////////////////////////////////////////////////////
state_t customerPanel()
{
    unsigned int choose1 = 0;
    printf("\nWELCOME TO CUSTOMER PANEL!\n");
    printf("--------------------------\n");
    printf("1.Sign in?\n");
    printf("2.Create a new customer account!\n");
    printf("3. Exit to home page\n");
    printf("--------------------------\n");
    printf("Enter your choice:\n");
    while (scanf("%u", &choose1) != 1 || choose1 < 1 || choose1 > 3)
    {
        printf("Please enter value form 1 to 3!!: \n");
        while (getchar() != '\n')
            ;
    }
    if (choose1 == 1)
    {
        customer_login();
        printf("Login succesfully!!!\n");
        return STATE_CUSTOMER_MENU;
    }
    else if (choose1 == 2)
    {
        customer_create_account();
        return STATE_CUSTOMER;
    }
    else if (choose1 == 3)
    {
        return STATE_HOME;
    }
    // return
}
///////////////////////////////////////////////////////////////////
// SHOULD CHANGE RETURN TYPE OF item_add to void ();
void item_add()
{
    int quantity = 0;
    printf("Enter a item's number to store:\n");
    scanf("%d", &quantity);
    for (int i = 0; i < quantity; i++)
    {
        printf("Enter item %d's id: \n", i + 1);
        // scanf("%19s", (pAdd + i)->id);
        printf("Enter item %d's name: \n", i + 1);
        // scanf("%49s", (pAdd + i)->name);
        printf("Enter item %d's price: \n", i + 1);
        // scanf("%lf", &((pAdd + i)->price));
        printf("Enter item %d's quantity: \n", i + 1);
        // scanf("%d", &((pAdd + i)->quantity));
    }
    // printf("\nSTT\tID\tNAME\tPRICE\tQUANTITY\n");
    // for (int i = 0; i < quantity; i++)
    // {
    //     printf("%d\t%s\t%s\t%.2lf\t%d\n", i + 1, ((pAdd + i)->id), ((pAdd + i)->name), ((pAdd + i)->price), ((pAdd + i)->quantity));
    // }
}
void inventory_display()
{
    printf("Success\n");
    printf("Those item in store is:\n");
}

void admin_login()
{
    int flag = 0;
    item_t items[100]; // list maximum 100 items
    printf("---Authentication For Admin---\n");
    // must create a logic login
    printf("enter admin username:\n");
    // fgets(username, sizeof(username), stdin); co the su dung de nhap chuoi
    // username[ strcspn( username, "\n" ) ] = '\0';
    // scanf("%49s", (pAdmin)->username);
    printf("enter admin password:\n");
    // scanf("%49s", (pAdmin)->password);
}
void customer_login()
{
    printf("---Authentication For Customer---\n");
    printf("enter a customer username:\n");
    printf("enter customer password:\n");
}

void admin_create_account()
{
    printf("enter an admin account name: \n");
    printf("enter a password\n");
    printf("enter one again password\n");
}

void customer_create_account()
{
    printf("enter an customer account name: \n");
    printf("enter a password\n");
    printf("enter one again password\n");
}
void menu_display(const role_t *pMenu, int size)
{
    uint8_t choose_index = 0;
    printf("\n------PANEL CONTROL------\n");
    for (uint8_t i = 0; i < size; i++)
    {
        printf("%d. %s\n", i + 1, (pMenu + i)->label);
    }
    printf("Enter a number to open: \n");
    while (scanf("%" SCNu8, &choose_index) != 1 || choose_index < 1 || choose_index > size) // nhap gia tri thanh cong ham scanf tra ve 1
    {
        printf("Please enter value form %d to %d\n", 1, size);
        while (getchar() != '\n')
            ;
    }
    // user enter choose_index = 3;
    menu_choose(pMenu, choose_index);
}
void menu_choose(const role_t *pMenu, uint8_t choose_index)
{
    choose_index -= 1;                 // minux 1 because choose_index != array implement_index
    (pMenu + choose_index)->handler(); // <----- remember have ()
}
void item_update()
{
}
void item_remove()
{
}
void customer_display()
{
}
void customer_add()
{
}
void customer_remove()
{
}
void discount_display()
{
}
void discount_add()
{
}
void discount_remove()
{
}
void reserve_table()
{
}
void see_my_reservation()
{
}
void customer_reserved_update()
{
}
void customer_reserved_cancel()
{
}
void customer_menu_display()
{
}
void view_available_tables()
{
}
void inventory_manage(const role_t *pInventory, int size)
{
    printf("INVENTORY MANAGEMENT ADMIN'S VIEW");
    menu_display(pInventory, size);
}
void customer_manage(const role_t *pCustomer, int size)
{
    printf("CUSTOMER MANAGEMENT ADMIN'S VIEW");
    menu_display(pCustomer, size);
}
void admin_view_customer_reserved()
{
}
void discount_manage(const role_t *pDiscount, int size)
{
    printf("DISCOUNT MANAGEMENT ADMIN'S VIEW");
    menu_display(pDiscount, size);
}
void item_current()
{
}

void admin_change_credentials()
{
    printf("please enter old account");
    printf("please enter old password");
    printf("please enter new password");
}
state_t admin_menu_panel()
{
    int choose = 0;
    printf("--ADMIN MENU PANEL--\n");
    printf("1. Manage inventory!\n");
    printf("2. Manage customers!\n");
    printf("3. Manage discount!\n");
    printf("4. Change admin credentials!\n");
    printf("5. Exit admin menu\n");
    printf("----------------------\n");

    printf("enter 5 to exit admin menu:\n");
    scanf("%d", &choose);
    switch (choose)
    {
    case 1:
        inventory_manage(inventory_manage_admin, INVENTORY_SIZE);
        break;
    case 2:
        customer_manage(customer_manage_admin, CUSTOMER_SIZE);
        break;
    case 3:
        discount_manage(discount_manage_admin, DISCOUNT_SIZE);
        break;
    case 4:
        // admin_login(&admin1);
        break;
    default:
        printf("Exit the program\n");
        return STATE_ADMIN;
        break;
    }
}
state_t customer_menu_panel()
{
    int lua_chon = 0;
    while (1)
    {
        menu_display(customer_view, CUSTOMER_PANEL);

        printf("Exit or continues the program in customer view?\n");
        printf("enter 1 to stay, 0 to exit: \n");
        while (scanf("%d", &lua_chon) != 1 || lua_chon < 0 || lua_chon > 1)
        {
            printf("ENTER 0 OR 1 NIGGA\n");
            while (getchar() != '\n')
                ;
        }
        if (lua_chon == 0) // exit
        {
            return STATE_CUSTOMER;
        }
        // lua_chon = 1 
        // still inside while loop 
    }
}

void meal_record()
{
}