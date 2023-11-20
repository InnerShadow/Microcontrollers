#include <reg51.h>

void main() {
    char iA0 = 1, iAl = 2, iB0 = 3, iBl = 4;
    int W2;
    long double iC0, iCl;

    TMOD |= 0x01; 
    TR0 = 1;

    iC0 = iA0 * (iB0 + iBl);
    iCl = iAl * (iB0 - iBl);
    W2 = iBl * (iA0 + iAl);
    iC0 -= W2;
    iCl += W2;
    iC0 = iA0 * (iB0 - iBl);
    iCl = iAl * (iB0 + iBl);
    W2 = iBl * (iA0 - iAl);
    iC0 += W2;
    iCl += W2;
    iC0 = iB0 * (iA0 + iAl);
    iCl = iA0 * (iB0 - iBl);
    W2 = iAl * (iB0 + iBl);
    iCl = iC0 - iCl;
    iC0 -= W2;

    TR0 = 0; 
		
		int elapsed_time = 0;

    elapsed_time = TH0 << 8 | TL0;

    printf("Result: iC0=%Lf, iCl=%Lf\n", iC0, iCl);
    printf("Elapsed time: %u timer counts\n", elapsed_time);

    while (1);
}