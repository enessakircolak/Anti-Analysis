// ntqueryinfo.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>
#include <Windows.h>
#include <winternl.h>
int main()
{
    typedef NTSTATUS(NTAPI* TNtQueryInformationProcess)(
        IN HANDLE           ProcessHandle,
        IN PROCESSINFOCLASS ProcessInformationClass,
        OUT PVOID           ProcessInformation,
        IN ULONG            ProcessInformationLength,
        OUT PULONG          ReturnLength
        );

    HMODULE hNtdll = LoadLibraryA("ntdll.dll");
    if (hNtdll)
    {
        auto pfnNtQueryInformationProcess = (TNtQueryInformationProcess)GetProcAddress(
            hNtdll, "NtQueryInformationProcess");
	  


        if (pfnNtQueryInformationProcess)
        {
            DWORD dwProcessDebugPort, dwReturned;
            NTSTATUS status = pfnNtQueryInformationProcess(
                GetCurrentProcess(),
                ProcessDebugPort,
                &dwProcessDebugPort,
                sizeof(DWORD),
                &dwReturned);

		//dwProcessDebugPort debugger varsa set edilecek değer

            if (NT_SUCCESS(status) && (-1 == dwProcessDebugPort)) {
                std::cout << "AYOO WASAP BODDYYY ?!?!?!?!?";
                ExitProcess(-1);
            }
        }
    }
    std::cout << "You are my precious <3";
}
