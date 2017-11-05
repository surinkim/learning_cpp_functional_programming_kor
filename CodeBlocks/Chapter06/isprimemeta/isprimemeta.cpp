// isprimemeta.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


/* isprimemeta.cpp */
#include <iostream>

using namespace std;

// 전달된 인수가 소수인지 아닌지 판단하는 템플릿 정의
template <
	int lastNumber,
	int secondLastNumber>
	class IsPrime
{
public:
	enum
	{
		primeNumber = (
			(lastNumber % secondLastNumber) &&
			IsPrime<lastNumber, secondLastNumber - 1>
				::primeNumber)
	};
};

// number 매개변수에 전달된 숫자가 소수인지 아닌지
// 확인하는 템플릿 정의
template <int number>
class IsPrime<number, 1>
{
public:
	enum
	{
		primeNumber = 1
	};
};

// 전달된 인수가 소수이면 콘솔에 출력하는 템플릿 정의
template <int number>
class PrimeNumberPrinter
{
public:
	PrimeNumberPrinter<number - 1> printer;

	enum
	{
		primeNumber = IsPrime<number, number - 1>
			::primeNumber
	};

	void func()
	{
		printer.func();

		if (primeNumber)
		{
			cout << number << "\t";
		}
	}
};

// 매개변수에 대한 인수로 1을 전달했을 때
// 무시하기 위한 템플릿 정의
template<>
class PrimeNumberPrinter<1>
{
public:
	enum
	{
		primeNumber = 0
	};

	void func()
	{
	}
};

int main()
{
	cout << "[isprimemeta.cpp]" << endl;

	// 1과 500 사이의 소수 출력
	cout << "Filtering the numbers between 1 and 500 ";
	cout << "for of the prime numbers:" << endl;

	// PrimeNumberPrinter 템플릿 사용
	PrimeNumberPrinter<500> printer;

	// 템플릿의 func() 함수 호출
	printer.func();
	cout << endl;

	return 0;
}


