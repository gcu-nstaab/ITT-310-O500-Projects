.586
.MODEL FLAT, C
.STACK
.DATA
.CODE
	
	
	PUBLIC add_asm

add_asm PROC, arg1:DWORD, arg2:DWORD
	mov eax, arg1
	add eax, arg2
	ret
	add_asm ENDP

END
