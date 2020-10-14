			section .text
			global	_ft_strcmp

_ft_strcmp:
			xor rax, rax

start:
			mov		al, byte [rdi]
			mov		bl, byte [rsi]
			cmp		al, 0
			je		end
			cmp		bl, 0
			je		end
			cmp 	al, bl
			jne 	end
			inc 	rdi
			inc 	rsi
			jmp 	start


end:
			movsx rax, al
			movsx rbx, bl
			sub rax, rbx
			ret
