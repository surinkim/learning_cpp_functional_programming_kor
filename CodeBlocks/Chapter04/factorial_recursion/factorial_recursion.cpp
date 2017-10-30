/* factorial_recursion.cpp */
#include <iostream>

using namespace std;

// 재귀를 사용하는 함수 선언
int factorial(int n)
{
	if (n == 0)
		return 1;
	else
		return n * factorial(n - 1);
}

auto main() -> int
{
	cout << "[factorial_recursion.cpp]" << endl;
	for (int i = 1; i < 10; ++i)
	{
		cout << i << "! = " << factorial(i) << endl;
	}
	return 0;
}
