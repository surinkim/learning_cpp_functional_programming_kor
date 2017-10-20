// lambdacapturingbyvalue.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


/* lambda_capturing_by_value.cpp */
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

auto main() -> int
{
	cout << "[lambda_capturing_by_value.cpp]" << endl;

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
	int a = 2;
	int b = 8;

	// 명시적으로 두 변수를 캡처한다.
	cout << "Printing elements between " << a;
	cout << " and " << b << " explicitly [a,b]:" << endl;
	for_each(
		begin(vect),
		end(vect),
		[a, b](int n) {
		if (n >= a && n <= b)
			cout << n << " ";
	});
	cout << endl;

	// a와 b의 값을 수정한다.
	a = 3;
	b = 7;

	// 암시적으로 두 변수를 캡처한다.
	cout << "printing elements between " << a;
	cout << " and " << b << " implicitly[=]:" << endl;
	for_each(
		begin(vect),
		end(vect),
		[=](int n) {
		if (n >= a && n <= b)
			cout << n << " ";
	});
	cout << endl;

	return 0;
}
