// threadhandle.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


/* threadhandle.cpp */
#include <iostream>
#include <windows.h>

using namespace std;

auto threadProc(void*) -> unsigned long
{
	cout << "threadProc() is run." << endl;
	return 100;
}

auto main() -> int
{
	cout << "[threadhandle.cpp]" << endl;

	auto hnd = HANDLE
	{
		CreateThread(
			nullptr,
			0,
			threadProc,
			nullptr,
			0,
			nullptr)
	};

	if (hnd)
	{
		WaitForSingleObject(hnd, INFINITE);

		unsigned long exitCode;
		GetExitCodeThread(hnd, &exitCode);

		cout << "The result = " << exitCode << endl;

		CloseHandle(hnd);
	}

	return 0;
}

