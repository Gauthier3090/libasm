			section .text
			global	ft_read
			extern __errno_location

ft_read:
			mov rax, 0
			syscall
			jc errno
			ret

errno:
			neg rax
			push rax
			call __errno_location
			mov rdi, rax
			pop rax
			mov [rdi], rax
			mov rax, -1
			ret
