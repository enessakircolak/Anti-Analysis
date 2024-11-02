#include <iostream>
#include <memory>  // std::allocator kullanımı için gerekli
#include <stdio.h>
#include <windows.h>  
#include <fstream>  // Dosya işlemleri için gerekli
#include <regex>     // regex, regex_search
#include <io.h>
#include <string>
#include <stdexcept>
#include <my_utils.h>

bool dir_check = FALSE;

std::string my_substr(const std::string& str, size_t start, size_t length) {
    std::string result;

    // start pozisyonu string uzunluğunun dışındaysa, boş string döneriz
    //if (start >= str.size()) {
    //    //info("pass it");
    //    //info(str);
    //    //return result;
    //}
    
    // start pozisyonundan başla ve length kadar karakter ekle
    for (size_t i = start; i < start + length && i < str.size(); ++i) {
        result += str[i];
    }

    return result;
}

int allocateMemory(int a1, unsigned int a2)
{
    // Bellek ayırıcı (allocator) nesnesi oluşturuyoruz
    std::allocator<char> allocator;

    // Verilen boyutta bellek ayırıyoruz
    char* allocatedMemory = allocator.allocate(a2);

    // Bellek başarıyla ayrıldığında, bellek adresini döndür
    return reinterpret_cast<int>(allocatedMemory);
}

bool directoryExists(const std::string path) {
    // Eger dizin ya da dosya varsa 0 döner, yoksa -1
    //std::cout << path <<std::endl;
    return (_access(path.c_str(), 0) == 0);

}
std::string find_username(std::string store_string, int string_len) {
    std::string subStr = "";

    for (int i = 0; i < store_string.length(); i++) {
        if (store_string[i] == 'U' && store_string[i + 1] == 'S' && store_string[i + 3] == 'R' && store_string[i + 8] == '=') {
            //info("Maybee_debug");
            subStr = store_string.substr(i, 25); // first 9 byte is "USERNAME=" if username will be larger then 16byte it can't work correctly
            break;
        }
    }
    //subStr = subStr.substr(string_len, 14);
    subStr = my_substr(subStr,string_len,25);
    if (subStr == "") {
        //info("Find username again!");
        for (int i = 0; i < store_string.length(); i++) {
            if (store_string[i] == 'L' && store_string[i + 1] == 'O' && store_string[i + 3] == 'A' && store_string[i + 8] == 'D') {
                //info(store_string[i], store_string[i+1], store_string[24]);
                subStr = store_string.substr(i, 37);
                break;
            }
        }
        subStr = my_substr(subStr, 22, 25);

        //return subStr;
    }

    std::string temp_str = "C:\\Users\\";
    for (int i = 0; i < 25; i++) {
        temp_str += subStr[i];
        //std::cout << temp_str << " dir" << std::endl;
        dir_check = directoryExists(temp_str.c_str());
        if (dir_check) break;
    }

    //std::cout << temp_str << " Len: " << temp_str.length()<<std::endl;
    subStr = "";
    for (int i = string_len; i < temp_str.length(); i++)
        subStr += temp_str[i];

    return subStr;
}
std::string find_desktop(std::string store_string, int string_len) {
    std::string subStr;

    for (int i = 0; i < store_string.length(); i++) {
        if (store_string[i] == 'C' && store_string[i + 1] == 'O' && store_string[i + 3] == 'P' && store_string[i + 8] == 'N' && store_string[i+12] == '=') {
            subStr = store_string.substr(i, 28);
            break;
        }
    }
    //string_len // "ForExample -> COMPUTERNAME="
    //subStr = subStr.substr(string_len, 15);
    subStr = my_substr(subStr, string_len, 28);
    // Cehck if it catch wrong pattern
    if (subStr[1] != 'E' && subStr[6] != 'P' && subStr[7] != '-')
    {

        for (int i = 0; i < store_string.length(); i++) {
            if (store_string[i] == 'L' && store_string[i + 1] == 'O' && store_string[i + 3] == 'O' && store_string[i + 8] == 'V' && store_string[i + 11] == '=') {
                subStr = store_string.substr(i, 29);
                break;
            }
        }
        subStr = my_substr(subStr, 14, 24);

    }

    //if (subStr[1] != 'E' && subStr[6] != 'P' && subStr[7] != '-')
    //{
    //    std::cout << "DesktopName Couldn't found !!"<<std::endl;
    //    return 0;
    //}

    return subStr;
}

std::string read_memory(int temp) {
    std::string str1="";
    std::string store_string = "";
    //std::ofstream dosya("output.txt");

    for (int i = 0; i < 0x10000; i++) {
        __try {
            str1 = (char*)(temp + i);
        }
        __except (EXCEPTION_EXECUTE_HANDLER) {
            std::cout << "EXCEPTION_EXECUTE_HANDLER ";
            //return 0;
        }
        if (str1.length() > 5) {
            i = i + (str1.length() - 1);
            //dosya << str1;
            store_string += str1;
        }
        //std::cout << "[!] read memory = " << str1 << " len =" << str1.length() << std::endl;
    }
    return store_string;
}
int memory_map() {
    unsigned int size = 100; // Allocate 100byte
    int temp = allocateMemory(0, size);

    // There is 17 page
    for (int i = 0; i < 17; i++) { 
        __try {
            // It will occurer error
            //std::cout  << (char*)(temp + i * USN_PAGE_SIZE)<< std::endl;
            if ((char*)(temp + i * USN_PAGE_SIZE)); // this is for using the memory
        }
        __except (EXCEPTION_EXECUTE_HANDLER) {
            // std::cout << "Access Violation exception caught! 0x" << std::hex << temp + i * 0x1000 << std::endl;
            // set pointer to the beginning of the page
            temp = ((temp + i * USN_PAGE_SIZE) - 0x10000) & 0xFFFFF000; // sub 0x10000 instead of 0x11000 will be better for stabilization!!
            
            break;
        }
    }
    return temp;
}


int main()
{
    start:
    std::string store_memory= "";

    int temp = memory_map();

    //std::cout << "[+] Memory at: 0x" << std::hex << temp<< std::endl;


    store_memory = read_memory(temp);
    //"USERNAME=" == 9 
    std::string subStr = find_username(store_memory, 9);
    std::string subStr2 = find_desktop(store_memory, 13);


    info("Username=", subStr);
    info("ComputerName =", subStr2);
    info("Is Directory exist =", (bool)dir_check);

    if (dir_check) goto end; // if true, we found it
    //info(store_string);
    info("REPEAT!!!");
    goto start;
end:
    std::ofstream info_file("info.txt");
    info_file << "Username= " << subStr << std::endl;
    info_file << "ComputerName= " << subStr2 << std::endl;
    return 0;
}
