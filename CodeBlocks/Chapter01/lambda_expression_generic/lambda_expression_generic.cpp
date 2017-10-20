/* lambda_expression_generic.cpp */
#include <iostream>

using namespace std;

auto main() -> int
{
	cout << "[lambda_expression_generic.cpp]" << endl;

	// 람다 표현식을 만든다.
	auto findMax = [](auto &x, auto &y) {
		return x > y ? x : y; };

	// 여러 개의 변수를 초기화한다.
	int i1 = 5, i2 = 3;
	float f1 = 2.5f, f2 = 2.05f;

	// int 타입으로 제네릭 람다 표현식을 사용한다.
	cout << "i1 = 5, i2 = 3" << endl;
	cout << "Max: " << findMax(i1, i2) << endl << endl;

	// double 타입으로 제네릭 람다 표현식을 사용한다.
	cout << "f1 = 2.5f, f2 = 2.05f" << endl;
	cout << "Max: " << findMax(f1, f2) << endl << endl;

	return 0;
}
