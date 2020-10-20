			section .text
			global	ft_strcpy

ft_strcpy:
			xor rax, rax

start:
			mov ch, byte[rsi + rax]
			mov byte[rdi + rax], ch
			cmp ch, 0
			je end
			inc rax
			jmp start

end:
			mov rax, rdi
			ret
