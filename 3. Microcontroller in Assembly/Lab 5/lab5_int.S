#include <asm/system.h>
.global interrupt_handler
interrupt_handler:

#define data_out_set_reg		0xF1018130
#define data_enable_set_reg		0xF101812C
#define data_out_clear_reg		0xF1018134
#define GT3_reg				0xF102032C 
#define value_of_25M			0x17D7840 
#define GT_control_reg			0xF1020300
#define value_for_GTcr			0x40C0 
#define value_turn_on_25th_led		0x2000000
#define MSB_64bit_counter		0x1c000000
#define LSB_64bit_counter		0x1c000004
#define GT3reload			0xF1020328


	
	SUB LR, LR, #4
	STMFD SP!, {R0-R12, LR}
	LDR R0, =value_turn_on_25th_led
	LDR R1, =value_for_GTcr
	LDR R2, =data_out_set_reg
	LDR R3, =GT_control_reg
	BL q_1_b
return2:
	CMP R4, #20			// checks if we're done with code
	LDREQ R5, =GT_control_reg	// if done, we'll turn off counter
	MOV R6, #0
	STREQ R6, [R5]			// put 0 in control reg.
	LDREQ PC, =0xC100000		// go back to beginning of code
	LDR R5, =value_of_25M
	LDR R6, =GT3_reg
	LDR R11, =data_out_clear_reg
	LDR R12, =value_of_25M
	MRS R7, CPSR		//get value of CPSR
	ORR R7, R7, #0x80	//mask 7th bit
	MSR CPSR_c, R7		//disable IRQ
	LDR R7, =0xF1020304	// event reg. address
	LDR R8, [R7]
	LDR R9, =0xFEFFFFFF	// mask to turn off GT3 sticky bit
	AND R8, R8, R9
	STR R8, [R7]		// turns off sticky bit
	//PUSH {LR}
	//BL q_1_b
//return2:
	//MOV R8, #1
	AND R8, R4, #1		//checks if to turn off or on led
	ADD R4, R4, #1		// increment counter
	CMP R8, #0
	LDREQ R7, =GT3reload	//address
	LDREQ R9, [R7]		//load value of GT3 reload reg
	ADDEQ R9, R9, R12	//add 25M to RR if counter is even
	STREQ R9, [R7]	
	MOV R9, #0
	STRNE R9, [R11]
	STRNE R0, [R2]		//odd-turn on
	STREQ R9, [R2]
	STREQ R0, [R11]		//even- turn off
	//MRS R7, CPSR		//get value of CPSR
	//MOV R8, #0x60
	//AND R8, R8, R7
	//MOV R7, #0x10
	//ORR R8, R8, R7
	//MOV R8, #0x7F		//mask for bits 7-0 to unmask 7th bit
	//AND R8, R8, R7		//masking
	//MSR CPSR_c, R8
	//POP {LR}
	//SUB PC, LR, #4
	LDMFD SP!, {R0-R12, PC}^

		
q_1_b:	
		CF = 0	
		//LDR R8, =MSB_64bit_counter
		LDR R9, =LSB_64bit_counter
		//LDR R10, [R8]
		LDR R4, [R9]
		ADD R4, R4, #1
		STR R4, [R9]
		//STR R7, [R9]
		BL return2
