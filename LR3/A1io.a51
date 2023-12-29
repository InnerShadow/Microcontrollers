$TITLE (Modul-2)
$XREF
        NAME    IO_STRING

        EXTRN   BIT     (BITTXT)
        EXTRN   CODE    (PUTCHAR)
; Процедуры (имена)
        PUBLIC  PUT_CRLF, PUTSTRING
; Сегменты
STRING_ROUTINES SEGMENT CODE INBLOCK

;=======
        RSEG    STRING_ROUTINES
; Символы (ВК) и (ПС).
CR      equ     0DH ; возврат каретки
LF      equ     0AH ; перевод строки

; Эта процедура выводит (ВК) и (ПС).
PUT_CRLF: 
        MOV     A,#CR
$IF SMALL        
        ACALL   PUTCHAR
$ELSE
        CALL    PUTCHAR
$ENDIF    
        MOV     A,#LF
$IF SMALL        
        ACALL   PUTCHAR
$ELSE
        CALL    PUTCHAR
$ENDIF    
        RET

; Эта процедура выводит строку с 0 на конце.
; Адрес строки в регистре DPTR.
; Строка находится в памяти CODE или XDATA
; в зависимости от флажка BITTXT.
PUTSTRING:
        JB      BITTXT,PS1 ; проверка бита BITTXT
        CLR     A
        MOVC    A,@A+DPTR
        SJMP    PS2
PS1:    MOVX    A,@DPTR
PS2:    JZ      EXIT
$IF SMALL        
        ACALL   PUTCHAR
$ELSE
        CALL    PUTCHAR
$ENDIF    
        INC     DPTR
        SJMP    PUTSTRING
EXIT:   RET

        END
 