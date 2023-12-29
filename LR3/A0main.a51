$TITLE (Modul-1)
$XREF
;$NOMOD51
        NAME    ASMQS0
; ��������� (�����)
EXTRN   CODE    (PUT_CRLF, PUTSTRING)
; ������ ������
PUBLIC  BITTXT
; ��������
;PROG    SEGMENT CODE
MCONST  SEGMENT CODE
;BITVAR  SEGMENT BIT
STACK   SEGMENT IDATA

;=======
        USING   0 ; ���� ��������� 0
; ����� ��������� �� ��������� ������� (RESET).
        SJMP    START
; ���������� ��������� ����� � ������.
START:  MOV     SP,#STACK-1

; ���������������� ���������������� ��������� UART
; ������������ TIMER 1 ��� ������������ ������
; �������� ������� �� = 12. MHz, 2403 ���.
        MOV     TMOD, #00100000B ; C/T = 0, Mode = 2
        MOV     TH1, #0F3H
        SETB    TR1
        MOV     SCON, #01010010B

; �������� BITTXT, ����� ������ ������ CODE
        CLR     BITTXT

; �������� ���� �������� ���������.
; ����� ������ � (��) (��)
REPEAT:        
; ������ ��������� 
        MOV     DPTR, #TXT
        CALL    PUTSTRING
        CALL    PUT_CRLF
; ����������
        SJMP    REPEAT

;=======
        RSEG    STACK
        DS      1 ; ���� �� 1 ����

;=======
        RSEG    MCONST
TXT:    DB      '���� ������!', 00H

;=======
;        RSEG    BITVAR
; BITTXT = 0 ������ �� ������ CODE 
; BITTXT = 1 ������ �� ������ XDATA
;BITTXT: DBIT    1
BITTXT  equ     F0

        END
