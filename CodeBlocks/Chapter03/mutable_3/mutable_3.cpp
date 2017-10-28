/* mutable_3.cpp */
#include <iostream>
#include "../mutableemployee/mutableemployee.h"

using namespace std;

auto main() -> int
{
	cout << "[mutable_3.cpp]" << endl;

	// 필요한 변수를 초기화한다.
	string first = "Frankie";
	string last = "Kaur";
	double d = 1500.0;

	// MutableEmployee 인스턴스를 생성한다.
	MutableEmployee me(0, first, last, d);

	// 초기값을 출력한다.
	cout << "Content of MutableEmployee instance" << endl;
	cout << "ID : " << me.Id() << endl;
	cout << "Name : " << me.FirstName();
	cout << " " << me.LastName() << endl;
	cout << "Salary : " << me.Salary() << endl << endl;

	// MutableEmployee의 각 멤버 변수를 수정한다.
	me.SetId(1);
	me.SetFirstName("Alexis");
	me.SetLastName("Andrews");
	me.SetSalary(2100.0);

	// 수정된 값을 출력한다.
	cout << "Content of MutableEmployee after mutating" << endl;
	cout << "ID : " << me.Id() << endl;
	cout << "Name : " << me.FirstName();
	cout << " " << me.LastName() << endl;
	cout << "Salary : " << me.Salary() << endl;

	return 0;
}
