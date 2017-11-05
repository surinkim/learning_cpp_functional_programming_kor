/* condition.cpp */
#include <iostream>

using namespace std;

// 조건식이 TRUE 일 때, 실행되는 함수
void TrueStatement()
{
	cout << "True Statement is run." << endl;
}

// 조건식이 FALSE 일 때, 실행되는 함수
void FalseStatement()
{
	cout << "False Statement is run." << endl;
}

auto main() -> int
{
	cout << "[condition.cpp]" << endl;

	// 조건식 결과에 따라
	// 다음에 실행할 함수를 선택
	if (2 + 3 == 5)
		TrueStatement();
	else
		FalseStatement();

	return 0;
}
