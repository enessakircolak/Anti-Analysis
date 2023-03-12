#include <stdio.h>

#include <iostream>
#include <windows.h>
#pragma comment(lib, "ntdll.lib")
#pragma section(".CRT$XLB", read) 
//Bu bölüm, programın çalıştırılması sırasında otomatik olarak yürütülecek
//olan önceden tanımlanmış işlevleri içerir.dir.
#define NtCurrentProcess() (HANDLE)-1
extern "C" NTSTATUS NTAPI NtQueryInformationProcess(HANDLE hProcess, ULONG InfoClass, PVOID Buffer, ULONG Length, PULONG ReturnLength);
#ifdef _WIN64
#else
#define readpeb (PBOOLEAN)__readfsdword(0x30) + 2 //x32 için
#endif



static int a = 0;

void NTAPI tls_callback(void* DllHandle, DWORD Reason, void* Reserved)
{
    PBOOLEAN BeingDebugged = readpeb;
    HANDLE DebugPort = NULL;
    //COD alıntıları debugger içindeyse gözükecek
    if (*BeingDebugged) {
        printf("This is for Soap\n");
    }
    else {
        printf("Accident is the first building block of evolution.\n");
    }
    if (!NtQueryInformationProcess(NtCurrentProcess(), 7, &DebugPort, sizeof(HANDLE), NULL)) {
        //DebugPort 0 değilse programın debug edildiğinin göstergesidir.
        if (DebugPort) {
            printf("This is it. Makarov doesn't leave here alive\n");  
            exit(1);
        }
        else {
            printf("Newton’s third law. You gotta leave something behind.\n");
        }
    }
}


#pragma comment (linker, "/INCLUDE:__tls_used")
#pragma comment (linker, "/INCLUDE:__xl_b")

#pragma data_seg(".CRT$XLB")
EXTERN_C PIMAGE_TLS_CALLBACK _xl_b = tls_callback;
#pragma data_seg()

//program debuggerda çalışırsa maine gelmeden önce kapanmış olacak
int main() {
    printf("%d\n", a);
    return 0;
}