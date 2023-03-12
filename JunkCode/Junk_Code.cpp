#include <iostream>

int main()
{
    int x = 10;
    if (x != 10) {
        std::cout << "This should never happen!" << std::endl; // Junk code satırı 1
    }
    x = x + 0; // Junk code satırı 2
    std::cout << "The value of x is " << x << std::endl;

    __asm {
        push ebp
        mov ebp, esp
        xor eax, eax
        mov ecx, 0x8
        or eax, ecx
        xor eax, ecx
        mov edx, eax
        sub eax, edx
        mov eax, 1
        xor ebx, ebx
    }
    return 0;
}