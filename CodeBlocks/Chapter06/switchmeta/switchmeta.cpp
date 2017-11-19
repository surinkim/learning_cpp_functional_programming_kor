/* switchmeta.cpp */
#include <iostream>

using namespace std;

// int 매개변수의 제곱값을 계산하는 함수
int Square(int a)
{
	return a * a;
}

// 기본 템플릿 정의
template<int val>
class SwitchTemplate
{
public:
	static inline int func()
	{
		return Square(0);
	}
};

// val이 1일 때의 템플릿 특수화 정의
template<>
class SwitchTemplate<1>
{
public:
	static inline int func()
	{
		return Square(1);
	}
};

// val이 2일 때의 템플릿 특수화 정의
template<>
class SwitchTemplate<2>
{
public:
	static inline int func()
	{
		return Square(2);
	}
};

auto main() -> int
{
	cout << "[switchmeta.cpp]" << endl;

	// const  변수 i 정의
	const int i = 2;

	// SwitchTemplate 템플릿 사용
	int output = SwitchTemplate<i>::func();

	// 결과 출력
	cout << "The result is " << output << endl;

	return 0;
}
