// array.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

/* array.cpp */
#include <array>
#include <iostream>

auto main() -> int
{
	std::cout << "[array.cpp]" << std::endl;
	
	// 10개의 정수로 배열 초기화
	std::array<int, 10> arr = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	
	// 배열의 각 원소를 출력한다.
	std::cout << "Original Data : ";
	for (auto a : arr) std::cout << a << " ";
	std::cout << std::endl;
	
	// Modifying the content of
	// the 1st and 3rd element of the array
	// 배열의 첫 번째와 세 번째 원소에 새로운 값을 설정한다.
	arr[1] = 9;
	arr[3] = 7;
	
	// 수정된 배열의 원소를 출력한다.
	std::cout << "Manipulated Data: ";
	for (auto a : arr) std::cout << a << " ";
	std::cout << std::endl;
	
	return 0;
}
