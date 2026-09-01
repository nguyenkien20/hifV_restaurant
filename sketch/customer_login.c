// void customerPanel();
#include <stdio.h>
#include "struct_type.h"
void customerPanel(){
    printf("---Authentication For Customer---\n");
    // must create a logic login
    printf("enter username:\n");
    // fgets(username, sizeof(username), stdin); co the su dung de nhap chuoi
    // username[ strcspn( username, "\n" ) ] = '\0';
    scanf("%s", (pAdmin)->username);
    printf("enter password:\n");
    scanf("%s", (pAdmin)->password);
}