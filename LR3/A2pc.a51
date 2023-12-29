$TITLE (Modul-3)
$XREF
        NAME    IO_CHAR
; Процедура вывода символа (имя)
        PUBLIC  PUTCHAR
; Сегменты
CHAR_ROUTINES SEGMENT CODE INBLOCK

;=======
        RSEG  CHAR_ROUTINES
; Вывод символа в последовательный интерфейс.
; Символ расположен в аккумуляторе A.
PUTCHAR:
        JNB     TI,$
        CLR     TI
        MOV     SBUF,A
        RET

        END
