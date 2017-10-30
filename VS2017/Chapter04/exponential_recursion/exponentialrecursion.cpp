// exponentialrecursion.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


/* exponential_recursion.cpp */
#include <iostream>

using namespace std;

// 재귀를 사용해서 제곱 값을 계산한다.
int power(int base, int exp)
{
	if (exp == 0)
		return 1;
	else
		return base * power(base, exp - 1);
}

auto main() -> int
{
	cout << "[exponential_recursion.cpp]" << endl;

	// power() 함수를 여섯 번 호출한다.
	for (int i = 0; i <= 5; ++i)
	{
		cout << "power (2, " << i << ") = ";
		cout << power(2, i) << endl;
	}

	return 0;
}

