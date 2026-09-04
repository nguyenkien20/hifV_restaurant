#include <stdio.h>
#include <string.h>
typedef enum state state_t;
#define MAX_CHAR 11
state_t main_board(void);

state_t admin_panel();
state_t admin_menu_panel();
state_t customer_panel();

enum state
{
    STATE_HOME,       // 0     // main_board
    STATE_ADMIN,      // 1     // admin_panel
    STATE_ADMIN_MENU, // 2     // admin_menu_panel
    STATE_CUSTOMER,   // 3     // customer_panel
    STATE_EXIT,       // 4     // exit the program
};

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
            state = admin_panel();
            break;
        case STATE_ADMIN_MENU:
            state = admin_menu_panel();
            break;
        case STATE_CUSTOMER:
            state = customer_panel();
            break;
        default:
            state = STATE_EXIT;
            break;
        }
    }
    printf("Exit the program!\n");
    return 0;
}
// ham nay tra ve kieu du lieu state_t (enum)
state_t main_board(void)
{
    char role[MAX_CHAR];
    int get_value = 0;
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
state_t customer_panel()
{
    int choose = 0;
    printf("\nWELCOME TO CUSTOMER PANEL!\n");
    printf("--------------------------\n");
    printf("1.Sign in?\n");
    printf("2.Create a new customer account!\n");
    printf("3. Exit to home page\n");
    printf("--------------------------\n");
    printf("Enter 3 to back:\n");
    scanf("%d", &choose);

    if (choose == 3)
    {
        return STATE_HOME;
    }
}
state_t admin_menu_panel()
{
    int choose = 0;
    printf("------ADMIN MENU------\n");
    printf("1. Manage inventory!\n");
    printf("2. Manage customers!\n");
    printf("3. Manage discount!\n");
    printf("4. Change admin credentials!\n");
    printf("5. Exit admin menu\n");
    printf("----------------------\n");

    printf("enter 5 to exit admin menu:\n");
    scanf("%d", &choose);

    if (choose == 5)
    {
        return STATE_ADMIN;
    }
}
state_t admin_panel()
{
    int choose = 0;
    printf("\nWELCOME TO ADMIN PANEL!\n");
    printf("-----------------------------\n");
    printf("1.Sign in?\n");
    printf("2.Create a new admin account!\n");
    printf("3. Back to main board\n");
    printf("-----------------------------\n");
    printf("Enter 3 to back:\n");
    scanf("%d", &choose);

    if (choose == 3)
    {
        return STATE_HOME;
    }
}