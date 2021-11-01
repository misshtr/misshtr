#include <asm/system.h>
.global interrupt_vector
interrupt_vector:

LDR PC, =0xC200410
	
