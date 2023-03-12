#include <windows.h>
#include <iostream>
using namespace std;
#define POLICY_KEY TEXT("SOFTWARE\\VMware, Inc.\\VMware Tools")



int main() {

    HKEY hKey;

    LONG lResult;

    DWORD dwValue, dwType, dwSize = sizeof(dwValue);

    // First, check for a policy.

    lResult = RegOpenKeyEx(HKEY_CURRENT_USER, POLICY_KEY, 0, KEY_READ, &hKey);
    
    if (lResult == ERROR_SUCCESS) {
        cout << "VM Detected";   
        RegCloseKey(hKey);

    }
    else {
        cout << "Keep going !!!"<<endl;
    }
}