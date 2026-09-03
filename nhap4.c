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

void print_information_customer(customer_t customer1, FILE *pFile, int customer_index);
int customer_add(void);

int main()
{
    // if state is main_admin_panel_add_customer
    customer_add();
    return 0;
}
void print_information_customer(customer_t customer1, FILE *pFile, int customer_index){
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
    fprintf(pFile, "\n-----THIS IS CUSTOMER/%d/-----\n", customer_index);
    fprintf(pFile, "1. ID_TABLE: %d\n2. ID_CUSTOMER: %s\n3. CUSTOMER NAME: %s\n4. CUSTOMER PHONENUMBER: %s\n5. QUANTITY: %d\n", customer1.table_index, customer1.id, customer1.name, customer1.phone_number, customer1.people_number);
    fprintf(pFile, "--------------------------------\n");
}
int customer_add(void){
    int customer_index = 0;
    customer_t customers[MAX_CUSTOMER];
    FILE *pFile = fopen(CUSTOMER_LIST, "a");

    if (pFile == NULL)
    {
        printf("Cant open file!\n");
        return (-1);
    }
    printf("ENTER NUMBER INDEX OF CUSTOMER: \n");
    while(scanf("%d", &customer_index) != 1 || customer_index < 1 || customer_index > 100){
        printf("PLEASE ENTER A NUMBER FROM 1 - 100!!!\n");
    }
    // admin enter 1 -> element [0];
    // admin enter 8 -> elenment [7];
    customer_index -= 1;
    print_information_customer(customers[customer_index], pFile, customer_index + 1);
   
    fclose(pFile);
    pFile = NULL;
}