// factorialrecursiontail.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


/* factorial_recursion_tail.cpp */
#include <iostream>

using namespace std;

// 꼬리 재귀로 팩토리얼을 계산하는 함수, factorialTail() 구현
int factorialTail(int n, int i)
{
	if (n == 0)
		return i;
	
	return factorialTail(n - 1, n * i);
}

// 꼬리 재귀 함수, factorialTail()을 호출하는 factorial() 구현
int factorial(int n)
{
	return factorialTail(n, 1);
}

auto main() -> int
{
	cout << "[factorial_recursion_tail.cpp]" << endl;

	// factorial() 함수를 10회 호출.
	for (int i = 1; i < 10; ++i)
	{
		cout << i << "! = " << factorial(i) << endl;
	}

	return 0;
}

