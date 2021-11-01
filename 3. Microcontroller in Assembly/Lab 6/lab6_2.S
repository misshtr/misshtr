.global _start
_start:

#define disk_0		0xC400000
#define disk_1		0xC402000
#define disk_2		0xC404000
#define disk_3		0xC406000
#define parity_disk	0xC408000
#define Eng_X_Ch_0	0xF1060920
#define X_Config	0xF1060910
#define Desc_PTR	0xF1060B00
#define CRC_0		0xC401000
#define CRC_1		0xC401004
#define CRC_2		0xC401008
#define CRC_3		0xC40100C

#define NCRC_0		0xC411000
#define NCRC_1		0xC411004
#define NCRC_2		0xC411008
#define NCRC_3		0xC41100C

#define NCRC_0_status 	0x741100
#define NCRC_0_CRC	0x741104
#define NCRC_0_command  0x741108
#define NCRC_0_next	0x74110C
#define NCRC_0_byte	0x741110		
#define NCRC_0_dest	0x741114
#define NCRC_0_source	0x741118

#define NCRC_1_status	0x742140
#define NCRC_1_CRC	0x742144
#define NCRC_1_command	0x742148
#define NCRC_1_next	0x74214C
#define NCRC_1_byte	0x742150
#define NCRC_1_dest	0x742154
#define NCRC_1_source	0x742158

#define NCRC_2_status	0x743180
#define NCRC_2_CRC	0x743184
#define NCRC_2_command  0x743188
#define NCRC_2_next	0x74318C
#define NCRC_2_byte	0x743190
#define NCRC_2_dest	0x743194
#define NCRC_2_source	0x743198

#define NCRC_3_status	0x7441C0
#define NCRC_3_CRC	0x7441C4
#define NCRC_3_command	0x7441C8
#define NCRC_3_next	0x7441CC
#define NCRC_3_byte	0x7441D0
#define NCRC_3_dest	0x7441D4
#define NCRC_3_source	0x7441D8

#define parity_0_status		0x745200
#define parity_0_CRC		0x745204
#define parity_0_command	0x745208
#define parity_0_next		0x74520C
#define parity_0_byte		0x745210
#define parity_0_dest		0x745214
#define parity_0_source		0x745218

#define parity_1_status		0x746200
#define parity_1_CRC		0x746204
#define parity_1_command	0x746208
#define parity_1_next		0x74620C
#define parity_1_byte		0x746210
#define parity_1_dest		0x746214
#define parity_1_source		0x746218

#define parity_2_status		0x747200
#define parity_2_CRC		0x747204
#define parity_2_command	0x747208
#define parity_2_next		0x74720C
#define parity_2_byte		0x747210
#define parity_2_dest		0x747214
#define parity_2_source		0x747218

#define parity_3_status		0x747200
#define parity_3_CRC		0x747204
#define parity_3_command	0x747208
#define parity_3_next		0x74720C
#define parity_3_byte		0x747210
#define parity_3_dest		0x747214
#define parity_3_source		0x747218




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


CRC_0_calc:
	
	LDR R0, =NCRC_0_status
	LDR R1, [R0]
	LDR R2, =0x80000000	//mask value 31bit
	ORR R1, R1, R2
	STR R1, [R0]		//put #1 in status val
	LDR R0, =NCRC_0_command
	LDR R1, =0x4100000F	//mask value to turn on CRC mode
	STR R1, [R0]		//turn on CRC mode
	LDR R0, =NCRC_0_next
	LDR R1, =NCRC_1_status
	STR R1, [R0]		//connected the next node
	LDR R0, =NCRC_0_byte
	LDR R1, =0x1000		//num of bytes to load
	STR R1, [R0]
	LDR R0, =NCRC_0_dest
	LDR R1, =NCRC_0
	STR R1, [R0]		//storing the address of destination (CRC 0)
	LDR R0, =NCRC_0_source
	LDR R1, =disk_0
	STR R1, [R0]
		

CRC_1_calc:

	LDR R0, =NCRC_1_status
	LDR R1, [R0]
	LDR R2, =0x80000000	//mask value 31bit
	ORR R1, R1, R2
	STR R1, [R0]		//put #1 in status val
	LDR R0, =NCRC_1_command
	//LDR R1, [R0]
	LDR R2, =0x4100000F	//mask value to turn on CRC mode
	//ORR R1, R1, R2
	STR R2, [R0]		//turn on CRC mode
	LDR R0, =NCRC_1_next
	LDR R1, =NCRC_2_status
	STR R1, [R0]		//connected the next node
	LDR R0, =NCRC_1_byte
	LDR R1, =0x1000		//num of bytes to load
	STR R1, [R0]
	LDR R0, =NCRC_1_dest
	LDR R1, =NCRC_1
	STR R1, [R0]		//storing the address of destination (disk 0)
	LDR R0, =NCRC_1_source
	LDR R1, =disk_1
	STR R1, [R0]
	
	
CRC_2_calc:

	LDR R0, =NCRC_2_status
	LDR R1, [R0]
	LDR R2, =0x80000000	//mask value 31bit
	ORR R1, R1, R2
	STR R1, [R0]		//put #1 in status val
	LDR R0, =NCRC_2_command
	//LDR R1, [R0]
	LDR R2, =0x4100000F	//mask value to turn on CRC mode
	//ORR R1, R1, R2
	STR R2, [R0]		//turn on CRC mode
	LDR R0, =NCRC_2_next
	LDR R1, =NCRC_3_status
	STR R1, [R0]		//connected the next node
	LDR R0, =NCRC_2_byte
	LDR R1, =0x1000		//num of bytes to load
	STR R1, [R0]
	LDR R0, =NCRC_2_dest
	LDR R1, =NCRC_2
	STR R1, [R0]		//storing the address of destination (disk 3)
	LDR R0, =NCRC_2_source
	LDR R1, =disk_2
	STR R1, [R0]	
		

CRC_3_calc:	

	LDR R0, =NCRC_3_status
	LDR R1, [R0]
	LDR R2, =0x80000000	//mask value 31bit
	ORR R1, R1, R2
	STR R1, [R0]		//put #1 in status val
	LDR R0, =NCRC_3_command
	//LDR R1, [R0]
	LDR R2, =0x4100000F	//mask value to turn on CRC mode
	//ORR R1, R1, R2
	STR R2, [R0]		//turn on CRC mode
	LDR R0, =NCRC_3_next
	LDR R1, =0x0
	STR R1, [R0]		//connected the next node
	LDR R0, =NCRC_3_byte
	LDR R1, =0x1000		//num of bytes to load
	STR R1, [R0]
	LDR R0, =NCRC_3_dest
	LDR R1, =NCRC_3
	STR R1, [R0]		//storing the address of destination (disk 3)
	LDR R0, =NCRC_3_source
	LDR R1, =disk_3
	STR R1, [R0]
	

	LDR R0, =Desc_PTR	
	LDR R1, =NCRC_0_status
	STR R1, [R0]		//setting the ptr for head node
	LDR R0, =Eng_X_Ch_0
	LDR R1, [R0]

	LDR R0, =Eng_X_Ch_0		//gets value from XOR Engine Channel to check if its 0
	LDR R1, [R0]
	MOV R2, #1
	ORR R1, R1, R2		//masking 1st bit with a 1 to start process
	STR R1, [R0]		//activating the engine	

	

STORING_CRCS:

	LDR R0, =NCRC_0_CRC
	LDR R1, [R0]
	LDR R2, =NCRC_0	
	STR R1, [R2]

	LDR R0, =NCRC_1_CRC
	LDR R1, [R0]
	LDR R2, =NCRC_1	
	STR R1, [R2]

	LDR R0, =NCRC_2_CRC
	LDR R1, [R0]
	LDR R2, =NCRC_2	
	STR R1, [R2]

	LDR R0, =NCRC_3_CRC
	LDR R1, [R0]
	LDR R2, =NCRC_3	
	STR R1, [R2]

	MOV R10, #0		//NUM OF CURRUPTED DISKS - J count
	MOV R11, #-1		//REG TO SAVE FAULTY DISK NUM, DEFAULT VAL IS -1

	LDR R0, =CRC_0
	LDR R1, [R0]
	LDR R2, =NCRC_0
	LDR R3, [R2]
	CMP R1, R3
	ADDNE R10, R10, #1
	MOVNE R11, #0
	LDR R0, =CRC_1
	LDR R1, [R0]
	LDR R2, =NCRC_1
	LDR R3, [R2]
	CMP R1, R3
	ADDNE R10, R10, #1
	MOVNE R11, #1
	LDR R0, =CRC_2
	LDR R1, [R0]
	LDR R2, =NCRC_2
	LDR R3, [R2]
	CMP R1, R3
	ADDNE R10, R10, #1
	MOVNE R11, #2
	LDR R0, =CRC_3
	LDR R1, [R0]
	LDR R2, =NCRC_3
	LDR R3, [R2]
	CMP R1, R3
	ADDNE R10, R10, #1
	MOVNE R11, #3

	CMP R10, #1
	BEQ one_faulty
	BGT too_many
	BLT zero_faulty
	


zero_faulty:
	MOV R0, #0
	BL end


one_faulty:
	CMP R11, #1
	BGE d_0			//enters if disk 0 is faulty

	LDR R0, =Desc_PTR	
	LDR R1, =parity_0_status
	STR R1, [R0]		//setting the ptr for head node
	LDR R0, =Eng_X_Ch_0
	LDR R1, [R0]

	LDR R0, =parity_0_status
	LDR R1, [R0]
	LDR R2, =0x80000000	//mask value 31bit
	ORR R1, R1, R2
	STR R1, [R0]		//put #1 in status val
	LDR R0, =parity_0_command
	MOV R2, #0xF
	STR R2, [R0]		//turn on XOR mode and enable source address #0-3
	LDR R0, =parity_0_next
	MOV R1, #0 
	STR R1, [R0]		// no next desc. so points to NULL
	LDR R0, =parity_0_byte
	LDR R1, =0x1000		//num of bytes to load
	STR R1, [R0]
	LDR R0, =parity_0_dest
	LDR R1, =disk_0
	STR R1, [R0]		//storing the address of destination (disk 0)
	LDR R0, =parity_0_source
	LDR R1, =parity_disk
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
loop0:	
	CMP R0, #0		//polls to see if channel is available
	BNE loop0







	BL zero_faulty

d_0:
	BNE d_1			//enters if disk 1 is faulty

	LDR R0, =Desc_PTR	
	LDR R1, =parity_1_status
	STR R1, [R0]		//setting the ptr for head node
	LDR R0, =Eng_X_Ch_0
	LDR R1, [R0]

	LDR R0, =parity_1_status
	LDR R1, [R0]
	LDR R2, =0x80000000	//mask value 31bit
	ORR R1, R1, R2
	STR R1, [R0]		//put #1 in status val
	LDR R0, =parity_1_command
	MOV R2, #0xF
	STR R2, [R0]		//turn on XOR mode and enable source address #0-3
	LDR R0, =parity_1_next
	MOV R1, #0 
	STR R1, [R0]		// no next desc. so points to NULL
	LDR R0, =parity_1_byte
	LDR R1, =0x1000		//num of bytes to load
	STR R1, [R0]
	LDR R0, =parity_1_dest
	LDR R1, =disk_1
	STR R1, [R0]		//storing the address of destination (disk 0)
	LDR R0, =parity_1_source
	LDR R1, =disk_0
	STR R1, [R0]
	ADD R0, #0x4
	LDR R1, =parity_disk
	STR R1, [R0]
	ADD R0, #0x4
	LDR R1, =disk_2
	STR R1, [R0]
	ADD R0, #0x4
	LDR R1, =disk_3
	STR R1, [R0]
	

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
loop1:	
	CMP R0, #0		//polls to see if channel is available
	BNE loop1
	
	BL zero_faulty
d_1:

	CMP R11, #3
	BGE d_2			//enters if disk 2 is faulty

	LDR R0, =Desc_PTR	
	LDR R1, =parity_2_status
	STR R1, [R0]		//setting the ptr for head node
	LDR R0, =Eng_X_Ch_0
	LDR R1, [R0]

	LDR R0, =parity_2_status
	LDR R1, [R0]
	LDR R2, =0x80000000	//mask value 31bit
	ORR R1, R1, R2
	STR R1, [R0]		//put #1 in status val
	LDR R0, =parity_2_command
	MOV R2, #0xF
	STR R2, [R0]		//turn on XOR mode and enable source address #0-3
	LDR R0, =parity_2_next
	MOV R1, #0 
	STR R1, [R0]		// no next desc. so points to NULL
	LDR R0, =parity_2_byte
	LDR R1, =0x1000		//num of bytes to load
	STR R1, [R0]
	LDR R0, =parity_2_dest
	LDR R1, =disk_2
	STR R1, [R0]		//storing the address of destination (disk 0)
	LDR R0, =parity_2_source
	LDR R1, =disk_0
	STR R1, [R0]
	ADD R0, #0x4
	LDR R1, =disk_1
	STR R1, [R0]
	ADD R0, #0x4
	LDR R1, =parity_disk
	STR R1, [R0]
	ADD R0, #0x4
	LDR R1, =disk_3
	STR R1, [R0]
	
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



	BL zero_faulty

d_2:
	BNE d_3			//enters if disk 3 is faulty

	LDR R0, =Desc_PTR	
	LDR R1, =parity_3_status
	STR R1, [R0]		//setting the ptr for head node
	LDR R0, =Eng_X_Ch_0
	LDR R1, [R0]

	LDR R0, =parity_3_status
	LDR R1, [R0]
	LDR R2, =0x80000000	//mask value 31bit
	ORR R1, R1, R2
	STR R1, [R0]		//put #1 in status val
	LDR R0, =parity_3_command
	MOV R2, #0xF
	STR R2, [R0]		//turn on XOR mode and enable source address #0-3
	LDR R0, =parity_3_next
	MOV R1, #0 
	STR R1, [R0]		// no next desc. so points to NULL
	LDR R0, =parity_3_byte
	LDR R1, =0x1000		//num of bytes to load
	STR R1, [R0]
	LDR R0, =parity_3_dest
	LDR R1, =disk_3
	STR R1, [R0]		//storing the address of destination (disk 0)
	LDR R0, =parity_3_source
	LDR R1, =disk_0
	STR R1, [R0]
	ADD R0, #0x4
	LDR R1, =disk_1
	STR R1, [R0]
	ADD R0, #0x4
	LDR R1, =disk_2
	STR R1, [R0]
	ADD R0, #0x4
	LDR R1, =parity_disk
	STR R1, [R0]

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
loop3:	
	CMP R0, #0		//polls to see if channel is available
	BNE loop3


	BL zero_faulty
d_3:

too_many:
	MOV R0, #-1
	BL end


end:





