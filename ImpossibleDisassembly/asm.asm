

.code
MySegment segment read execute

selamcanim PROC

_start:
    db 0ebH,0ffH,0c0H  ; ilk 2 byte jmp -1   // bu atlamanýn ardýndan ff opcode'u c0 ile beraber kullanýyor ve bu atlamadan sonra düzeliyor kod öncesinde
    mov rax,1					   // burada c0 diðer kodlarla birleþip bozuluyor
    mov rdi,1
    jmp short next

    buffer db "Evil Code!",10
    len equ $-buffer

next:   
    mov rsi,qword ptr buffer
    mov rdx,len
    syscall
    mov rax,60
    mov rdi,0
    syscall
   

selamcanim endp

MySegment ends
end