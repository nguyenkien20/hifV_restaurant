// dung struct va function pointer
// thay vi dung 1 big dutty switch case
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

typedef struct role_manage
{
    const char *label;
    void (*handler)(void);
} role_t;

// admin panel
#define INVENTORY_SIZE (sizeof(inventory_manage) / sizeof(inventory_manage[0]))
#define CUSTOMER_SIZE (sizeof(customer_manage) / sizeof(customer_manage[0]))
#define DISCOUNT_SIZE (sizeof(discount_manage) / sizeof(discount_manage[0]))
// customer panel
#define CUSTOMER_PANEL (sizeof(customer_view) / sizeof(customer_view[0]))

// 2 function thay switch 
void menu_display(const role_t *pMenu, int size);
void menu_choose(const role_t *pMenu, uint8_t choose_index);
// void inventory_manage(const role_t *pRole);
//
void inventory_display();
void item_add();
void item_update();
void item_remove();
// void customer_manage(const role_t *pRole);
//
void customer_add();
void customer_display();
void customer_remove();
void view_customer_reserved();
// void discount_manage(const role_t *pRole);
//
void discount_add();
void discount_remove();
void discount_display();
// CUSTOMER VIEW
void reserve_table();
void see_my_reservation();
void customer_reserved_update();
void customer_reserved_cancel();
void customer_menu_display();
void view_available_tables();
//

int main()
{
    /*ADMIN PANEL*/
    // inventory
    const role_t inventory_manage[4] = {{"Open inventory display", inventory_display},
                                        {"Add more item", item_add},
                                        {"Update item", item_update},
                                        {"Remove item", item_remove}};
    // customer
    const role_t customer_manage[4] = {{"Display all customers", customer_display},
                                       {"Add customer", customer_add},
                                       {"Remove customer", customer_remove},
                                       {"Customer's reserve", view_customer_reserved}};
    // discount
    const role_t discount_manage[3] = {{"Display all discount", discount_display},
                                       {"Add discount", discount_add},
                                       {"Remove discount", discount_remove}};
    /*CUSTOMER RESERVATION PANEL*/
    const role_t customer_view[6] = {{"Reserved my table", reserve_table},
                                     {"See my reservation", see_my_reservation},
                                     {"Update my reservation", customer_reserved_update},
                                     {"Cancel my reservation", customer_reserved_cancel},
                                     {"Display menu", customer_menu_display},
                                     {"View available table", view_available_tables}};
    printf("Please enter your choose: \n");
    // menu_display(inventory_manage, INVENTORY_SIZE);
    // menu_display(customer_manage, CUSTOMER_SIZE);
    // menu_display(discount_manage, DISCOUNT_SIZE);
    menu_display(customer_view, CUSTOMER_PANEL); 
    return 0;
}
void inventory_display()
{
    // printf("BAN DA CHO bun cha gia 40k\n");
    printf("DISPLAY INVENTORY");
}
void item_add()
{
    // printf("BAN DA CHON com tam\n");
    printf("ADD ITEM");
}
void item_update()
{
    printf("UPDATE ITEM\n");
    // maybe update about price, name, quantity
}
void item_remove()
{
    printf("REMOVE ITEM\n");
}
//
void customer_add()
{
}
void customer_display()
{
}
void customer_remove()
{
}
void view_customer_reserved()
{
}
//
void discount_add()
{
}
void discount_remove()
{
}
void discount_display()
{
//
}
void reserve_table(){

}
void see_my_reservation(){

}
void customer_reserved_update(){

}
void customer_reserved_cancel(){

}
void customer_menu_display(){
printf("THIS IS MENU OF MY RESTAURANT\n");
}
void view_available_tables(){

}
//
void menu_display(const role_t *pMenu, int size)
{
    uint8_t choose_index = 0;
    printf("\nBang dieu khien manage inventory\n");
    for (uint8_t i = 0; i < size; i++)
    {
        printf("%d. %s\n", i + 1, (pMenu + i)->label);
    }
    printf("Vui long nhap muc de mo: \n");
    while (scanf("%" SCNu8, &choose_index) != 1 || choose_index < 1 || choose_index > size) // nhap gia tri thanh cong ham scanf tra ve 1 
    {
        printf("Nhap lai gia tri tu %d den %d\n", 1, size);
        while (getchar() != '\n')
            ;
    }
    menu_choose(pMenu, choose_index);
}

// ham xu ly co tac dung giong switch statement
void menu_choose(const role_t *pMenu, uint8_t choose_index)
{
    choose_index = choose_index - 1;   // start from 0 index
    (pMenu + choose_index)->handler(); // <----- remember have ()
}
/*
void inventory_manage(const role_t *pRole)
{
    printf("---INVENTORY MANAGEMENT PANEL---");
    menu_display(inventory_manage, INVENTORY_SIZE);
}
void customer_manage(const role_t *pRole)
{
    printf("---CUSTOMER MANAGEMENT PANEL---");
    menu_display(customer_manage, CUSTOMER_SIZE);
}
void discount_manage(const role_t *pRole)
{
    printf("---DISCOUNT MANAGEMENT PANEL---");
    menu_display(discount_manage, DISCOUNT_SIZE);
}
*/