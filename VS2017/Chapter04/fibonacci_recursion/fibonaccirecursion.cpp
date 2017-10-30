// fibonaccirecursion.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


/* fibonacci_recursion.cpp */
#include <iostream>

using namespace std;

// 재귀를 사용해서 피보나치 순열을 
// 생성하는 함수 구현
int fibonacci(int n)
{
	if (n <= 1)
		return n;
	return fibonacci(n - 1) + fibonacci(n - 2);
}

auto main() -> int
{
	cout << "[fibonacci_recursion.cpp]" << endl;

	// fibonacci() 함수를 10번 호출
	for (int i = 0; i < 10; ++i)
	{
		cout << fibonacci(i) << " ";
	}
	cout << endl;
	
	return 0;
}

