// loopmeta.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


/* loopmeta.cpp */
#include <iostream>

using namespace std;

// 매개변수를 출력하는 함수
void PrintNumber(int i)
{
	cout << i << "\t";
}

// limit 매개변수에 전달된 값을 출력하는 템플릿 정의.
// limit이 0보다 클 때만 동작한다.
template<int limit>
class DoWhile
{
private:
	enum
	{
		run = (limit - 1) != 0
	};

public:
	static inline void func()
	{
		PrintNumber(limit);
		DoWhile<run == true ? (limit - 1) : 0>
			::func();
	}
};

// limit이 0이 되면 아무 처리도 하지 않는다. 
template<>
class DoWhile<0>
{
public:
	static inline void func()
	{
	}
};

auto main() -> int
{
	cout << "[loopmeta.cpp]" << endl;

	// int 변수 초기화
	const int i = 100;

	// DoWhile 템플릿으로 
	// i 변수보다 작고 0 보다 큰 수를 출력한다.
	cout << "List of numbers between 100 and 1";
	cout << endl;
	DoWhile<i>::func();
	cout << endl;

	return 0;
}

