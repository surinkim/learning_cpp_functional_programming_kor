/* switch.cpp */
#include <iostream>

using namespace std;

// int 매개변수의 제곱값을 계산하는 함수
int Square(int a)
{
	return a * a;
}

auto main() -> int
{
	cout << "[switch.cpp]" << endl;

	// 2개의 int 변수를 초기화
	int input = 2;
	int output = 0;

	// input 값에 따라 Square() 함수 호출
	switch (input)
	{
	case 1:
		output = Square(1);
		break;
	case 2:
		output = Square(2);
		break;
	default:
		output = Square(0);
		break;
	}

	// 결과 출력
	cout << "The result is " << output << endl;

	return 0;
}
