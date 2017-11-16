/* first_class_pure_immutable.cpp */
#include <iostream>
#include <functional>

using namespace std;

// MyValue 클래스 구현
class MyValue
{
public:
	const int value;
	MyValue(int v) : value(v)
	{
	}
};

// 네 개의 함수를 가지는 MyFunction 클래스 구현
class MyFunction
{
public:
	const int x, y;

	MyFunction(int _x, int _y) :
		x(_x), y(_y)
	{
	}

	MyValue addition() const
	{
		return MyValue(x + y);
	}

	MyValue subtraction() const
	{
		return MyValue(x - y);
	}

	MyValue multiplication() const
	{
		return MyValue(x * y);
	}

	MyValue division() const
	{
		return MyValue(x / y);
	}
};

auto main() -> int
{
	cout << "[first_class_pure_immutable.cpp]" << endl;

	// 두 개의 변수 초기화.
	// 이 변수들은 MyFunction 클래스의 생성자에 사용된다.
	int a = 100;
	int b = 10;

	// 두 변수의 값을 출력.
	cout << "Initial value" << endl;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << endl;

	// MyFunction 클래스 인스턴스를 생성한다.
	MyFunction func(a, b);

	// MyFunction 클래스의 각 멤버 함수에 대한 래퍼를 만든다.
	// 이 래퍼 함수는 이제 일급 함수다.
	auto callableAdd = mem_fn(&MyFunction::addition);
	auto callableSub = mem_fn(&MyFunction::subtraction);
	auto callableMul = mem_fn(&MyFunction::multiplication);
	auto callableDiv = mem_fn(&MyFunction::division);

	// 함수 호출
	auto value1 = callableAdd(func);
	auto value2 = callableSub(func);
	auto value3 = callableMul(func);
	auto value4 = callableDiv(func);

	// 결과 출력
	cout << "The result" << endl;
	cout << "addition = " << value1.value << endl;
	cout << "subtraction = " << value2.value << endl;
	cout << "multiplication = " << value3.value << endl;
	cout << "division = " << value4.value << endl;

	return 0;
}
