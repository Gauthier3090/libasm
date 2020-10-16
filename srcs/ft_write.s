			section .text
			global ft_write
			extern __errno_location
ft_write:
			mov rax, 1
			syscall
			jc errno
			ret

errno:
			push rax
			call __errno_location
			mov rdi, rax
			pop rax
			mov [rdi], rax
			mov rax, -1
			ret
