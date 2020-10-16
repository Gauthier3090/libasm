			section .text
			global	ft_read
			extern __errno_location

ft_read:
    mov     rax, 0
    syscall
    jc      errno
    ret

errno:
    push    rbx
    mov     rbx, rax
    call    __errno_location
    mov     [rax], rbx
    pop     rbx
    mov     rax, -1
    ret
