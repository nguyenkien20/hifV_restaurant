#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main() {
    uint8_t age;
    printf("Nhap tuoi cua ban: ");

    while(scanf("%" SCNu8, &age) != 1){
        printf("Loi! Vui long nhap lai gt tu %d den %d\n", 1, 4);
        while(getchar() != '\n');
    }

    return 0;
}