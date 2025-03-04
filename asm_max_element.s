.global asm_max_element
asm_max_element:
	@ R0 = pointer to first element of vec
	@ R1 = size of vec
	@	Note: R1 will be used as iterating variable so I dont have to use R4-R12
	@		  Thus, we will be iterating through the loop backwards
	@ R2 = current element of vec
	@ R3 = max element so far

	@ if (vec.size() == 0) return;
	CMP R1, #0
	B return

	@ Store the end value of vec as the max element initially
	LDR R3, [R0, R1, LSL #2]	@ R3 = vec[i]

	@ for (int i = vec.size(); i > 0; i--)
	loop:
		SUBS R1, #1 @ i -= 1
		BLE return	@ Return if size <= 0

		LDR R2, [R0, R1, LSL #2]	@ R2 = vec[i]

		CMP R2, R3		@ if (vec[i] > max)
		MOVGT R3, R2	@ 	R3 = R2;

		BAL loop
	
	return:
	MOV R0, R3
	BX LR
