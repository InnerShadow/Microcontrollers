#include <reg51.h>

void delay(int count) {
    int i;
    for (i = 0; i < count; i++) {
        __asm nop
    }
}

void main() {
    P1 = P1 & 0xFD;

    while (1) {
        delay(86);
        P1 = P1 | 0x02;
        delay(2);
        P1 = P1 & 0xFD;
    }
}
