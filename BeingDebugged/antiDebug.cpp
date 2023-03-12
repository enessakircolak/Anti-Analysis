#include <iostream>
#include <Windows.h>
using namespace std;


extern "C" int selamcanim();

int main()
{
    int b;
    bool a;
    a = selamcanim();  // this is assembly func
    // a will set if beingDebugged flag "1" 

    cout << "Soldier is there clear ? " <<endl;
 	
    if (a == 1) {
		//debugging
        std::cout << "Negatif\n";
        return 0;
    }
    else {
        std::cout << "Affirmative\n";
    
        system("pause");
    }

}
