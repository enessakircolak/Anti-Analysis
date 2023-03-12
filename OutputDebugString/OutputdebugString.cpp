#include <stdio.h>
#include <Windows.h>
#include <iostream>

int main()
{
	system("pause");
	SetLastError(0);
	OutputDebugStringA((LPCSTR)"SA");
	if (GetLastError() != 0)
		printf("Debugger detected!!\n");

	std::cout << GetLastError();
	system("pause");
	return 0;
}