

.code
MySegment segment read execute

selamcanim PROC

_start:
    db 0ebH,0ffH,0c0H  ; ilk 2 byte jmp -1   // bu atlaman�n ard�ndan ff opcode'u c0 ile beraber kullan�yor ve bu atlamadan sonra d�zeliyor kod �ncesinde
    mov rax,1					   // burada c0 di�er kodlarla birle�ip bozuluyor
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