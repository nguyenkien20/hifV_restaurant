// sketch record customer information
#include <stdio.h>
#include <string.h>

#define CUSTOMER_LIST "add_customer.txt"
#define PHONENUMBER_LENG 11 // one character for NULL
#define MAX_CHAR 20
#define MAX_NAME 50
#define MAX_TABLE 20
#define MAX_CUSTOMER 100

typedef struct Customer
{
    char id[MAX_CHAR];
    char name[MAX_NAME];
    char phone_number[PHONENUMBER_LENG];
    int people_number;
    int is_reserved;
    int table_index;
} customer_t;

void get_information_customer(customer_t customer1, FILE *pFile, int customer_index);
int customer_add(void);
void printf_customer_information(customer_t customer1, FILE *pFile, int customer_index);

int main()
{
    // if state is main_admin_panel_add_customer
    int value = customer_add();
    if(value == -1){
        printf("EXIT THE PROGRAM!!\n");
        return (-1);
    }
    else{
        return 0;
    }
}
void get_information_customer(customer_t customer1, FILE *pFile, int customer_index)
{
    printf("Enter a id table number: \n");
    scanf("%d", &customer1.table_index);
    while (getchar() != '\n')
        ;
    printf("Enter an id customer (max %d character): \n", MAX_CHAR);
    fgets(customer1.id, MAX_CHAR, stdin);
    //  item_name[strcspn(item_name, "\n")] = '\0
    customer1.id[strcspn(customer1.id, "\n")] = '\0';

    printf("Enter customer's name (max %d character): \n", MAX_NAME);
    fgets(customer1.name, MAX_NAME, stdin);
    //  item_name[strcspn(item_name, "\n")] = '\0
    customer1.name[strcspn(customer1.name, "\n")] = '\0';

    printf("Enter customer's phone number (max %d character): \n", PHONENUMBER_LENG);
    fgets(customer1.phone_number, PHONENUMBER_LENG, stdin);
    customer1.phone_number[strcspn(customer1.phone_number, "\n")] = '\0';

    printf("Enter customer's quantity (/1 table): \n");
    scanf("%d", &customer1.people_number);
    while (getchar() != '\n')
        ;
    printf_customer_information(customer1, pFile, customer_index);

}
int customer_add(void)
{
    int customer_index = 0;
    customer_t customers[MAX_CUSTOMER];
    FILE *pFile = fopen(CUSTOMER_LIST, "a");

    if (pFile == NULL)
    {
        printf("Cant open file!\n");
        return (-1);
    }
    printf("ENTER NUMBER INDEX OF CUSTOMER: \n");
    while (scanf("%d", &customer_index) != 1 || customer_index < 1 || customer_index > 100)
    {
        printf("PLEASE ENTER A NUMBER FROM 1 - 100!!!\n");
    }
    // admin enter 1 -> element [0];
    // admin enter 8 -> elenment [7];
    customer_index -= 1;
    get_information_customer(customers[customer_index], pFile, customer_index + 1);
    fclose(pFile);
    pFile = NULL;
    return 1;
}
void printf_customer_information(customer_t customer1, FILE *pFile, int customer_index)
{
    int total_character = 0;
    total_character += fprintf(pFile, "\n-------THIS IS CUSTOMER/%d/-------\n", customer_index);
    total_character += fprintf(pFile, "1. ID_TABLE: %d\n2. ID_CUSTOMER: %s\n3. CUSTOMER NAME: %s\n4. CUSTOMER PHONENUMBER: %s\n5. QUANTITY: %d\n", customer1.table_index, customer1.id, customer1.name, customer1.phone_number, customer1.people_number);
    total_character += fprintf(pFile, "--------------------------------\n");

    printf("LENGTH IS: %d\n", total_character);
    // printf("Distance from last position to current is: %d bytes\n", length - last_value);
    fseek(pFile, - total_character, SEEK_CUR);
}