// impurefunction1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


/* im_pure_function_1.cpp */
#include <iostream>

using namespace std;

// 전역 변수를 초기화한다.
float phi = 3.14f;

// 원의 면적을 계산한다.
// 전역 변수 phi를 참조한다.
float circleArea(float r)
{
	return phi * r * r;
}

auto main() -> int
{
	cout << "[im_pure_function_1.cpp]" << endl;
	
	// 지역 변수 f를 초기화한다.
	float f = 2.5f;

	// f를 인자로 전달하여 circleArea() 함수를
	// 다섯 번 호출한다.
	for (int i = 1; i <= 5; ++i)
	{
		cout << "Invocation " << i << " -> ";
		cout << "Result of circleArea(" << f << ") = ";
		cout << circleArea(f) << endl;
	}

	return 0;
}

