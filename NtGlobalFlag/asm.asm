.386
.model flat

.code
MySegment segment read execute

_selamcanim proc

_start:

    ASSUME FS:NOTHING
    MOV EAX, FS:[030H]
    ASSUME FS:ERROR
    mov eax,dword ptr[eax+068H]; BeingDebugged bit
    cmp eax, 070H   ; set edilen değerler 0x10 0x20 0x40 bunlar totalde 070h olacak ve buna göre eax set edilecek
    jz flagged
    mov eax,0
    ret
flagged:
    mov eax,1    
    ret

_selamcanim endp

MySegment ends
end