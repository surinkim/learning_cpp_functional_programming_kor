// strict.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


/* strict.cpp */
#include <iostream>

using namespace std;

int OuterFormula(int x, int yz)
{
	// 로깅 목적으로 콘솔에 출력한다.
	cout << "Calculate " << x << " + ";
	cout << "InnerFormula(" << yz << ")";
	cout << endl;

	// 계산 결과를 반환한다.
	return x + yz;
}

int InnerFormula(int y, int z)
{
	// 로깅 목적으로 콘솔에 출력한다.
	cout << "Calculate " << y << " * ";
	cout << z << endl;

	// 계산 결과를 반환한다.
	return y * z;
}

auto main() -> int
{
	cout << "[strict.cpp]" << endl;

	// 세 개의 int 변수를 초기화한다.
	int x = 4;
	int y = 3;
	int z = 2;

	// 표현식 계산
	cout << "Calculate " << x << " + ";
	cout << "(" << y << " * " << z << ")";
	cout << endl;
	int result = OuterFormula(x, InnerFormula(y, z));

	// 로깅 목적으로 콘솔에 출력한다.
	cout << x << " + ";
	cout << "(" << y << " * " << z << ")";
	cout << " = " << result << endl;

	return 0;
}

