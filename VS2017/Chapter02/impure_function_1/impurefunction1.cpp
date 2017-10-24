// impurefunction1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


/* impure_function_1.cpp */
#include <iostream>

using namespace std;

// 전역 변수를 초기화한다.
int currentState = 0;

//전달된 인자 값을 currentState에 더한다.
//(계산 결과에 전역 변수 currentState가 관여한다.)
int increment(int i)
{
	currentState += i;
	return currentState;
}

auto main() -> int
{
	cout << "[impure_function_1.cpp]" << endl;

	// 지역 변수를 초기화한다.
	int fix = 5;

	// fix를 인자로 전달하여 increment() 함수를
	// 다섯 번 호출한다.
	for (int i = 1; i <= 5; ++i)
	{
		cout << "Invocation " << i << " -> ";
		cout << "Result of increment(" << fix << ") = ";
		cout << increment(fix) << endl;
	}

	return 0;
}

