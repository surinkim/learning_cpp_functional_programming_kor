// notsync.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


/* notsync.cpp */
#include <thread>
#include <iostream>

using namespace std;

auto main() -> int
{
	cout << "[notsync.cpp]" << endl;
	
	int counter = 0;
	
	thread threads[5];
	
	for (int i = 0; i < 5; ++i)
	{
		threads[i] = thread([&counter]()
		{
			for (int i = 0; i < 10000; ++i)
			{
				++counter;
				cout << "Thread ID: ";
				cout << this_thread::get_id();
				cout << "\tCurrent Counter = ";
				cout << counter << endl;
			}
		});
	}
	
	for (auto& thread : threads)
	{
		thread.join();
	}
	
	cout << "Final result = " << counter << endl;
	
	return 0;
}

