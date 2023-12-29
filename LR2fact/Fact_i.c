/* Монолитный вариант.                                  Пример 1
   Пример нелокальных переходов. Вложенные комментарии. Условная компиляция.
   Маленькая программа, вычисляющая факториалы.
// вложенные комментарии в IAR Systems, а здесь Keil
   ! факториалы положительные - unsigned.
*/
#pragma CODE
#pragma PAGELENGTH(999)
#pragma PAGEWIDTH(132)

#define NoRecurs 0
#define Param 3
// ===============================================================
#if Param == 0
// ===== 0 вариант.
#error Ошибка №1, этот фрагмент ещё не написан!
/* . . . . . . . . . . . . . */
#elif Param == 1
// ===== 1 вариант.
#error Ошибка №2, этот фрагмент всё ещё не написан!
/* . . . . . . . . . . . . . */
#elif Param == 2
// ===== 2 вариант.
#error Ошибка №3, этот фрагмент врядли напишу!
/* . . . . . . . . . . . . . */
#elif Param == 3
// ===== 3 вариант. Нелокальные переходы.
#define CnstMyFunc 40320   /* 5040 40320 для факториала */
#pragma small              // явная модель памяти.
#include <setjmp.h>
#include <stdio.h>
#include <string.h>

// ----- рабочие переменные
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
/***** Подготовка к работе.
   -включить прогрев; -вкл. ВЧ ген.; -подать высокое. */
  iN = 666;
  strcpy( cResult, "Start!" );
  iValCT = setjmp( vJumper );
/* <<<<< Точка входа. Работа блока.
   -30-40 мин прогрев на 5 градусов. */
  if ( iValCT != 0 ) { // не первый вход!
    iN = Fact( iValCT );
    if ( iN >= CnstMyFunc ) {
      strcpy( cResult, "Finish!" );
      goto Lexit;
    }
  }
  else iN = -1;
  iN = sprintf( cResult, "N=%u i=%d", iN, iValCT ); // %d %u
  fSubroutine();
/***** Завершение.
  -снять высокое; выкл. ген.; -вентил. охл. 5 мин. */
Lexit:
  while (1) {}
}

// ===============================================================
// Вычисление факториала.
#if NoRecurs 
// Обычный расчет факториала в цикле.
int Fact( int iNum ) {
  register int i, prod = 1;
  if ( iNum < 0 ) return 0;
  if ( iNum == 0 ) return 1;
  for ( i = 1; i <= iNum; i++ )
    prod *= i;
  return prod;
}
#else
// Рекурсивный расчет факториала.
int Fact( int iNum ) reentrant {
  if ( iNum < 0 ) return 0;
  if ( iNum == 0 ) return 1;
  return  Fact( iNum - 1 )* iNum;
}
#endif

// ===============================================================
// Вспомогательная функция.
/* В прерывании longjmp(...) */
void fSubroutine( void ) {
/* ... */
  longjmp( vJumper, ++iC );
/* ... */
}
#else
// ===== 4 Последний вариант.
#message "Этот фрагмент до конца не написан!"
/* . . . . . . .
  для IAR Systems
   . . . . . . . */
#endif
