// decltype.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


/* decltype.cpp */
#include <iostream>

// 템플릿 함수를 생성한다.
template<typename I, typename J>
auto add(I i, J j) -> decltype(i + j)
{
	return i + j;
}

auto main() -> int
{
	std::cout << "[decltype.cpp]" << std::endl;

	// 템플릿 함수를 호출한다.
	auto d = add<int, double>(2, 2.5);

	// 결과를 출력한다.
	std::cout << "result of 2 + 2.5: " << d << std::endl;

	return 0;
}

