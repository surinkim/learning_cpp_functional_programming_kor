/* factorial_iteration_do_while.cpp */
#include <iostream>
using namespace std;

// do-while 루프를 사용하는 함수 선언
int factorial(int n)
{
	int result = 1;
	int i = 1;

	// do-while 루프를 사용한 반복
	do
	{
		result *= i;
	} while (++i <= n);

	return result;
}
auto main() -> int
{
	cout << "[factorial_iteration_do_while.cpp]" << endl;

	// factorial() 함수를 9번 호출
	for (int i = 1; i < 10; ++i)
	{
		cout << i << "! = " << factorial(i) << endl;
	}

	return 0;
}
