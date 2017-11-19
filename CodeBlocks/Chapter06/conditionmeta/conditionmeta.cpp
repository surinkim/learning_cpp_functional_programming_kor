/* conditionmeta.cpp */
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

// IfElse 기본 템플릿 정의
template<bool predicate>
class IfElse
{
};

// predicate가 true일 때의
// 템플릿 특수화
template<>
class IfElse<true>
{
public:
	static inline void func()
	{
		TrueStatement();
	}
};

// predicate가 false일 때의
// 템플릿 특수화
template<>
class IfElse<false>
{
public:
	static inline void func()
	{
		FalseStatement();
	}
};

auto main() -> int
{
	cout << "[conditionmeta.cpp]" << endl;

	// IfElse 템플릿 사용
	IfElse<(2 + 3 == 5)>::func();

	return 0;
}
