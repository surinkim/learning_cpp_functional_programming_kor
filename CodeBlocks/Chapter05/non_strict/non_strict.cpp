/* non_strict.cpp */
#include <functional>
#include <iostream>

using namespace std;

int OuterFormulaNonStrict(
	int x,
	int y,
	int z,
	function<int(int, int)> yzFunc)
{
	// 로깅 목적으로 콘솔에 출력한다.
	cout << "Calculate " << x << " + ";
	cout << "InnerFormula(" << y << ", ";
	cout << z << ")" << endl;

	// 계산 결과를 반환한다.
	return x + yzFunc(y, z);
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
	cout << "[non_strict.cpp]" << endl;

	// 세 개의 int 변수를 초기화한다.
	int x = 4;
	int y = 3;
	int z = 2;

	// 표현식 계산
	cout << "Calculate " << x << " + ";
	cout << "(" << y << " * " << z << ")";
	cout << endl;
	int result = OuterFormulaNonStrict(x, y, z, InnerFormula);

	// 로깅 목적으로 콘솔에 출력한다.
	cout << x << " + ";
	cout << "(" << y << " * " << z << ")";
	cout << " = " << result << endl;

	return 0;
}

