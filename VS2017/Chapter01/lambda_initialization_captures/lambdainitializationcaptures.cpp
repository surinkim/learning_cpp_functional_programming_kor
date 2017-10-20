// lambdainitializationcaptures.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


/* lambda_initialization_captures.cpp */
#include <iostream>

using namespace std;

auto main() -> int
{
	cout << "[lambda_initialization_captures.cpp]" << endl;

	// 변수 초기화
	int a = 5;
	cout << "Initial a = " << a << endl;

	// a를 사용해서 람다에서 사용하는 변수 x의 값을 초기화 한다.
	auto myLambda = [&x = a]() { x += 2; };

	// 람다를 실행한다.
	myLambda();

	// 변수 값을 출력한다.
	cout << "New a = " << a << endl;

	return 0;
}
