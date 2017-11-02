/* delaying_non_pure.cpp */
#include <iostream>
#include <functional>

using namespace std;

template<class T> class Delay
{
private:
	function<T()> m_func;

public:
	Delay(function<T()> func) : m_func(func)
	{
	}

	T Fetch()
	{
		return m_func();
	}
};

auto main() -> int
{
	cout << "[delaying_non_pure.cpp]" << endl;

	// int 변수 a, b, multiplexer 초기화
	int a = 10;
	int b = 5;
	int multiplexer = 0;

	// multiply_impure 생성
	Delay<int> multiply_impure([&]()
	{
		return multiplexer * a * b;
	});

	// multiply_impure 인스턴스의 Fetch()를 여러 번 호출
	for (int i = 0; i < 5; ++i)
	{
		++multiplexer;
		cout << "Multiplexer = " << multiplexer << endl;
		cout << "a * b = " << multiply_impure.Fetch();
		cout << endl;
	}

	return 0;
}
