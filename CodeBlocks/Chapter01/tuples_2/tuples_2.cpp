/* tuples_2.cpp */
#include <tuple>
#include <iostream>

using namespace std;

auto main() -> int
{
	cout << "[tuples_2.cpp]" << endl;

	// 두 개의 튜플을 초기화 한다.
	tuple<int, const char*, bool> t1(1, "Robert", true);
	auto t2 = make_tuple(2, "Anna", false);

	int i;
	const char* s;
	bool b;

	// t1에서 값을 추출한다.
	tie(i, s, b) = t1;
	cout << "tie(i, s, b) = t1" << endl;
	cout << "i = " << i << endl;
	cout << "s = " << s << endl;
	cout << "b = " << boolalpha << b << endl;
	cout << endl;

	// t2에서 값을 추출한다.
	tie(ignore, s, ignore) = t2;
	cout << "tie(ignore, s, ignore) = t2" << endl;
	cout << "new i = " << i << endl;
	cout << "new s = " << s << endl;
	cout << "new b = " << boolalpha << b << endl;
	cout << endl;

	return 0;
}
