// loop.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


/* loop.cpp */
#include <iostream>

using namespace std;

// 매개변수를 출력하는 함수
void PrintNumber(int i)
{
	cout << i << "\t";
}

auto main() -> int
{
	cout << "[loop.cpp]" << endl;

	// int 변수 초기화
	int i = 100;

	// i 변수보다 작고 0 보다 큰 수를 루프를 돌면서 출력한다.
	cout << "List of numbers between 100 and 1";
	cout << endl;
	do
	{
		PrintNumber(i);
	} while (--i > 0);
	cout << endl;

	return 0;
}

