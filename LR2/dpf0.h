// dpf0.h
//===== ��������� � ����
#define M_PI        3.14159265358979323846
#define M_PI_2      1.57079632679489661923
#define M_PI_4      0.785398163397448309616
//===== ������������ ������
#define N 128
#define Nm1 ( N - 1 )
#define Nd2 ( N >> 1 )
#define Nd4 ( Nd2 >> 1 )

extern unsigned char n;
extern unsigned char nm1, nd2, nd4; // ������
extern float SReal[ N ];
//extern float SImag[ N ];
extern float SReal_out[ N ];
extern float SImag_out[ N ];

void FunR_DPF( void );
