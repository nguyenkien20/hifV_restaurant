#include <stdio.h>
#include "struct_type.h"

void adminPanel()
{
    int flag = 0;
    admin_t admin1; // max admin account is 10
    unsigned int choose1 = 0, choose2 = 0;
    printf("--------------------------");
    printf("\nThis is the admin panel!\n");
    printf("--------------------------\n");
    printf("\n1.Sign in?\n");
    printf("2.Create a new admin account!\n");
    do
    {
        scanf("%u", &choose1);
        if (choose1 == 1)
        {
            flag = admin_login(&admin1);
            break;
        }
        else if (choose1 == 2)
        {
            ;
        }
        else
        {
            printf("Must choose 1 or 2!!\n");
        }
    } while (choose1 < 1 || choose1 > 2);
    if (flag == 1)
    {
        printf("------ADMIN MENU------\n");
        printf("1. Manage inventory!\n");
        // void inventory_manage();
        printf("2. Manage customers!\n");
        // void customer_manage();
        printf("3. Manage reserve table online!\n");
        //
        printf("4. Manage discount!\n");
        // void discount_manage();
        printf("5. Change admin credentials!\n");
        //
        printf("6. Exit admin menu\n");
        // void main_board(); // return to main board
        do
        {
            printf("Make your choice !\n");
            scanf("%d", &choose2);
            if (choose2 < 1 || choose2 > 6)
            {
                printf("Please enter a number 1 - 6!!\n");
            }
        } while (choose2 < 1 || choose2 > 6);
    }
}