	.global _start
_start:

#define disk_0		0xC400000
#define disk_1		0xC402000
#define disk_2		0xC404000
#define disk_3		0xC406000
#define parity_disk	0xC408000
#define file		0xC300000
#define Eng_X_Ch_0	0xF1060920
#define X_Config	0xF1060910
#define Desc_PTR	0xF1060B00
#define CRC_0		0xC401000
#define CRC_1		0xC401004
#define CRC_2		0xC401008
#define CRC_3		0xC40100C

#define desc_0_status	0x740000
#define desc_0_CRC	0x740004
#define desc_0_command  0x740008
#define desc_0_next	0x74000C
#define desc_0_byte	0x740010
#define desc_0_dest	0x740014
#define desc_0_source	0x740018

#define CRC_0_status 	0x740100
#define CRC_0_CRC	0x740104
#define CRC_0_command   0x740108
#define CRC_0_next	0x74010C
#define CRC_0_byte	0x740110
#define CRC_0_dest	0x740114
#define CRC_0_source	0x740118


#define desc_1_status	0x740040
#define desc_1_CRC	0x740044
#define desc_1_command	0x740048
#define desc_1_next	0x74004C
#define desc_1_byte	0x740050
#define desc_1_dest	0x740054
#define desc_1_source	0x740058

#define CRC_1_status	0x740140
#define CRC_1_CRC	0x740144
#define CRC_1_command	0x740148
#define CRC_1_next	0x74014C
#define CRC_1_byte	0x740150
#define CRC_1_dest	0x740154
#define CRC_1_source	0x740158

#define desc_2_status	0x740080
#define desc_2_CRC	0x740084
#define desc_2_command  0x740088
#define desc_2_next	0x74008C
#define desc_2_byte	0x740090
#define desc_2_dest	0x740094
#define desc_2_source	0x740098

#define CRC_2_status	0x740180
#define CRC_2_CRC	0x740184
#define CRC_2_command   0x740188
#define CRC_2_next	0x74018C
#define CRC_2_byte	0x740190
#define CRC_2_dest	0x740194
#define CRC_2_source	0x740198

#define desc_3_status	0x7400C0
#define desc_3_CRC	0x7400C4
#define desc_3_command	0x7400C8
#define desc_3_next	0x7400CC
#define desc_3_byte	0x7400D0
#define desc_3_dest	0x7400D4
#define desc_3_source	0x7400D8

#define CRC_3_status	0x7401C0
#define CRC_3_CRC	0x7401C4
#define CRC_3_command	0x7401C8
#define CRC_3_next	0x7401CC
#define CRC_3_byte	0x7401D0
#define CRC_3_dest	0x7401D4
#define CRC_3_source	0x7401D8

#define parity_status	0x740200
#define parity_CRC	0x740204
#define parity_command	0x740208
#define parity_next	0x74020C
#define parity_byte	0x740210
#define parity_dest	0x740214
#define parity_source	0x740218


	LDR R0, =Eng_X_Ch_0	//gets value from XOR Engine Channel to check if its 0
	LDR R1, [R0]
	MOV R0, #0x30
	AND R0, R0, R1
	LSL R0, R0, #4
loop:	
	CMP R0, #0		//polls to see if channel is available
	BNE loop

	LDR R0, =X_Config
	LDR R1, =0x447		// mask value
	STR R1, [R0]		// setting engine configuration register


PREPARING_DESCRIPTORS:


DMA_0_store:

	LDR R0, =desc_0_status
	LDR R1, [R0]
	LDR R2, =0x80000000	//mask value 31bit
	ORR R1, R1, R2
	STR R1, [R0]		//put #1 in status val
	LDR R0, =desc_0_command
	//LDR R1, [R0]
	LDR R2, =0x2000000	//mask value to turn on DMA mode
	//ORR R1, R1, R2
	STR R2, [R0]		//turn on DMA mode
	LDR R0, =desc_0_next
	LDR R1, =desc_1_status
	STR R1, [R0]		//calls next node
	LDR R0, =desc_0_byte
	LDR R1, =0x1000		//num of bytes to load
	STR R1, [R0]
	LDR R0, =desc_0_dest
	LDR R1, =disk_0
	STR R1, [R0]		//storing the address of destination (disk 0)
	LDR R0, =desc_0_source
	LDR R1, =file
	STR R1, [R0]



DMA_1_store:
	
	LDR R0, =desc_1_status
	LDR R1, [R0]
	LDR R2, =0x80000000	//mask value 31bit
	ORR R1, R1, R2
	STR R1, [R0]		//put #1 in status val
	LDR R0, =desc_1_command
	//LDR R1, [R0]
	LDR R2, =0x2000000	//mask value to turn on DMA mode
	//ORR R1, R1, R2
	STR R2, [R0]		//turn on DMA mode
	LDR R0, =desc_1_next
	LDR R1, =desc_2_status
	STR R1, [R0]		//connected the next node
	LDR R0, =desc_1_byte
	LDR R1, =0x1000		//num of bytes to load
	STR R1, [R0]
	LDR R0, =desc_1_dest
	LDR R1, =disk_1
	STR R1, [R0]		//storing the address of destination (disk 1)
	LDR R0, =desc_1_source
	LDR R1, =file
	ADD R1, R1, #0x1000
	STR R1, [R0]	



DMA_2_store:

	LDR R0, =desc_2_status
	LDR R1, [R0]
	LDR R2, =0x80000000	//mask value 31bit
	ORR R1, R1, R2
	STR R1, [R0]		//put #1 in status val
	LDR R0, =desc_2_command
	//LDR R1, [R0]
	LDR R2, =0x2000000	//mask value to turn on DMA mode
	//ORR R1, R1, R2
	STR R2, [R0]		//turn on DMA mode
	LDR R0, =desc_2_next
	LDR R1, =desc_3_status
	STR R1, [R0]		//connected the next node
	LDR R0, =desc_2_byte
	LDR R1, =0x1000		//num of bytes to load
	STR R1, [R0]
	LDR R0, =desc_2_dest
	LDR R1, =disk_2
	STR R1, [R0]		//storing the address of destination (disk 3)
	LDR R0, =desc_2_source
	LDR R1, =file
	ADD R1, R1, #0x2000
	STR R1, [R0]	


DMA_3_store:
	
	LDR R0, =desc_3_status
	LDR R1, [R0]
	LDR R2, =0x80000000	//mask value 31bit
	ORR R1, R1, R2
	STR R1, [R0]		//put #1 in status val
	LDR R0, =desc_3_command
	//LDR R1, [R0]
	LDR R2, =0x2000000	//mask value to turn on DMA mode
	//ORR R1, R1, R2
	STR R2, [R0]		//turn on DMA mode
	LDR R0, =desc_3_next
	MOV R1, #0
	STR R1, [R0]		//connected the next node
	LDR R0, =desc_3_byte
	LDR R1, =0x1000		//num of bytes to load
	STR R1, [R0]
	LDR R0, =desc_3_dest
	LDR R1, =disk_3
	STR R1, [R0]		//storing the address of destination (disk 3)
	LDR R0, =desc_3_source
	LDR R1, =file
	ADD R1, R1, #0x3000
	STR R1, [R0]

POINTER0:	

	LDR R0, =Desc_PTR	
	LDR R1, =desc_0_status
	STR R1, [R0]		//setting the ptr for head node
	LDR R0, =Eng_X_Ch_0
	LDR R1, [R0]

LDR R0, =Eng_X_Ch_0		//gets value from XOR Engine Channel to check if its 0
	LDR R1, [R0]
	MOV R2, #1
	ORR R1, R1, R2		//masking 1st bit with a 1 to start process
	STR R1, [R0]		//activating the engine

	LDR R0, =Eng_X_Ch_0	//gets value from XOR Engine Channel to check if its 0
	LDR R1, [R0]
	MOV R0, #0x30
	AND R0, R0, R1
	LSL R0, R0, #4
loop0:	
	CMP R0, #0		//polls to see if channel is available
	BNE loop0


CRC_0_calc:
	
	LDR R0, =CRC_0_status
	LDR R1, [R0]
	LDR R2, =0x80000000	//mask value 31bit
	ORR R1, R1, R2
	STR R1, [R0]		//put #1 in status val
	LDR R0, =CRC_0_command
	LDR R2, =0x4100000F	//mask value to turn on CRC mode
	STR R2, [R0]		//turn on CRC mode
	LDR R0, =CRC_0_next
	LDR R1, =CRC_1_status
	STR R1, [R0]		//connected the next node
	LDR R0, =CRC_0_byte
	LDR R1, =0x1000		//num of bytes to load
	STR R1, [R0]
	LDR R0, =CRC_0_dest
	LDR R1, =CRC_0
	STR R1, [R0]		//storing the address of destination (CRC 0)
	LDR R0, =CRC_0_source
	LDR R1, =disk_0
	STR R1, [R0]
		

CRC_1_calc:

	LDR R0, =CRC_1_status
	LDR R1, [R0]
	LDR R2, =0x80000000	//mask value 31bit
	ORR R1, R1, R2
	STR R1, [R0]		//put #1 in status val
	LDR R0, =CRC_1_command
	LDR R2, =0x4100000F	//mask value to turn on CRC mode
	STR R2, [R0]		//turn on CRC mode
	LDR R0, =CRC_1_next
	LDR R1, =CRC_2_status
	STR R1, [R0]		//connected the next node
	LDR R0, =CRC_1_byte
	LDR R1, =0x1000		//num of bytes to load
	STR R1, [R0]
	LDR R0, =CRC_1_dest
	LDR R1, =CRC_1
	STR R1, [R0]		//storing the address of destination (disk 0)
	LDR R0, =CRC_1_source
	LDR R1, =disk_1
	STR R1, [R0]
	

CRC_2_calc:

	LDR R0, =CRC_2_status
	LDR R1, [R0]
	LDR R2, =0x80000000	//mask value 31bit
	ORR R1, R1, R2
	STR R1, [R0]		//put #1 in status val
	LDR R0, =CRC_2_command
	LDR R2, =0x4100000F	//mask value to turn on CRC mode
	STR R2, [R0]		//turn on CRC mode
	LDR R0, =CRC_2_next
	LDR R1, =CRC_3_status
	STR R1, [R0]		//connected the next node
	LDR R0, =CRC_2_byte
	LDR R1, =0x1000		//num of bytes to load
	STR R1, [R0]
	LDR R0, =CRC_2_dest
	LDR R1, =CRC_2
	STR R1, [R0]		//storing the address of destination (disk 3)
	LDR R0, =CRC_2_source
	LDR R1, =disk_2
	STR R1, [R0]
		
		


CRC_3_calc:	

	LDR R0, =CRC_3_status
	LDR R1, [R0]
	LDR R2, =0x80000000	//mask value 31bit
	ORR R1, R1, R2
	STR R1, [R0]		//put #1 in status val
	LDR R0, =CRC_3_command
	LDR R2, =0x4100000F	//mask value to turn on CRC mode
	STR R2, [R0]		//turn on CRC mode
	LDR R0, =CRC_3_next
	MOV R1, #0
	STR R1, [R0]		//connected the next node
	LDR R0, =CRC_3_byte
	LDR R1, =0x1000		//num of bytes to load
	STR R1, [R0]
	LDR R0, =CRC_3_dest
	LDR R1, =CRC_3
	STR R1, [R0]		//storing the address of destination (disk 3)
	LDR R0, =CRC_3_source
	LDR R1, =disk_3
	STR R1, [R0]
	


POINTER1:	

	LDR R0, =Desc_PTR	
	LDR R1, =CRC_0_status
	STR R1, [R0]		//setting the ptr for head node
	LDR R0, =Eng_X_Ch_0
	LDR R1, [R0]

	LDR R0, =Eng_X_Ch_0		//gets value from XOR Engine Channel to check if its 0
	LDR R1, [R0]
	MOV R2, #1
	ORR R1, R1, R2		//masking 1st bit with a 1 to start process
	STR R1, [R0]		//activating the engine

	LDR R0, =Eng_X_Ch_0	//gets value from XOR Engine Channel to check if its 0
	LDR R1, [R0]
	MOV R0, #0x30
	AND R0, R0, R1
	LSL R0, R0, #4
loop1:	
	CMP R0, #0		//polls to see if channel is available
	BNE loop1

STORING_CRCS:

	LDR R0, =CRC_0_CRC
	LDR R1, [R0]
	LDR R2, =CRC_0	
	STR R1, [R2]

	LDR R0, =CRC_1_CRC
	LDR R1, [R0]
	LDR R2, =CRC_1	
	STR R1, [R2]

	LDR R0, =CRC_2_CRC
	LDR R1, [R0]
	LDR R2, =CRC_2	
	STR R1, [R2]

	LDR R0, =CRC_3_CRC
	LDR R1, [R0]
	LDR R2, =CRC_3	
	STR R1, [R2]

PARITY_CALC:
	
	LDR R0, =parity_status
	LDR R1, [R0]
	LDR R2, =0x80000000	//mask value 31bit
	ORR R1, R1, R2
	STR R1, [R0]		//put #1 in status val
	LDR R0, =parity_command
	MOV R2, #0xF
	STR R2, [R0]		//turn on XOR mode and enable source address #0-3
	LDR R0, =parity_next
	MOV R1, #0 
	STR R1, [R0]		// no next desc. so points to NULL
	LDR R0, =parity_byte
	LDR R1, =0x1000		//num of bytes to load
	STR R1, [R0]
	LDR R0, =parity_dest
	LDR R1, =parity_disk
	STR R1, [R0]		//storing the address of destination (disk 0)
	LDR R0, =parity_source
	LDR R1, =disk_0
	STR R1, [R0]
	ADD R0, #0x4
	LDR R1, =disk_1
	STR R1, [R0]
	ADD R0, #0x4
	LDR R1, =disk_2
	STR R1, [R0]
	ADD R0, #0x4
	LDR R1, =disk_3
	STR R1, [R0]

POINTER2:	

	LDR R0, =Desc_PTR	
	LDR R1, =parity_status
	STR R1, [R0]		//setting the ptr for head node
	LDR R0, =Eng_X_Ch_0
	LDR R1, [R0]

	
	LDR R0, =Eng_X_Ch_0	//gets value from XOR Engine Channel to check if its 0
	LDR R1, [R0]
	MOV R2, #1
	ORR R1, R1, R2		//masking 1st bit with a 1 to start process
	STR R1, [R0]		//activating the engine

	LDR R0, =Eng_X_Ch_0	//gets value from XOR Engine Channel to check if its 0
	LDR R1, [R0]
	MOV R0, #0x30
	AND R0, R0, R1
	LSL R0, R0, #4
loop2:	
	CMP R0, #0		//polls to see if channel is available
	BNE loop2

//stahhhppppp

	

	

	
	

	
	

	










	
