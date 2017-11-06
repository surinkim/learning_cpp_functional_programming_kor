// singlethread.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


/* singlethread.cpp */
#include <thread>
#include <iostream>

using namespace std;

void threadProc()
{
	cout << "Thread ID: ";
	cout << this_thread::get_id() << endl;
}

auto main() -> int
{
	cout << "[singlethread.cpp]" << endl;
	thread thread1(threadProc);
	thread1.join();

	return 0;
}

