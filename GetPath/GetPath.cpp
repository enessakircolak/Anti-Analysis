#include <iostream>
#include <Windows.h>
#include <string>

int main() {
 

    char buffer[MAX_PATH];
    DWORD length = GetTempPathA(MAX_PATH, buffer);
    if (length == 0 || length > MAX_PATH) {
        //std::cerr << "Error: Could not get temporary folder path." << std::endl;
        //return 1;
    }

    const char* dirName = "ZAYOTEM";
    char path[MAX_PATH];
    snprintf(path, MAX_PATH, "%s%s\\", buffer, dirName);

    if (!CreateDirectoryA(path, NULL)) {
        //std::cerr << "Error: Could not create directory." << std::endl;
        //return 1;
    }

    char sourcePath[MAX_PATH];

    //std::cout << sourcePath <<" NABERRR " << std::endl;

    GetModuleFileNameA(NULL, sourcePath, MAX_PATH);
    //std::cout << sourcePath << " NABERRR " << std::endl;

    char destPath[MAX_PATH];
    snprintf(destPath, MAX_PATH, "%s%s", path, "GetPath.exe");

    if (!CopyFileA(sourcePath, destPath, FALSE)) {
        //std::cerr << "Error: Could not copy file." << std::endl;
        //return 1;
    }
    //    ShellExecuteA(NULL, ("open"), destPath, NULL, NULL, SW_RESTORE);

    if (strcmp(sourcePath, destPath) != 0) {
        ShellExecuteA(NULL, ("open"), destPath, NULL, NULL, SW_RESTORE);

        std::cout << "Ben bir bocegim"<<std::endl;
        std::cout << sourcePath << std::endl;
        std::cout << destPath<< std::endl;

    }
    else {
        std::cout << "zararliyim, uzerim seni" << std::endl;
        system("pause");
    }
    std::cout << "Copied file to: " << destPath << std::endl;

    return 0;
}

