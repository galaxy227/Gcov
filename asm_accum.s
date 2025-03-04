.global asm_accum

asm_accum:
	MOV R2,#0
LOOP:
	CMP R1,#0
	BEQ DONE
	LDR R3,[R0],#4
	ADD R2,R2,R3
	SUB R1,R1,#1
	BNE LOOP
DONE:
	MOV R0,R2
	BX LR
.section .note.GNU-stack
