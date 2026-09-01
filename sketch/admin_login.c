#include <stdio.h>
#include "struct_type.h"

int admin_login(admin_t *pAdmin)
{
    int flag = 0;
    item_t items[100];
    printf("---Authentication For Admin---\n");
    // must create a logic login
    printf("enter username:\n");
    // fgets(username, sizeof(username), stdin); co the su dung de nhap chuoi
    // username[ strcspn( username, "\n" ) ] = '\0';
    scanf("%s", (pAdmin)->username);
    printf("enter password:\n");
    scanf("%s", (pAdmin)->password);
    flag = 1; // mean login successful
    return flag;
    // item_add(items); // test function
}