
.386
.model flat

.code
MySegment segment read execute

_selamcanim proc

_start:

    ASSUME FS:NOTHING
    MOV EAX, FS:[030H]
    ASSUME FS:ERROR
    mov ah, [eax+2]
    xor edx,edx
    mov dh,ah
    xor eax,eax
    mov eax,edx
    
    ret

_selamcanim endp

MySegment ends
end