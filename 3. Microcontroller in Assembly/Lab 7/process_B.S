#include <asm/system.h>
.global _start
_start:

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
#define value_for_GTcr			0x7014
#define value_turn_on_25th_led		0x2000000
#define value_turn_on_29th_led		0x20000000
#define event_register			0xF1020304

#define on				1
#define off				0
#define locked				1
#define unlocked			0
#define LOCK				0xc150034
#define status_25			0x740000		// process A
#define status_29			0x740004		// process B

#define value_to_lower_29th_led		0xDFFFFFFF
#define value_turn_on_25th_led		0x2000000
#define value_turn_on_29th_led		0x20000000
#define MSB_counter_A			0x740008
#define LSB_counter_A			0x74000C
#define MSB_counter_B			0x740108
#define LSB_counter_B			0x74010C
#define first_round			0x740010
#define last_process			0xC400000
	

	

	
again:


	LDR R0, =value_of_50M
	LDR R1, =GT1_reg
	STR R1, [R0]			// stores 50M in GT1, making the count equal 2 seconds

poll:

	LDR R1, =MSB_counter_B
	LDR R0, =LSB_counter_B
	LDR R3, [R1]			// fetches MSB counter from memory
	LDR R2, [R0] 			// fetches LSB counter from memory
	ADDS R2, R2, #1			// increment LSB counter
	ADC R3, R3, #0			// increment MSB counter
	STR R2, [R0]			// stores LSB counter back into memory
	STR R3, [R1]			// stores MSB counter back into memory
	LDR R0, =event_register			// poll sticky bit
	LDR R1, [R0]	
	MOV R2, #0x100
	AND R0, R2, R1
	CMP R0, R2
	BNE poll
	

lock_mutex_PROC:	

	LDR R0, =LOCK
	LDR R1, =locked
	LDREX R2, [R0]			// load exclusive
	CMP R2, R1			// checks if mutex is locked/unlocked
	BEQ lock_mutex_PROC		// if locked, wait for it to be released

	STREXNE R2, R1, [R0] 		// not locked, attempt to lock it (success/failure goes into R2)
	CMPNE R2, #1 			// checks if Store_Exclusive was succesful 
	BEQ lock_mutex_PROC 		// fail - start whole process over again

	DMB				// Data Memory Barrier

	
	LDR R0, =status_29
	LDR R1, [R0]
	CMP R1, #0
	BEQ turn_on

turn_off:

	LDR R0, =value_to_lower_29th_led	// all 1's except 29th bit
	LDR R1, =data_out_set_reg
	LDR R2, [R1]
	AND R2, R2, R0				// turns 29th bit to 0
	STR R2, [R1]				// so it wont fight with clear reg
	LDR R0, =value_turn_on_29th_led
	LDR R1, =data_out_clear_reg
	LDR R2, [R1]
	ORR R2, R2, R0				// puts 1 in 29th bit
	STR R2, [R1]				// turns off led
	LDR R0, =off
	LDR R1, =status_29
	STR R0, [R1]				// updating status of led
	BL skip

turn_on:

	LDR R0, =value_to_lower_29th_led	// all 1's except 29th bit
	LDR R1, =data_out_clear_reg
	LDR R2, [R1]
	AND R2, R2, R0				// turns 29th bit to 0
	STR R2, [R1]				// so it wont compete with set reg.
	LDR R0, =value_turn_on_29th_led
	LDR R1, =data_out_set_reg
	LDR R2, [R1]
	ORR R2, R2, R0				// puts a 1 at 29th bit	
	STR R2, [R1]				// turns on 29th led
	LDR R0, =on
	LDR R1, =status_29
	STR R0, [R1]				// updating status of led

skip:
	
	

unlock_mutex_PROC:
	

	LDR R0, =LOCK
	LDR R1, =unlocked
	DMB
	STR R1, [R0]				// unlock mutex

	BL again
	BL again

















		
		
	

	


