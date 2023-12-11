#include <stdio.h>
#include <string.h>

void convertToCP1251(char *str) {
    unsigned char *ptr = (unsigned char *)str;

    while (*ptr != '\0') {
        if (*ptr >= 0xC0 && *ptr <= 0xFF) {
            *ptr = *ptr + 0x30;
        }
        ptr++;
    }
}

int main() {
    char inputString[100];

    printf("CP866: ");
    gets(inputString);

    convertToCP1251(inputString);

    printf("CP1251: %s\n", inputString);

    while(true){}
}
