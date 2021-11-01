.global _start
_start:

	MOV        R0, R5        //R0 going to be our counter
n:
	CMP		R0, #3
	BGT		greater	//in case counter is less than 
	CMP		R0, #2
	BMI one
	BEQ two
	BGT three

one:	LDRB		R4, [R3,R0]	//enters if r0=1
	BAL label1
	
two:	LDRB		R4, [R3,R0]	//enters if r0=2
	BAL label2
	
three:	LDRB		R4, [R3,R0]	//enters if r0=3
	BAL label3

label1:
label2:
label3:			
	MOV		R0, #0
greater:

        CMP        R0, #0
        
	
        BEQ        equal	//enters if r0>0
        STR        R4, [R3,R0]
        SUB        R0, R0, #0x10
	BNE		n
        equal:
	
