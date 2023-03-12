
#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
    __asm {
        mov eax, 5  
        cmp eax, 5
        jz zipla   	; zero flag set edilirse atlayacağı yer 
        jnz zipla		; zero flag set edilmezse atlayacağı yer
        mov eax, 2	; görüldüğü gibi iki şekilde de atlayacağı yer aynı 
	  dec eax		; o yüzden bu iki satır hiç çalışmayacak
        zipla:
        mov eax,3
    }
}

