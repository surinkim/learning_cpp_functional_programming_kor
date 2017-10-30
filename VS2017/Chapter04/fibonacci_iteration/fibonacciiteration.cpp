// fibonacciiteration.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


/* fibonacci_iteration.cpp */
#include <iostream>

using namespace std;

// 반복을 사용해서 피보나치 순열을 
// 생성하는 함수 구현
int fibonacci(int n)
{
	if (n == 0)
		return 0;
	int previous = 0;
	int current = 1;
	for (int i = 1; i < n; ++i)
	{
		int next = previous + current;
		previous = current;
		current = next;
	}
	return current;
}

auto main() -> int
{
	cout << "[fibonacci_iteration.cpp]" << endl;

	// fibonacci() 함수를 10번 호출
	for (int i = 0; i < 10; ++i)
	{
		cout << fibonacci(i) << " ";
	}
	cout << endl;

	return 0;
}

