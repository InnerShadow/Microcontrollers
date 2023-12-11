/* ���������� �������.                                  ������ 1
   ������ ����������� ���������. ��������� �����������. �������� ����������.
   ��������� ���������, ����������� ����������.
// ��������� ����������� � IAR Systems, � ����� Keil
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
#define CnstMyFunc 40320         /* 5040 ��� ���������� */
#pragma small                   // ����� ������ ������.
#include <setjmp.h>
#include <stdio.h>
#include <string.h>

// ----- ������� ����������
jmp_buf vJumper;
unsigned int iN;
static char cResult[ 11 ];
static unsigned int iValCT, iC = 0;

#if NoRecurs 
//static int Fact( int iNum );
#else
static int fibonacci( int iNum ) reentrant;
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
    iN = fibonacci( iValCT );
    if ( iN >= CnstMyFunc ) {
      strcpy( cResult, "Finish!" );
      goto Lexit;
    }
  }
  else iN = -1;
  iN = sprintf( cResult, "N=%d i=%d", iN, iValCT );
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

#else
// ����������� ������ ����������.
fibonacci(char n) reentrant {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;

    return fibonacci(n - 1) + fibonacci(n - 2);
}
//int Fact( int iNum ) reentrant {
//  if ( iNum < 0 ) return 0;
//  if ( iNum == 0 ) return 1;
//  return  Fact( iNum - 1 )* iNum;
//}
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

