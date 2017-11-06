// lambdathread.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


/* lambdathread.cpp */
#include <thread>
#include <iostream>

using namespace std;

auto main() -> int
{
	cout << "[lambdathread.cpp]" << endl;
	
	thread threads[5];
	
	for (int i = 0; i < 5; ++i)
	{
		threads[i] = thread([]()
		{
			cout << "Thread ID: ";
			cout << this_thread::get_id() << endl;
		});
	}
	
	for (auto& thread : threads)
	{
		thread.join();
	}
	
	return 0;
}

