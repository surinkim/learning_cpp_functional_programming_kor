// mutable1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


/* mutable_1.cpp */
#include <iostream>

using namespace std;

auto main() -> int
{
	cout << "[mutable_1.cpp]" << endl;

	// int 변수 초기화
	int mutableVar = 100;
	cout << "Initial mutableVar = " << mutableVar;
	cout << endl;

	// mutableVar 변경
	for (int i = 0; i <= 10; ++i)
		mutableVar = mutableVar + i;

	// mutableVar 출력
	cout << "After manipulating mutableVar = " << mutableVar;
	cout << endl;

	return 0;
}

