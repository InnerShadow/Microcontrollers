$TITLE (Modul-3)
$XREF
        NAME    IO_CHAR
; ��������� ������ ������� (���)
        PUBLIC  PUTCHAR
; ��������
CHAR_ROUTINES SEGMENT CODE INBLOCK

;=======
        RSEG  CHAR_ROUTINES
; ����� ������� � ���������������� ���������.
; ������ ���������� � ������������ A.
PUTCHAR:
        JNB     TI,$
        CLR     TI
        MOV     SBUF,A
        RET

        END
