.global _start
_start:

LDR R7, =0xD1000000
MOV R0, #0             //register to compare to
MOV R1, #80        //amount of rows in matrix X memory allignment 
MOV R8, #4		
MUL R8, R4, R8         //memory allignment

MUL R2, R3, R1
ADD R2, R2, R8
ADD R2, R2, R7
CMP R5, R0         // decides whether to read or write into matrix
BEQ equal
STR R6, [R2]        //if not equal, write
BNE not_equal
equal:
LDR R6, [R2]
not_equal:

