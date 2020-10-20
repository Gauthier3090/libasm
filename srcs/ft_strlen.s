			section .text
			global	ft_strlen

ft_strlen:
			xor		rax, rax
			jmp		start

increment:
			inc rax

start:
			cmp BYTE [rdi + rax], 0
			jne increment

end:
			ret
