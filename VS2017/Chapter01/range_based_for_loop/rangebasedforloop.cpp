// rangebasedforloop.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

/* range_based_for_loop.cpp */
#include <iostream>

auto main() -> int
{
	std::cout << "[range_based_for_loop.cpp]" << std::endl;
	
	// 배열을 선언한다.
	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	
	// 비-멤버 begin(), end() 함수를 사용해서 
	// 배열 내의 원소를 출력한다.
	std::cout << "Displaying array element using range-based for loop";
	std::cout << std::endl;
	for (auto a : arr) std::cout << a << " ";
	std::cout << std::endl;

	return 0;
}
