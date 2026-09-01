// sketch
// this header file just contain marco, struct definition
// has not yet contain prototype
// struct_type.h
#ifndef STRUCTTYPE_H
#define STRUCTTYPE_H

#define PHONENUMBER_LENG 10
#define MAX_CHAR 20
#define MAX_NAME 50
#define MAX_ITEM 100

typedef struct Admin admin_t;
typedef struct Item item_t;
typedef struct Customer customer_t;
typedef struct admin_panel_choosen admin_choosen_t;

struct Admin
{
    char username[MAX_NAME];
    char password[MAX_NAME];
};
//
struct Item
{
    char id[MAX_CHAR];   // ma san pham
    char name[MAX_NAME]; // ten san pham
    double price;        // gia nhap
    int quantity;
};
//
struct admin_panel_choosen
{
    item_t *items;
    void (*handler)();
};
//
struct Customer
{
    char id[MAX_CHAR];
    char name[MAX_CHAR];
    char phone_number[PHONENUMBER_LENG];
    int people_number;
};
//
struct Discount
{
    customer_t guest;
    double percent;
};
#endif