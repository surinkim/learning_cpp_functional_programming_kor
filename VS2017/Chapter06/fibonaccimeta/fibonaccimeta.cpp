// fibonaccimeta.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


/* fibonaccimeta.cpp */
#include <iostream>

using namespace std;

// 피보나치 순열을 계산하는 
// 템플릿 정의
template <int number>
struct Fibonacci
{
	enum
	{
		value =
		Fibonacci<number - 1>::value +
		Fibonacci<number - 2>::value
	};
};

// number 매개변수가 1일 때의
// 템플릿 정의
template <>
struct Fibonacci<1>
{
	enum
	{
		value = 1
	};
};

// number 매개변수가 0일 때의
// 템플릿 정의
template <>
struct Fibonacci<0>
{
	enum
	{
		value = 0
	};
};

auto main() -> int
{
	cout << "[fibonaccimeta.cpp]" << endl;

	// 컴파일 타임 상수 출력
	cout << "Getting compile-time constant:";
	cout << endl;
	cout << "Fibonacci(25) = ";
	cout << Fibonacci<25>::value;
	cout << endl;

	return 0;
}

