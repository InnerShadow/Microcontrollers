#include <reg52.h>
#include <stdio.h>

//#include "fibonacci.c"

extern unsigned int fibonacci(char n) reentrant;

void main() {
	
    char result;

    result = fibonacci(7);
	
    printf("Result: %u\n", result);

    while (1) {}
}

