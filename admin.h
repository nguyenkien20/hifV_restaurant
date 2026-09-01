#ifndef ADMIN_H
#define ADMIN_H

#include <stdint.h>
#include <inttypes.h>

#define PHONENUMBER_LENG 11 // one character for NULL
#define MAX_CHAR 20
#define MAX_NAME 50
#define MAX_TABLE 20


typedef struct Admin admin_t;
typedef struct Item item_t;
typedef struct Customer customer_t;
typedef struct RolePanel role_t;

struct RolePanel
{
    const char *label; // function name
    void (*handler)(); // function pointer
};

struct Admin
{
    char username[MAX_NAME];
    char password[MAX_NAME];
};
struct Item
{
    char id[MAX_CHAR];   // ma san pham
    char name[MAX_NAME]; // ten san pham
    double price;        // gia nhap
    int quantity;
};
struct Customer
{
    char id[MAX_CHAR];
    char name[MAX_NAME];
    char phone_number[PHONENUMBER_LENG];
    int people_number;
    int is_reserved;
    char table_id[MAX_TABLE];
};
struct Discount
{
    customer_t guest; //discount add depend on guest.id
    double percent;
};
void main_board(); // x

// for function pointer replace switch
void menu_display(const role_t *pMenu, int size);
void menu_choose(const role_t *pMenu, uint8_t choose_index);

// ADMIN
int adminPanel();                // (x) admin panel
int admin_login(admin_t *pAdmin); // (x) create and revised account or password
void admin_account_create();
void admin_change_credentials();
// CUSTOMER
void customerPanel();
void customer_login();
void customer_create_account();
// CUSTOMER CONTROLLER
void reserve_table();
void see_my_reservation();
void customer_reserved_update();
void customer_reserved_cancel();
void customer_menu_display();
void view_available_tables();
// ADMIN CONTROLLER
//  main function inventory
void inventory_manage(const role_t *pInventory, int size);     //////////
void inventory_display();    // x
void item_add(item_t *pAdd); // x
void item_update();
void item_remove();
// customer manage main function
void customer_manage(const role_t *pCustomer, int size); ///////////
void customer_add();
void customer_display();
void customer_remove();
void admin_view_customer_reserved();
// discount manage
void discount_manage(const role_t *pDiscount, int size); ////////////
void discount_add();
void discount_remove();
void discount_display();
// record
void meal_record(); ///////////////
void item_current(); //////////
#endif