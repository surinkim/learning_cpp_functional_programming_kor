/* immutable_2.cpp */
#include <iostream>

using namespace std;

void Modify(string name)
{
	name = "Alexis Andrews";
}

auto main() -> int
{
	cout << "[immutable_2.cpp]" << endl;

	// string 변수를 초기화한다.
	string n = "Frankie Kaur";
	cout << "Initial name = " << n;
	cout << endl;

	// n을 수정하기 위해서 Modify() 함수를 호출한다.
	// 하지만, Modify() 함수는 string 값(value)을 인수로 받으므로
	// 함수 호출 후에도 n 값은 변하지 않는다.
	Modify(n);

	// n을 출력한다.
	cout << "After manipulating = " << n;
	cout << endl;

	return 0;
}


