/* curry_1.cpp */
#include <functional>
#include <iostream>

using namespace std;

// 커링에 필요한 가변 템플릿
template<typename Func, typename... Args>
auto curry(Func func, Args... args)
{
	return [=](auto... lastParam)
	{
		return func(args..., lastParam...);
	};
}

int areaOfRectangle(int length, int width)
{
	return length * width;
}

auto main() -> int
{
	cout << "[curry_1.cpp]" << endl;

	// areaOfRectangle() 함수를 커링하여 length5 생성.
	auto length5 = curry(areaOfRectangle, 5);

	// length5 호출
	cout << "Curried with spesific length = 5" << endl;
	for (int i = 0; i <= 5; ++i)
	{
		cout << "length5(" << i << ") = ";
		cout << length5(i) << endl;
	}

	return 0;
}
