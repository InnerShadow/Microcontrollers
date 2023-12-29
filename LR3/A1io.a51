$TITLE (Modul-2)
$XREF
        NAME    IO_STRING

        EXTRN   BIT     (BITTXT)
        EXTRN   CODE    (PUTCHAR)
; ��������� (�����)
        PUBLIC  PUT_CRLF, PUTSTRING
; ��������
STRING_ROUTINES SEGMENT CODE INBLOCK

;=======
        RSEG    STRING_ROUTINES
; ������� (��) � (��).
CR      equ     0DH ; ������� �������
LF      equ     0AH ; ������� ������

; ��� ��������� ������� (��) � (��).
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

; ��� ��������� ������� ������ � 0 �� �����.
; ����� ������ � �������� DPTR.
; ������ ��������� � ������ CODE ��� XDATA
; � ����������� �� ������ BITTXT.
PUTSTRING:
        JB      BITTXT,PS1 ; �������� ���� BITTXT
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
 