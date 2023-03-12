// HardwareBP.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//
#include <windows.h>
#include <stdio.h>

int main() {

    HANDLE thread = GetCurrentThread();
    CONTEXT threadContext;
    int errorCode;

    memset(&threadContext, 0, sizeof(CONTEXT));
    threadContext.ContextFlags = CONTEXT_ALL;

    if (!GetThreadContext(thread, &threadContext)) {
        errorCode = GetLastError();
        puts("Could not get thread context");
        return errorCode;
    }

    if (threadContext.Dr0 || threadContext.Dr1 || threadContext.Dr2 || threadContext.Dr3) { // programın debug registerlarını kontrol ediyor
        puts("Detected");
    }
    else {
        puts("Undetected");
    }

    return 0;
}
