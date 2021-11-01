#include <asm/system.h>
.global _start
_start:

ENABLE_MPP_25_AS_GPIO:
	ldr r1, =0xF101800C
	mov r0, #0x000000F0
	ldr r2, [r1]
	bic r2, r0
	str r2, [r1]

Configurations:
	//SCTLR - configire bit 13 (V) to 0 
	mrc p15,0,r0,c1,c2,0 
	bic r0,r0,#0x2000
	mcr p15,0,r0,c1,c2,0
	
	//VBAR - configure a new address for interrupt vector
	ldr r1,=0xc200000
	mcr p15,0,r1,c12,c0,0
	
	
distributor:
	ldr r1,=0xF100D000 //ICDDCR - disable distributor
	mov r0,#0x0
	strb r0,[r1]
	
	ldr r1,=0xF100D828 //
	mov r0,#0x01000000
	str r0,[r1]
	
	mov r2,#0x3d
	ldr r0,=0x55555555
	ldr r3,=0xF100DC08
	
	IDCICFRLoop:
		str r0,[r3],#4
		subs r2,r2,#0x1
		bpl IDCICFRLoop

	mov r2,#0xF6
	ldr r0,=0xA0A0A0A0
	ldr r3,=0xF100D420
	
	ICDIPRLoop:
		str r0,[r3],#4
		subs r2,r2,#0x1
		bpl ICDIPRLoop
	
	mov r2,#0x1F	
	mvn r0,#0x0		//0xffffffff
	ldr r3,=0xF100D180
	
	ICDICERLoop:
		str r0,[r3],#4
		subs r2,r2,#0x1
		bpl ICDICERLoop	
	
	ldr r1,=0xF100D000 	//ICDDCR - enable distrebutor
	mov r0,#0x1
	strb r0,[r1]
	
	ldr r1,=0xF100D104	//Enable the timer3 interrupt in the Distributor
	mov r0,#0x0800 
	str r0,[r1]
	

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

#define value_turn_on_25th_led		0x2000000
#define MSB_counter_A			0x740008
#define LSB_counter_A			0x74000C
#define MSB_counter_B			0x740108
#define LSB_counter_B			0x74010C
#define last_process			0xC400000		//00- starting point -> 01- A1 -> 10-A2 -> 11-B -> A1 etc.
#define first_round			0x740010		// 1 	IF FIRST ROUND, 0 OTHERWISE


	
MAIN:
	
	MOV R0, #0xF0
	LDR R1, =0xF100C104
	STR R0, [R1]
	MOV R0, #1
	LDR R1, =0xF100C100	//enable overall interrupts
	STR R0, [R1]
	MRS R0, CPSR		//get value of CPSR
	MOV R1, #0x7F		//mask for bits 7-0 to unmask 7th bit
	AND R1, R1, R0		//masking
	MSR CPSR_c, R1		//enable IRQ
	MRS R0, CPSR
	MOV R2, R0
	MVN R1, #0B11111
	AND R0, R0, R1
	MOV R1, #0b10010
	ORR R0, R0, R1
	MSR CPSR_c, R0
	LDR SP, =0x0D100100
	MSR CPSR_c, R2

	LDR R0, =LOCK
	LDR R1, =unlocked	
	STR R1, [R0]				// initiliazes mutex value to unlocked	
	

	MOV R0, #0
	LDR R1, =last_process
	STR R0, [R1]				// intilaizes last process as 'starting point'

	LDR R0, =first_round
	MOV R1, #1
	STR R1, [R0]				// so we know we're in the first round
	

	LDR R0, =value_of_125M
	LDR R1, =GT3_reg
	STR R0, [R1]			
	

	LDR R0, =value_turn_on_25th_led
	LDR R1, =value_turn_on_29th_led
	ORR R1, R1, R0				// will now hold value for both 25 and 29 led				
	LDR R2, =data_enable_clear_reg
	STR R1, [R2]				// keep 25th and 29th led low
	

	LDR R0, =value_for_GTcr
	LDR R1, =GT_control_reg			//sets frequencies to 25Mhz, GT3 on auto-reload (1-2 not on auto)
	STR R0, [R1]
	

	MOV R0, #0
	LDR R1, =data_out_clear_reg
	STR R0, [R1]				//makes sure clear reg is all 0's (reg that turns off leds)
	

	LDR R0, =value_turn_on_25th_led
	LDR R1, =value_turn_on_29th_led
	ORR R0, R0, R1				//creates value to turn on both leds at once
	LDR R1, =data_out_set_reg
	STR R0, [R1]				// turns on both leds
	

	LDR R0, =on
	LDR R1, =status_25
	LDR R2, =status_29
	STR R0, [R1]
	STR R0, [R2]				// saves the status of both leds as 'on' in memory

	MOV R0, #0				// reseting counters
	LDR R1, =MSB_counter_B
	LDR R2, =LSB_counter_B
	STR R0, [R1]
	STR R0, [R2]
	LDR R1, =MSB_counter_A
	LDR R2, =LSB_counter_A
	STR R0, [R1]
	STR R0, [R2]
	

	LDR R0, =GT_control_reg
	LDR R1, [R0]				// value of timer control reg.	
	LDR R2, =value_to_enable_GT3		// value to enable GT3 timer
	ORR R1, R1, R2				// mask to enable GT3 timer
	

	MOV R2, #0				// preparing for loop
	
	STR R1, [R0]				// enables GT3 timer


loop:
	CMP R2, #0
	BEQ loop
	
	
	
	
	
	

