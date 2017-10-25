/* curry_2.cpp */
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

int volumeOfRectanglular(
	int length,
	int width,
	int height)
{
	return length * width * height;
}

auto main() -> int
{
	cout << "[curry_2.cpp]" << endl;

	// volumeOfRectanglular() 함수를 커링하여 length5width4 생성.
	auto length5width4 = curry(volumeOfRectanglular, 5, 4);

	// length5width4 호출
	cout << "Curried with spesific data:" << endl;
	cout << "length = 5, width 4" << endl;
	for (int i = 0; i <= 5; ++i)
	{
		cout << "length5width4(" << i << ") = ";
		cout << length5width4(i) << endl;
	}

	return 0;
}
