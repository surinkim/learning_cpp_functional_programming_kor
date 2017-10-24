/* pure_function_1.cpp */
#include <iostream>

using namespace std;

float circleArea(float r)
{
	return 3.14 * r * r;
}

auto main() -> int
{
	cout << "[pure_function_1.cpp]" << endl;

	// float 변수 초기화
	float f = 2.5f;

	// f를 인자로 전달하여 circleArea() 함수를
	// 다섯 번 호출한다.
	for (int i = 1; i <= 5; ++i)
	{
		cout << "Invocation " << i << " -> ";
		cout << "Result of circleArea(" << f << ") = ";
		cout << circleArea(f) << endl;
	}
	return 0;
}
