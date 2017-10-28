// immutable3.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


/* immutable_3.cpp */
#include <iostream>
#include "../immutableemployee/immutableemployee.h"

using namespace std;

auto main() -> int
{
	cout << "[immutable_3.cpp]" << endl;

	// 필요한 변수를 초기화한다.
	string first = "Frankie";
	string last = "Kaur";
	double d = 1500.0;

	// ImmutableEmployee 인스턴스를 생성한다.
	ImmutableEmployee me(0, first, last, d);

	// 초기값을 출력한다.
	cout << "Content of ImmutableEmployee instance" << endl;
	cout << "ID : " << me.Id() << endl;
	cout << "Name : " << me.FirstName()
		<< " " << me.LastName() << endl;
	cout << "Salary : " << me.Salary() << endl << endl;

	// 초기값을 수정한다.
	ImmutableEmployee me2 = me.SetId(1);
	ImmutableEmployee me3 = me2.SetFirstName("Alexis");
	ImmutableEmployee me4 = me3.SetLastName("Andrews");
	ImmutableEmployee me5 = me4.SetSalary(2100.0);

	// 새로운 값을 출력한다.
	cout << "Content of ImmutableEmployee after modifying" << endl;
	cout << "ID : " << me5.Id() << endl;
	cout << "Name : " << me5.FirstName()
		<< " " << me5.LastName() << endl;
	cout << "Salary : " << me5.Salary() << endl;

	return 0;
}

