.global _start
_start:


	CMP		R14, R12

	BEQ		equal		//ENTERS IF R12>R14
	BMI		lesser		//enters if r14>r12
												not_equal:
	LDMIA        R12!,    {R0-R11}
	STMIA        R13!,    {R0-R11}
        CMP        R12, R14
        BNE        not_equal
	BEQ		DONE	
	

lesser:
ney_equal:
	LDMDA        R12!,    {R0-R11}
	STMDA        R13!,    {R0-R11}
        CMP        R12, R14
        BNE        ney_equal
	BEQ		DONE

	equal:

	BNE		n_equal		//ENTERS IF R12=R14


	n_equal:
	DONE:
