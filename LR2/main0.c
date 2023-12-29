///////////////////////////////////////////////////
// ��������� ��� �������������� �������������������
// �������� ���������.
//#pragma SMALL
#pragma CODE
#include "dpf0.h"

unsigned char n;
unsigned char nm1, nd2; // ������ , nd4
float SReal[ N ];
// float SImag[ N ];
float SReal_out[ N ];
float SImag_out[ N ];

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
// ������� ������. �������.
  for ( i = 0; i <= Nm1; ++i )
//  for ( i = 0; i < N; ++i )
    SReal[ i ] = 0.f;
  SReal[ 1 ] = 1.0f;
  FunR_DPF();
  n = nd2, nd2 >>= 1; // n >>= 1; 
  FunR_DPF(); // 1 �����
  SReal[ 1 ] = 0.f;
  SReal[ 3 ] = 1.0f;
  FunR_DPF(); // 3 �����
// ...
  n = nd2, nd2 >>= 1; // n >>= 1;  n = nd2, nd2 >>= 1;
  FunR_DPF();
  while(1) ;
}
