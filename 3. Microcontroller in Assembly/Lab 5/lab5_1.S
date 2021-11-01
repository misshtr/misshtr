.global _start
_start:

ENABLE_MPP_25_AS_GPIO:
	ldr r1, =0xF101800C
	mov r0, #0x000000F0
	ldr r2, [r1]
	bic r2, r0
	str r2, [r1]

DEFINES:
#define data_out_set_reg		0xF1018130
#define data_enable_set_reg		0xF101812C
#define data_out_clear_reg		0xF1018134
#define GT1_reg				0xF102031C 
#define value_of_25M			0x17D7840 
#define GT_control_reg			0xF1020300
#define value_for_GTcr			0x1004 
#define value_turn_on_25th_led		0x2000000
#define MSB_64bit_counter		0x1c000000
#define LSB_64bit_counter		0x1c000004

MAIN:	
	LDR R0, =value_turn_on_25th_led
	LDR R1, =value_for_GTcr
	LDR R2, =data_out_set_reg
	LDR R3, =data_enable_set_reg
	MOV R4, #0 		//counter
	STR R0, [R3]		//keep low in 25th pin
	LDR R5, =value_of_25M
	LDR R6, =GT1_reg
	STR R5, [R6]		//put 25M into GT1
	LDR R3, =GT_control_reg
	LDR R11, =data_out_clear_reg
	LDR R12, =value_of_25M

	BL q_1_a		//reset counter
return1:

	BL skip 
loop:
	ADD R4, R4, #1		// increment counter
	AND R8, R4, #1		//checks even/odd
	CMP R8, #0
	STRNE R5, [R6] 
	ADDEQ R5, R5, R12	// increment by 25M
	STREQ R5, [R6]
	
	
		
	
	
	
skip:	
	STR R1, [R3] 		// enables countdown

while:
	BL q_1_b		// increments counter by 1
return2:
	LDR R9, [R6]
	CMP R9, #0
	BNE while		//polls countdowns	
	

	AND R8, R4, #1		//checks if to turn off or on led
	CMP R8, #0
	STREQ R9, [R11]
	STREQ R0, [R2]		//even-turn on
	STRNE R9, [R2]
	STRNE R0, [R11]		//odd- turn off
	CMP R4, #20		//iterate 20 times
	BL q_1_c		// return counter
return3:
	BNE loop
	BL end
	



q_1_a:	//resets counter

		MOV R7, #0
		LDR R8, =MSB_64bit_counter
		ADD R9, R8, #4
		STR R7, [R8]
		STR R7, [R9]
BL 		return1
		


q_1_b:	

		LDR R8, =MSB_64bit_counter
		LDR R9, =LSB_64bit_counter
		LDR R10, [R8]
		LDR R7, [R9]
		ADDS R10, R10, #1
		ADC R7, R7, #0
		STR R10, [R8]
		STR R7, [R9]
		

BL 		return2



q_1_c:	

		LDR R8, =MSB_64bit_counter
		LDR R9, =LSB_64bit_counter
		LDR R7, [R8]
		LDR R10, [R9]
		

BL 		return3

end:
