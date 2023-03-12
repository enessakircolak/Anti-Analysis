;/SAFESEH:NO
.386
.model flat

.DATA
donus    DD 55
cagri    DD 55

.code

MySegment segment read execute

_selamcanim proc
	push ebp
	mov ebp,esp
MyFunc:

	mov eax,[ebp+8]
	cmp eax,1
	jz dbg
	mov eax,[ebp+12]
	call eax
	ret



dbg:
	mov eax,[ebp+16]
	call eax
	ret

_selamcanim endp

MySegment ends

end

	;MyFunc:
	;ASSUME FS:NOTHING  
	;mov	eax,[fs:30h]
	;ASSUME FS:ERROR
	;mov	eax,[eax+0Ch]   
	;mov	esi,[eax+1Ch]
	;mov	ebx,[eax+08h]