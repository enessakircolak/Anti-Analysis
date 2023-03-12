
#include <iostream>
using namespace std;

// Class
class GFG {

public:
    // Constructor of the class
    GFG()
    {

        // Call the other function
        func();
    }

    // Function to get executed before main()
    void func()
    {
        cout << "live with the sword die by sword"
            << endl;
    }
};

// Global variable to declare
// the object of class GFG
GFG obj;

// obj variable will initialize before main !!!
// so func() will run 

int main()
{
    cout << "Welcome to you Castle Sir!!" << endl;
    return 0;
}