			section .text
			global	ft_strlen

ft_strlen:
			xor		rax, rax ; initialise le registre rax à zéro
			jmp		start    ; poursuit l'éxecution à la fonction start

increment:
			inc rax ; incrémente le registre rax

start:
			cmp BYTE [rdi + rax], 0 ; équivaut à dire str[i] == '\0'
			jne increment ; si la valeur n'est pas égale à '\0' alors on incrémente

end:
			ret ; retourne le résultat du registre rax
