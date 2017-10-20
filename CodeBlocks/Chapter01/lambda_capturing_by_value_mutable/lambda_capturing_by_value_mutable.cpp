/* lambda_capturing_by_value_mutable.cpp */
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

auto main() -> int
{
	cout << "[lambda_capturing_by_value_mutable.cpp]" << endl;

	// 몇 개의 정수로 벡터를 초기화한다.
	vector<int> vect;
	for (int i = 0; i < 10; ++i)
		vect.push_back(i);

	// 벡터의 각 요소를 출력한다.
	cout << "Original Data:" << endl;
	for_each(
		begin(vect),
		end(vect),
		[](int n) {
		cout << n << " ";
	});
	cout << endl;

	// 두 개의 변수를 초기화한다.
	int a = 1;
	int b = 1;

	// 두 변수를 캡처하지만,
	// mutable 키워드 때문에 실제로 수정되지 않는다.
	for_each(
		begin(vect),
		end(vect),
		[=](int& x) mutable {
		const int old = x;
		x *= 2;
		a = b;
		b = old;
	});

	// 벡터의 각 원소를 출력한다.
	cout << "Squared Data:" << endl;
	for_each(
		begin(vect),
		end(vect),
		[](int n) {
		cout << n << " ";
	});
	cout << endl << endl;

	// a와 b의 값을 출력한다.
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	return 0;
}
