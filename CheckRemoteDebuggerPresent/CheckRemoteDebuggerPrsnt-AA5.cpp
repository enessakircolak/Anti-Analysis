#include "windows.h"
#include <iostream>

int main(void)
{
    BOOL HasDebugPort = FALSE;
    system("pause");
    if (CheckRemoteDebuggerPresent(GetCurrentProcess(), &HasDebugPort))
    {
        std::cout << "Look what we got"<<std::endl;

        std::cout << HasDebugPort<<std::endl;

        if (HasDebugPort) {
		//if debug port is setted program will print this message
            std::cout << "WATCHAA WATCHAA WATCHAAAA RRKKOOOOOOO" << std::endl;
            return 0;
        }
        else {
		//here is for default 
            std::cout << "Nevermind, Go on"<<std::endl;
        }
         // Running in ring-3 debugger
    }
  
    system("pause");
    return 0;
}