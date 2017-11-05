/* selectingtype.cpp */
#include <iostream>

using namespace std;

// IfElseDataType 템플릿 정의
template<
	bool predicate,
	typename TrueType,
	typename FalseType>
	struct IfElseDataType
{
};

// predicate 매개변수에 전달된 값이 TRUE 일 때,
// 필요한 템플릿 정의
template<
	typename TrueType,
	typename FalseType>
	struct IfElseDataType<
	true,
	TrueType,
	FalseType>
{
	typedef TrueType type;
};

// predicate 매개변수에 전달된 값이 FALSE 일 때,
// 필요한 템플릿 정의
template<
	typename TrueType,
	typename FalseType>
	struct IfElseDataType<
	false,
	TrueType,
	FalseType>
{
	typedef FalseType type;
};

auto main() -> int
{
	cout << "[selectingtype.cpp]" << endl;

	// SHRT_MAX는 32767로 define 되어 있기 때문에
	// 'SHRT_MAX == 2147483647' 표현식은 FALSE 다.
	// 따라서, IfElseDataType 템플릿에 의해 myVar는 int 타입이 된다.
	IfElseDataType<
		SHRT_MAX == 2147483647,
		short,
		int>::type myVar;

	// myVar에 int 타입의 최대값 2147483647을 대입한다.
	myVar = 2147483647;

	// myVar의 데이터 타입을 출력한다.
	cout << "myVar has type ";
	cout << typeid(myVar).name() << endl;

	return 0;
}
