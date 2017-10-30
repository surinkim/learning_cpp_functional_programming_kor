/* exponential_iteration.cpp */
#include <iostream>

using namespace std;

// 반복을 사용해서 제곱 값을 계산한다.
int power(int base, int exp)
{
	int result = 1;
	for (int i = 0; i < exp; ++i)
	{
		result *= base;
	}
	return(result);
}

auto main() -> int
{
	cout << "[exponential_iteration.cpp]" << endl;

	// power() 함수를 여섯 번 호출한다.
	for (int i = 0; i <= 5; ++i)
	{
		cout << "power (2, " << i << ") = ";
		cout << power(2, i) << endl;
	}

	return 0;
}
