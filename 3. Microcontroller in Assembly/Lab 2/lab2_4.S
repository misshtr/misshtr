.global _start
_start:

	AND        R0, R4, R5
        MVN        R4, R4
	LDR	   R6, [R3]
        AND        R1, R4, R6
        ORR        R6, R1, R0
	STR	   R6, [R3]
 

