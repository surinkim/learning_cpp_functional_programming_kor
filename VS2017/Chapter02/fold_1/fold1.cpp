// fold1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


/* fold_1.cpp */
#include <vector>
#include <numeric>
#include <functional>
#include <iostream>

using namespace std;

auto main() -> int
{
	cout << "[fold_1.cpp]" << endl;

	// 몇 개의 정수를 벡터에 추가한다.
	vector<int> numbers = { 0, 1, 2, 3, 4 };

	// 벡터의 각 원소의 합을 
	// 왼쪽부터, foldl 타입으로 계산한다.
	auto foldl = accumulate(
		begin(numbers),
		end(numbers),
		0,
		std::plus<int>());

	// 벡터의 각 원소의 합을 
	// 오른쪽부터, foldr 타입으로 계산한다.
	auto foldr = accumulate(
		rbegin(numbers),
		rend(numbers),
		0,
		std::plus<int>());

	// 계산 결과를 출력한다.
	cout << "foldl result = " << foldl << endl;
	cout << "foldr result = " << foldr << endl;

	return 0;
}

