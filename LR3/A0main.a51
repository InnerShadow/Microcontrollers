$TITLE (Modul-1)
$XREF
;$NOMOD51
        NAME    ASMQS0
; Процедуры (имена)
EXTRN   CODE    (PUT_CRLF, PUTSTRING)
; Флажок вывода
PUBLIC  BITTXT
; Сегменты
;PROG    SEGMENT CODE
MCONST  SEGMENT CODE
;BITVAR  SEGMENT BIT
STACK   SEGMENT IDATA

;=======
        USING   0 ; банк регистров 0
; Старт программы по включению питания (RESET).
        SJMP    START
; Установить указатель стека в начало.
START:  MOV     SP,#STACK-1

; Инициализировать последовательный интерфейс UART
; Использовать TIMER 1 для тактирования сдвига
; Тактовая частота МК = 12. MHz, 2403 бод.
        MOV     TMOD, #00100000B ; C/T = 0, Mode = 2
        MOV     TH1, #0F3H
        SETB    TR1
        MOV     SCON, #01010010B

; Очистить BITTXT, чтобы читать память CODE
        CLR     BITTXT

; Основной цикл головной программы.
; Вывод строки и (ВК) (ПС)
REPEAT:        
; Выдать сообщение 
        MOV     DPTR, #TXT
        CALL    PUTSTRING
        CALL    PUT_CRLF
; повторение
        SJMP    REPEAT

;=======
        RSEG    STACK
        DS      1 ; Стек на 1 байт

;=======
        RSEG    MCONST
TXT:    DB      'Всем привет!', 00H

;=======
;        RSEG    BITVAR
; BITTXT = 0 чтение из памяти CODE 
; BITTXT = 1 чтение из памяти XDATA
;BITTXT: DBIT    1
BITTXT  equ     F0

        END
