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
	
MAIN:
	LDR R0, =value_of_25M
	LDR R1, =GT3reload
	STR R0, [R1]
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
	LDR R0, =value_turn_on_25th_led
	LDR R1, =value_for_GTcr
	LDR R2, =data_out_set_reg
	LDR R3, =data_enable_set_reg
	MOV R4, #0 		//counter
	MOV R7, #0
	STR R0, [R3]		//keep low in 25th pin
	LDR R5, =value_of_25M
	LDR R6, =GT3_reg
	STR R5, [R6]		//put 25M into GT3
	LDR R3, =GT_control_reg
	LDR R11, =data_out_clear_reg
	LDR R12, =value_of_25M

	BL q_1_a		//reset counter
return1:

	
	STR R1, [R3] 		// enables countdown

while:
	ADDS R4, R4, #1
	ADC R7, R7, #0
	BL while		//polls counter
	BL done




q_1_a:	//resets counter

		MOV R7, #0
		LDR R8, =MSB_64bit_counter
		ADD R9, R8, #4
		STR R7, [R8]
		STR R7, [R9]
BL 		return1

done:	

		LDR R8, =MSB_64bit_counter
		LDR R9, =LSB_64bit_counter
		LDR R7, [R8]
		LDR R10, [R9]
	
	

	
	
