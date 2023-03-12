
#include <iostream>
#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <algorithm>
#include <vector>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;
int main() {

    bool enter = 0;

    string filename = "C:\\Users\\%USERNAME%\\AppData\\Local\\Temp\\getmacaddress.txt";
    system(("getmac >" + filename).c_str());
    // ifstream myfile("macaddress.txt");
    char* user = getenv("username");

    string username = user;

    ifstream file;
    string line;
    file.open("C:\\Users\\" + username + "\\AppData\\Local\\Temp\\getmacaddress.txt");

    vector<string> lines;

    while (getline(file, line)) {
        lines.push_back(line);
    }
    file.close();

    string content = "";
    // cout << deli;
    file.open("C:\\Users\\" + username + "\\AppData\\Local\\Temp\\getmacaddress.txt");
    string mac;
    int i = 0;
    while (file >> content) {
        if (i != 0)
        {
            if (content == "N/A")
                i = i;
            else if (content.length() == 17) {

                mac = content;
                break;
            }
        }
        if (content == "==========================================================") {
            i++;
        }
    }
    //cout << mac << endl;
    bool VM = 0;

  
    string enc;
    int c=0;
    for (auto a : mac) {
        if (a != '-' && c < 6) {
            enc += a;
            c++;
        }
    }

    if (enc == "000C29") { // "00:0C:29" mean Vmware INC.  so we can understand if it is equal this machine is a VM
        VM = 1;
        cout << "I see who you are, you are my enemy!!!";
        
    }
    cout << mac << endl;
    cout <<"Ayna ayna soyle bana kimsin sen " << VM << endl;



}
