#include <iostream>
#include <Windows.h>

DWORD WINAPI ThreadFunction(LPVOID pParam)
{
	std::cout << "TreadFunction() - Begin" << std::endl;
	std::cout << (const char*)pParam << std::endl;
	std::cout << "ThreadFunction() - End" << std::endl;
	return 0;
}

int main()
{
	std::cout << "main() - Begin" << std::endl;
	DWORD dwThreadId = 0;
	HANDLE hThread = ::CreateThread(
		NULL,
		0,
		ThreadFunction,
		(LPVOID)"PARAM",
		0,
		&dwThreadId);

	if (hThread == NULL) {

	}

	::WaitForSingleObject(hThread, INFINITE);
	::CloseHandle(hThread);

	std::cout << "main() - End" << std::endl;
	return 0;
}