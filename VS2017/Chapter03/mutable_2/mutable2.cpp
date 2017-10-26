// mutable2.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


/* mutable_2.cpp */
#include <iostream>

using namespace std;

void Modify(string &name)
{
	name = "Alexis Andrews";
}

auto main() -> int
{
	cout << "[mutable_2.cpp]" << endl;

	// string 변수를 초기화한다.
	string n = "Frankie Kaur";
	cout << "Initial name = " << n.c_str();
	cout << endl;

	// n을 수정하기 위해서 Modify() 함수를 호출한다.
	// Modify() 함수는 string의 참조(reference)를 인자로 받으므로
	// 함수 호출 후에 n 값이 변한다.
	Modify(n);

	// n을 출력한다.
	cout << "After manipulating = " << n.c_str();
	cout << endl;

	return 0;
}

