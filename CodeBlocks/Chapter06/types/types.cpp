/* types.cpp */
#include <iostream>

using namespace std;

// 템플릿에 데이터 타입 정의
template<typename T>
struct datatype
{
	using type = T;
};

auto main() -> int
{
	cout << "[types.cpp]" << endl;

	// 컴파일 타임에 데이터 타입을 선택한다.
	using t = typename datatype<int>::type;

	// 선택한 데이터 타입을 사용한다.
	t myVar = 123;

	// 선택한 데이터 타입을 출력한다.
	cout << "myVar = " << myVar;

	return 0;
}
