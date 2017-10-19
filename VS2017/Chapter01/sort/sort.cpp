// sort.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


/* sort.cpp */
#include <vector>
#include <algorithm>
#include <iostream>

bool comparer(int a, int b)
{
	return (a > b);
}

auto main() -> int
{
	std::cout << "[sort.cpp]" << std::endl;

	// 여러 개의 정수로 벡터 초기화
	std::vector<int> vect = { 20, 43, 11, 78, 5, 96 };

	// 벡터의 각 원소 출력
	std::cout << "Original Data : ";
	for (auto v : vect)
		std::cout << v << " ";
	std::cout << std::endl;

	// Sorting the vector element ascending
	// 오름차 순으로 정렬
	std::sort(std::begin(vect), std::end(vect));

	// 오름차 순으로 정렬된 벡터 출력
	std::cout << "Ascending Sorted : ";
	for (auto v : vect)
		std::cout << v << " ";
	std::cout << std::endl;

	// comparer를 사용하여 내림차 순으로 정렬
	std::sort(std::begin(vect), std::end(vect), comparer);

	// 내림차 순으로 정렬된 벡터 출력
	std::cout << "Descending Sorted: ";
	for (auto v : vect)
		std::cout << v << " ";
	std::cout << std::endl;

	return 0;
}
