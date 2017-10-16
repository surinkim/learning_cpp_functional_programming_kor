// auto.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

/* auto.cpp */
#include <iostream>
#include <typeinfo>

auto main() -> int
{
	std::cout << "[auto.cpp]" << std::endl;

	// 여러 개의 auto 타입 변수를 생성한다.
	auto a = 1;
	auto b = 1.0;
	auto c = a + b;
	auto d = { b, c };

	// 변수의 실제 타입을 출력한다.
	std::cout << "type of a: " << typeid(a).name() << std::endl;
	std::cout << "type of b: " << typeid(b).name() << std::endl;
	std::cout << "type of c: " << typeid(c).name() << std::endl;
	std::cout << "type of d: " << typeid(d).name() << std::endl;
	return 0;
}

