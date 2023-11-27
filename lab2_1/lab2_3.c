#include <reg51.h>
#include <stdio.h>

#include "fibonacci.c"

extern unsigned int fibonacci(unsigned int n);

void main() {
    unsigned int result;

    result = fibonacci(5);
	
    printf("Result: %u\n", result);

    while (1);
}
