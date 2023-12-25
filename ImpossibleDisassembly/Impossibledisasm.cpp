
#include <iostream>

void naber() {
    __asm {
        _emit 0xE8
    }
    std::cout << "selam canim";

}


int main()
{
    __asm {
        _emit 0xEB
        _emit 0xFF
        _emit 0xC0
    };

   
    __asm {
        call naber+4
    }
   
    std::cout << "ZAYOTEM";



}
