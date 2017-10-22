// tuples1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


/* tuples_1.cpp */
#include <tuple>
#include <iostream>

using namespace std;

auto main() -> int
{
	cout << "[tuples_1.cpp]" << endl;
	
	// 두 개의 튜플을 초기화 한다.
	tuple<int, const char*, bool> t1(1, "Robert", true);
	auto t2 = make_tuple(2, "Anna", false);
	
	// t1의 각 원소를 출력한다.
	cout << "t1 elements:" << endl;
	cout << get<0>(t1) << endl;
	cout << get<1>(t1) << endl;
	cout << (get<2>(t1) == true ? "Male" : "Female") << endl;
	cout << endl;
	
	// t2의 각 원소를 출력한다.
	cout << "t2 elements:" << endl;
	cout << get<0>(t2) << endl;
	cout << get<1>(t2) << endl;
	cout << (get<2>(t2) == true ? "Male" : "Female") << endl;
	cout << endl;

	return 0;
}
