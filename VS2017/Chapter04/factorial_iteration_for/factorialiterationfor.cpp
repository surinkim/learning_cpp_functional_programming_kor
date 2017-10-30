// factorialiterationfor.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


/* factorial_iteration_for.cpp */
#include <iostream>

using namespace std;

// for 루프를 사용하는 함수 선언
int factorial(int n)
{
	int result = 1;

	// for 루프를 사용한 반복
	for (int i = 1; i <= n; ++i)
	{
		result *= i;
	}
	return result;
}

auto main() -> int
{
	cout << "[factorial_iteration_for.cpp]" << endl;

	// factorial() 함수를 9번 호출
	for (int i = 1; i < 10; ++i)
	{
		cout << i << "! = " << factorial(i) << endl;
	}
	return 0;
}

