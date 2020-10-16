			section .text
			global	ft_strcpy

ft_strcpy:
			xor rax, rax ; initialise le registre rax à zéro

start:
			mov ch, byte[rsi + rax] ; equivaut à dire que ch = rsi[rax]
			mov byte[rdi + rax], ch ; equivaut à dire que rdi[rax] = ch
			cmp ch, 0 ; si ch == '/0'
			je end ; si c'est égale alors on passe à la fonction end
			inc rax ; sinon on incrémente le registre rax
			jmp start ; on recommence la fonction start

end:
			mov rax, rdi ; on copie le registre rdi dans rax
			ret ; on retourne le résultat du registre rax
