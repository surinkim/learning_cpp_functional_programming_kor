/* threaduniquehandle.cpp */
#include <iostream>
#include <windows.h>
#include "../uniquehandle_h/uniquehandle.h"

using namespace std;

unsigned long threadProc(void*)
{
	cout << "threadProc() is run." << endl;
	return 100;
}

struct WinException
{
	unsigned long error;
	explicit WinException(
		unsigned long value = GetLastError()) :
		error{ value }
	{
	}
};

auto WaitOneThread(
	HANDLE const h,
	DWORD const ms = INFINITE) -> bool
{
	auto const r = WaitForSingleObject(
		h,
		ms);

	// 핸들 h가 시그널 상태
	if (r == WAIT_OBJECT_0)
		return true;

	// 핸들 h가 지정한 시간까지 시그널 상태가 되지 않았음.
	if (r == WAIT_TIMEOUT)
		return false;

	throw WinException();
}

auto main() -> int
{
	cout << "[threaduniquehandle.cpp]" << endl;
	auto hnd = NullHandle
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
		if (WaitOneThread(hnd.Get(), 0))
			cout << "Before running thread" << endl;

		WaitOneThread(hnd.Get());
		if (WaitOneThread(hnd.Get(), 0))
			cout << "After running thread" << endl;

		unsigned long exitCode;
		GetExitCodeThread(hnd.Get(), &exitCode);

		cout << "The result = " << exitCode << endl;
	}

	return 0;
}

