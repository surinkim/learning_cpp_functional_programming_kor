/* prime.cpp */
#include <iostream>
#include <cmath>

using namespace std;

bool PrimeCheck(int i)
{
	// 2를 제외한 모든 짝수는 소수가 아니다.
	if ((i % 2) == 0)
	{
		return i == 2;
	}

	// i의 제곱근을 구한다.
	int sqr = sqrt(i);

	// 9보다 작은 수 중, 소수는 홀수이며,
	// 9이상의 수 중, 소수는 제곱수를 제외한 홀수다.
	for (int t = 3; t <= sqr; t += 2)
	{
		if (i % t == 0)
		{
			return false;
		}
	}

	// 1은 소수가 아니다.
	return i != 1;
}

auto main() -> int
{
	cout << "[delaying.cpp]" << endl;

	// 카운트 변수 초기화
	int n = 0;

	// 100개의 소수 출력
	cout << "List of the first 100 prime numbers:" << endl;
	for (int i = 0; ; ++i)
	{
		if (PrimeCheck(i))
		{
			cout << i << "\t";

			if (++n == 100)
				return 0;
		}
	}

	return 0;
}


