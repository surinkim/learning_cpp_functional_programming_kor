/* array.cpp */
#include <array>
#include <iostream>

auto main() -> int
{
	std::cout << "[array.cpp]" << std::endl;

	// 10개의 정수로 배열 초기화
	std::array<int, 10> arr = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	// 배열의 각 요소를 출력한다.
	std::cout << "Original Data : ";
	for (auto a : arr) std::cout << a << " ";
	std::cout << std::endl;

	// 배열의 첫 번째와 세 번째 요소에 새로운 값을 설정한다.
	arr[1] = 9;
	arr[3] = 7;

	// 수정된 배열의 요소를 출력한다.
	std::cout << "Manipulated Data: ";
	for (auto a : arr) std::cout << a << " ";
	std::cout << std::endl;

	return 0;
}
