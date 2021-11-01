#include <asm/system.h>
.global interrupt_handler
interrupt_handler:




DEFINES:

#define GT_control_reg			0xF1020300
#define data_enable_set_reg		0xF1018128
#define data_enable_clear_reg		0xF101812C
#define data_out_set_reg		0xF1018130		//REG TO TURN ON LED
#define data_out_clear_reg		0xF1018134		//REG TO TURN OFF LIGHT
#define GT1_reg				0xF102031C
#define GT2_reg				0xF1020324
#define GT3_reg				0xF102032C
#define GT1_reload			0xF1020318
#define GT2_reload			0xF1020320
#define GT3_reload			0xF1020328 
#define value_of_125M			0x1312D0
#define value_of_25M			0x17D7840
#define value_of_50M			0x2FAF080
#define value_to_enable_GT1		0x4
#define value_to_enable_GT2		0x10
#define value_to_enable_GT3		0x40 
#define value_for_GTcr			0x7094
#define value_turn_on_25th_led		0x2000000
#define value_turn_on_29th_led		0x20000000
#define event_register			0xF1020304

#define on				1
#define off				0
#define locked				1
#define unlocked			0
#define LOCK				0xc150034
#define status_25			0x740000		// process A
#define status_29			0x740004		//PROCESS B

#define value_turn_on_25th_led		0x2000000
#define MSB_counter_A			0x740008
#define LSB_counter_A			0x74000C
#define MSB_counter_B			0x740008
#define LSB_counter_B			0x74000C
#define last_process			0xC400000		//00- starting point -> 01- A1 -> 10-A2 -> 11-B -> A1 etc.
#define A1				0x1
#define A2				0x2
#define B				0x3
#define process_A			0xC110000
#define process_B			0xC120000
#define first_round			0x740010
#define A_LR				0x740200
#define B_LR				0x740204
#define SP_A				0x750000
#define SP_B				0x760000



	SUB LR, LR, #4
	
	LDR R7, =last_process		// R7-R8 are free
	LDR R8, [R7]
	
	
	CMP R8, #0
	BNE skip10
	
	LDREQ LR, =process_A 
	LDREQ SP, =SP_A
	STMFD SP!, {R0-R12, LR}


	

	CMP R8, #1			
	BNE skip7
	

	LDREQ SP, =SP_A
	STMFD SP!, {R0-R12, LR}

skip7:
	
	CMP R8, #2
	BNE skip8
	
	LDREQ SP, =SP_A
	STMFD SP!, {R0-R12, LR}
	

	LDR R0, =last_process
	LDR R1, [R0]
	CMP R1, #0
	BNE skip69

	LDREQ LR, =process_B
	LDREQ SP, =SP_B
	STMFD SP!, {R0-R12, LR}
	

skip8:
skip69:

	CMP R8, #3
	BNE skip9

	LDREQ SP, =SP_B
	STMFD SP!, {R0-R12, LR} 

skip9:


	

	//MRS R7, CPSR			//get value of CPSR
	//ORR R7, R7, #0x80		//mask 7th bit
	//MSR CPSR_c, R7			//disable IRQ
	//LDR R7, =0xF1020304		// event reg. address
	//LDR R8, [R7]
	//LDR R9, =0xFEFFFFFF		// mask to turn off GT3 sticky bit
	//AND R8, R8, R9
	//STR R8, [R7]			// turns off sticky bit
	
	LDR R0, =first_round
	LDR R1, [R0]
	CMP R1, #1
	BNE in_rhythm 	

skip10:					// if we're here, it's the FIRST ROUND!

	LDR R0, =last_process
	LDR R1, [R0]
	CMP R1, #0
	
	
	LDREQ R1, =A1			// starting point
	STREQ R1, [R0]
	LDREQ R3, =value_of_125M
	LDREQ R4, =GT3_reg
	STREQ R3, [R4]			// starts GT3
	LDREQ SP, =SP_A
	LDMFD SP!, {R0-R12, PC}^
	

	CMP R1, #1			// situation A1
	BNE skip1

	LDREQ R1, =A2			
	STREQ R1, [R0]
	LDREQ R3, =value_of_125M
	LDREQ R4, =GT3_reg
	STREQ R3, [R4]			// starts GT3
	LDREQ SP, =SP_A
	LDMFD SP!, {R0-R12, PC}^
	

skip1:

	CMP R1, #2			// situation A2
	BNE skip2

	LDREQ R1, =B
	STREQ R1, [R0]
	LDREQ R1, =A_LR
	STREQ LR, [R1]			// stores where we are in process A before moving to process B
	LDREQ R3, =value_of_125M
	LDREQ R4, =GT3_reg
	STREQ R3, [R4]			// starts GT3
	LDREQ SP, =SP_B
	STMFD SP!, {R0-R12, LR} 
	LDMFD SP!, {R0-R12, PC}^	
	

skip2:

	CMP R1, #3
	BNE skip3

	LDREQ R1, =A1
	STREQ R1, [R0]
	MOVEQ R0, #0
	LDREQ R1, =first_round
	STREQ R0, [R1]			// done with 1st round
	LDREQ R0, =B_LR
	STREQ LR, [R0]			// stores where we are in process B before moving back to process A	
	LDREQ R3, =value_of_125M
	LDREQ R4, =GT3_reg
	STREQ R3, [R4]			// starts GT3
	LDREQ SP, =SP_A
	LDMFD SP!, {R0-R12, PC}^
	

skip3:

in_rhythm:

	LDR R0, =last_process
	LDR R1, [R0]
	
	CMP R1, #1			// situation A1
	BNE skip4

	LDREQ R1, =A2			
	STREQ R1, [R0]
	LDREQ R3, =value_of_125M
	LDREQ R4, =GT3_reg
	STREQ R3, [R4]			// starts GT3
	LDREQ SP, =SP_A
	LDMFD SP!, {R0-R12, PC}^	
	
skip4:
	CMP R1, #2			// situation A2
	BNE skip5

	LDREQ R1, =B
	STREQ R1, [R0]
	LDREQ R1, =A_LR
	STREQ LR, [R1]			// stores where we are in process A before moving to process B
	LDREQ R3, =value_of_125M
	LDREQ R4, =GT3_reg
	STREQ R3, [R4]			// starts GT3
	LDREQ SP, =SP_B
	LDMFD SP!, {R0-R12, PC}^
	
	
skip5:
	CMP R1, #3
	BNE skip6

	LDREQ R1, =A1
	STREQ R1, [R0]
	MOVEQ R0, #0
	LDREQ R1, =first_round
	STREQ R0, [R1]			// done with 1st round
	LDREQ R0, =B_LR
	STREQ LR, [R0]			// stores where we are in process B before moving back to process A
	LDREQ R3, =value_of_125M
	LDREQ R4, =GT3_reg
	STREQ R3, [R4]			// starts GT3
	LDREQ SP, =SP_A
	LDMFD SP!, {R0-R12, PC}^
	

skip6:


	
	
	
	



	
