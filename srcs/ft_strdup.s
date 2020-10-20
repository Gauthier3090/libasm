			section .text
			global	ft_strdup
			extern	ft_strlen
			extern	ft_strcpy
			extern	malloc

ft_strdup:
			cmp rdi, 0x0
			jz is_null
			push rdi
			call ft_strlen
			inc rax
			mov rdi, rax
			call malloc
			pop rdi
			cmp rax, 0
			je is_null
			mov rsi, rdi
			mov rdi, rax
			call ft_strcpy
			ret

is_null:
			mov rax, 0
			ret
