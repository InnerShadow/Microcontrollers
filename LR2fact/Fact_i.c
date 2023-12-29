/* ���������� �������.                                  ������ 1
   ������ ����������� ���������. ��������� �����������. �������� ����������.
   ��������� ���������, ����������� ����������.
// ��������� ����������� � IAR Systems, � ����� Keil
   ! ���������� ������������� - unsigned.
*/
#pragma CODE
#pragma PAGELENGTH(999)
#pragma PAGEWIDTH(132)

#define NoRecurs 0
#define Param 3
// ===============================================================
#if Param == 0
// ===== 0 �������.
#error ������ �1, ���� �������� ��� �� �������!
/* . . . . . . . . . . . . . */
#elif Param == 1
// ===== 1 �������.
#error ������ �2, ���� �������� �� ��� �� �������!
/* . . . . . . . . . . . . . */
#elif Param == 2
// ===== 2 �������.
#error ������ �3, ���� �������� ������ ������!
/* . . . . . . . . . . . . . */
#elif Param == 3
// ===== 3 �������. ����������� ��������.
#define CnstMyFunc 40320   /* 5040 40320 ��� ���������� */
#pragma small              // ����� ������ ������.
#include <setjmp.h>
#include <stdio.h>
#include <string.h>

// ----- ������� ����������
jmp_buf vJumper;
unsigned int iN; // unsigned
static char cResult[ 12 ];
static int iValCT, iC = 0;

#if NoRecurs 
static int Fact( int iNum );
#else
static int Fact( int iNum ) reentrant;
#endif
void fSubroutine( void );

// ===============================================================
void main( void ) {
/***** ���������� � ������.
   -�������� �������; -���. �� ���.; -������ �������. */
  iN = 666;
  strcpy( cResult, "Start!" );
  iValCT = setjmp( vJumper );
/* <<<<< ����� �����. ������ �����.
   -30-40 ��� ������� �� 5 ��������. */
  if ( iValCT != 0 ) { // �� ������ ����!
    iN = Fact( iValCT );
    if ( iN >= CnstMyFunc ) {
      strcpy( cResult, "Finish!" );
      goto Lexit;
    }
  }
  else iN = -1;
  iN = sprintf( cResult, "N=%u i=%d", iN, iValCT ); // %d %u
  fSubroutine();
/***** ����������.
  -����� �������; ����. ���.; -������. ���. 5 ���. */
Lexit:
  while (1) {}
}

// ===============================================================
// ���������� ����������.
#if NoRecurs 
// ������� ������ ���������� � �����.
int Fact( int iNum ) {
  register int i, prod = 1;
  if ( iNum < 0 ) return 0;
  if ( iNum == 0 ) return 1;
  for ( i = 1; i <= iNum; i++ )
    prod *= i;
  return prod;
}
#else
// ����������� ������ ����������.
int Fact( int iNum ) reentrant {
  if ( iNum < 0 ) return 0;
  if ( iNum == 0 ) return 1;
  return  Fact( iNum - 1 )* iNum;
}
#endif

// ===============================================================
// ��������������� �������.
/* � ���������� longjmp(...) */
void fSubroutine( void ) {
/* ... */
  longjmp( vJumper, ++iC );
/* ... */
}
#else
// ===== 4 ��������� �������.
#message "���� �������� �� ����� �� �������!"
/* . . . . . . .
  ��� IAR Systems
   . . . . . . . */
#endif
