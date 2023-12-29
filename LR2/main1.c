///////////////////////////////////////////////////
// Программа ДПФ действительных последовательностей
// Головная процедура.
#pragma SMALL
#pragma CODE
#include "dpf1.h"

unsigned char n;
unsigned char nm1, nd2; // резерв , nd4
float xdata SReal[ N ];
// float xdata SImag[ N ];
float xdata SReal_out[ N ];
float xdata SImag_out[ N ];

///////////// main
void main() {
  register unsigned char i;
  n = N;
  nm1 = n - 1;
#if N != 256
  nd2 = n >> 1;
//  nd4 = nd2 >> 1;
#else
  nd2 = 0x80;
//  nd4 = 0x40;
#endif
// входной сигнал. Импульс.
//  for ( i = 0; i <= Nm1; ++i )
  for ( i = 0; i < N; ++i )
    SReal[ i ] = 0.f;
  SReal[ 1 ] = 1.0f;
  FunR_DPF();
  n >>= 1; // n >>= 1; n = nd2, nd2 >>= 1;
  FunR_DPF(); // 1 волна
  SReal[ 1 ] = 0.f;
  SReal[ 3 ] = 1.0f;
  FunR_DPF(); // 3 волны
// ...
  n >>= 1; // n >>= 1;  n = nd2, nd2 >>= 1;
  FunR_DPF();
  while(1){};
}
