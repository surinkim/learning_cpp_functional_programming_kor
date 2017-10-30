// tailrecursion.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


/* tail_recursion.cpp */
#include <iostream>

using namespace std;

void displayNumber(long long n)
{
	// 현재 n 값을 출력한다.
	cout << n << endl;

	// 함수 마지막에서 재귀 호출을 수행한다.
	displayNumber(n + 1);
}

auto main() -> int
{
	cout << "[tail_recursion.cpp]" << endl;

	// 꼬리 재귀를 사용하는 displayNumber() 함수를 호출한다.
	displayNumber(0);
	return 0;
}

