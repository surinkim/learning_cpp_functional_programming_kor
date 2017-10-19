// vector.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


/* vector.cpp */
#include <vector>
#include <iostream>

auto main() -> int
{
	std::cout << "[vector.cpp]" << std::endl;

	// 3개의 정수로 vector 초기화
	std::vector<int> vect = { 0, 1, 2 };

	// vector의 각 요소를 출력한다.
	std::cout << "Original Data : ";
	for (auto v : vect) std::cout << v << " ";
	std::cout << std::endl;

	// 2개의 데이터를 추가한다.
	vect.push_back(3);
	vect.push_back(4);

	// 수정된 vector의 각 요소를 출력한다.
	std::cout << "New Data Added : ";
	for (auto v : vect) std::cout << v << " ";
	std::cout << std::endl;

	// vector의 두 번째와 네 번째 요소의 값을 수정한다.
	vect.at(2) = 5;
	vect.at(4) = 6;

	// 수정된 vector의 각 요소를 출력한다.
	std::cout << "Manipulate Data: ";
	for (auto v : vect) std::cout << v << " ";
	std::cout << std::endl;

	return 0;
}
