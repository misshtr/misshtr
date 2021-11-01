#include <asm/system.h>
.global _start
_start:

DEFINES:
#define on				1
#define off				0
#define locked				1
#define unlocked			0
#define LOCK				0xc150034
#define status_25			0x740000		// process A
#define status_29			0x740004		// process B

#define value_to_lower_25th_led		0xFDFFFFFF
#define MSB_counter_A			0x740008
#define LSB_counter_A			0x74000C
#define MSB_counter_B			0x740008
#define LSB_counter_B			0x74000C
#define last_process			0xc400000 		// 00-first round,  01- A1,  10- A2,  11- B
#define GT_event_reg			0xF1020304 
#define data_out_set_reg		0xF1018130		//REG TO TURN ON LED
#define data_out_clear_reg		0xF1018134		//REG TO TURN OFF LIGHT
#define GT2_reg				0xF1020324
#define value_of_25M			0x17D7840
#define value_of_50M			0x2FAF080 
#define value_turn_on_25th_led		0x2000000
#define value_turn_on_29th_led		0x20000000


start:

MAIN:

	LDR R0, =GT2_reg	
	LDR R1, =value_of_25M
	LDR R4, =GT_event_reg
	
	STR R1, [R0] 		// enables countdown GT2

poll:
	LDR R1, =MSB_counter_A
	LDR R0, =LSB_counter_A
	LDR R3, [R1]			// fetches MSB counter from memory
	LDR R2, [R0] 			// fetches LSB counter from memory
	ADDS R2, R2, #1			// increment LSB counter
	ADC R3, R3, #0			// increment MSB counter
	STR R2, [R0]			// stores LSB counter back into memory
	STR R3, [R1]			// stores MSB counter back into memory
	LDR R0, =GT_event_reg		// poll sticky bit
	LDR R1, [R0]	
	MOV R2, #0x10000
	AND R0, R2, R1
	CMP R0, R2
	BNE poll			//polls counter



lock_mutex_PROC:	

	
	LDR R0, =LOCK
	LDR R1, =locked
	LDREX R6, [R0]			// load exclusive
	CMP R6, R1			// checks if mutex is locked/unlocked
	BEQ lock_mutex_PROC		// if locked, wait for it to be released

	STREXNE R6, R1, [R0] 		// not locked, attempt to lock it (success/failure goes into R2)
	CMPNE R6, #1 			// checks if Store_Exclusive was succesful 
	BEQ lock_mutex_PROC 		// fail - start whole process over again

	DMB				// Data Memory Barrier
	
	LDR R0, =status_25
	LDR R1, [R0]
	LDR R7, =on
	CMP R1, R7
	BNE led_off
	BEQ led_on

led_off:
	LDR R0, =value_to_lower_25th_led	// all 1's except 25th bit
	LDR R1, =data_out_clear_reg
	LDR R2, [R1]
	AND R2, R2, R0				// turns 25th bit to 0
	STR R2, [R1]				// so it wont compete with set reg.
	LDR R0, =value_turn_on_25th_led
	LDR R1, =data_out_set_reg
	LDR R2, [R1]
	ORR R2, R2, R0				// puts a 1 at 25th bit	
	STR R2, [R1]				// turns on 25th led
	LDR R0, =on
	LDR R1, =status_25
	STR R0, [R1]				// updating status of led

	BL unlock

led_on:
	
	LDR R0, =value_to_lower_25th_led	// all 1's except 25th bit
	LDR R1, =data_out_set_reg
	LDR R2, [R1]
	AND R2, R2, R0				// turns 25th bit to 0
	STR R2, [R1]				// so it wont fight with clear reg
	LDR R0, =value_turn_on_25th_led
	LDR R1, =data_out_clear_reg
	LDR R2, [R1]
	ORR R2, R2, R0				// puts 1 in 25th bit
	STR R2, [R1]				// turns off led
	LDR R0, =off
	LDR R1, =status_25
	STR R0, [R1]				// updating status of led
	BL unlock

unlock:

unlock_mutex_PROC:
	
	
	LDR R0, =LOCK
	LDR R1, =unlocked
	DMB
	STR R1, [R0]			// unlock mutex

	BL start
	BL start






	




