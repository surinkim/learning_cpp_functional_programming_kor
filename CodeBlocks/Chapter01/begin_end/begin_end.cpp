/* begin_end.cpp */
#include <iostream>

auto main() -> int
{
	std::cout << "[begin_end.cpp]" << std::endl;

	// 배열 선언
	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	// 보통의 for 루프를 사용해서
	// 배열 내의 요소를 출력한다.
	std::cout << "Displaying array element using conventional for-loop";
	std::cout << std::endl;
	for (unsigned int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;

	// 비멤버 begin(), end() 함수를 사용해서
	// 배열 내의 요소를 출력한다.
	std::cout << "Displaying array element using non-member begin() and end()";
	std::cout << std::endl;
	for (auto i = std::begin(arr); i != std::end(arr); ++i)사
		std::cout << *i << " ";
	std::cout << std::endl;

	return 0;
}
