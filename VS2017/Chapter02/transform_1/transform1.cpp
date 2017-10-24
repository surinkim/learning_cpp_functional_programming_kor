// transform1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


/* transform_1.cpp */
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

auto main() -> int
{
	cout << "[transform_1.cpp]" << endl;

	// 몇 개의 정수를 벡터에 추가한다.
	vector<int> v1;
	for (int i = 0; i < 5; ++i)
		v1.push_back(i);

	// 또 다른 벡터 v2를 생성한다.
	vector<int> v2;

	// v2의 크기를 v1과 동일하게 조정한다.
	v2.resize(v1.size());

	// 벡터 안의 각 원소를 변경한다.
	transform(
		begin(v1),
		end(v1),
		begin(v2),
		[](int i) {
		return i * i; });

	// 벡터 v1을 출력한다.
	std::cout << "v1 contains:";
	for (auto v : v1)
		std::cout << " " << v;
	std::cout << endl;

	// 벡터 v2를 출력한다.
	std::cout << "v2 contains:";
	for (auto v : v2)
		std::cout << " " << v;
	std::cout << endl;

	return 0;
}

